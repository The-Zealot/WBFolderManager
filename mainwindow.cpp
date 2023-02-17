#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int BUTTON_SIZE = 16;
    QPushButton* buttonSettings = new QPushButton(this);
    buttonSettings->setGeometry(this->width() - BUTTON_SIZE, 0, BUTTON_SIZE, BUTTON_SIZE);
    buttonSettings->show();

    this->setFixedSize(this->size());

    s = nullptr;
    fileSize = 0;

    ui->editName->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9а-яА-Я][a-zA-Z0-9а-яА-Я ]{0,50}")));

    QFile config("config.json");
    if (config.open(QIODevice::ReadOnly))
    {
        QJsonObject jObject = QJsonDocument::fromJson(config.readAll()).object();

        startDir        = jObject["startDir"].toString();
        defectDir       = jObject["defectDir"].toString();
        discDir         = jObject["discrepancyDir"].toString();
        overDir         = jObject["overageDir"].toString();
        policy          = (MkdirPolicy)jObject["mkdirPolicy"].toInteger();
        copyMovePhoto   = jObject["copyMovePhoto"].toBool();

        config.close();
    }
    else
    {
        QMessageBox::warning(this, "Упс, что-то случилось", "Файл конфигурации не был открыт. Настройки не загружены.");
    }

    connect(ui->radioButtonDefect, &QRadioButton::clicked, [this](){ updateDataOut(); });
    connect(ui->radioButtonDiscrepancy, &QRadioButton::clicked, [this](){ updateDataOut(); });
    connect(ui->radioButtonOverage, &QRadioButton::clicked, [this](){ updateDataOut(); });
    connect(ui->editName, &QLineEdit::textEdited, [this](){ updateDataOut(); });

    connect(ui->listWidget, &QListWidget::itemDoubleClicked, [this](){
        photos.removeAt(ui->listWidget->currentRow());
        fillListWidget();
        updateDataOut();

    });
    connect(buttonSettings, &QPushButton::clicked, [this](){
        if (s)
        {
            delete s;
            s = nullptr;
        }
        SettingsForm* s = new SettingsForm(this);
        s->show();
    });

    ui->editPhotoPath->installEventFilter(this);
    ui->editPhotoPath->setAcceptDrops(true);
    ui->editPhotoPath->setReadOnly(true);

    updateDataOut();
}

MainWindow::~MainWindow()
{
    delete ui->editName->validator();
    delete ui;
}

void MainWindow::updateDataOut()
{
    QString postfixFileSize = " B";

    if (fileSize >= (1024 * 1024))
    {
        fileSize /= (1024 * 1024);
        postfixFileSize = " MB";
    }
    if (fileSize >= 1024)
    {
        fileSize /= 1024;
        postfixFileSize = " KB";
    }

    int temp = fileSize * 100;
    fileSize = temp;
    fileSize /= 100;

    qDebug() << temp << fileSize;

    QString data = "Загруженные фотографии:\n";

    for (auto & iter : photos)
        data.append('\t' + iter + '\n');

    data.append("Количество загруженных фотографий: " + QVariant(photos.size()).toString() + '\n');

    data.append("Размер загруженных фото: " + QVariant(fileSize).toString() + postfixFileSize + '\n');

    data.append("Имя новой директории: " + ui->editName->text() + '\n');

    data.append("Тип новой директории: ");

    for (auto & iter : ui->groupBox->findChildren<QRadioButton*>())
        if (iter->isChecked())
            data.append(iter->text());

    ui->labelDataOut->setText(data);

    qDebug() << "updateDataOut() was called";
}

void MainWindow::fillListWidget()
{
    fileSize = 0;

    ui->listWidget->clear();

    ui->listWidget->addItems(photos);

    for (auto & iter : photos)
    {
        QFileInfo info(iter);
        fileSize += info.size();
    }

//    if (fileSize > (1024))
//        fileSize /= (1024);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::DragEnter)
    {
        QDragEnterEvent* dee = dynamic_cast<QDragEnterEvent*>(event);
        dee->acceptProposedAction();
        return true;
    }
    if (event->type() == QEvent::Drop)
    {
        QDropEvent* de = dynamic_cast<QDropEvent*>(event);
        QList<QUrl> files = de->mimeData()->urls();

        for (auto iter : files)
        {
            photos.append(iter.toLocalFile());
        }

        if (files.isEmpty())
            return true;

        fillListWidget();

        updateDataOut();

        return true;
    }

    return QMainWindow::eventFilter(object, event);
}


void MainWindow::on_buttonBrowse_clicked()
{
    photos = QFileDialog::getOpenFileNames(this, "Выбор фотокарточек", startDir, "*.png; *.jpg; *.jpeg");

    qDebug() << photos;

    fillListWidget();

    updateDataOut();
}


void MainWindow::on_buttonSubmit_clicked()
{
    if (ui->editName->text().isEmpty())
    {
        QMessageBox::warning(this, "Упс, что-то случилось", "Название директории не может быть пустым");
        return;
    }

    QString dirPrefix;

    for (auto & iter : ui->groupBox->findChildren<QRadioButton*>())
        if (iter->isChecked())
            dirPrefix = iter->text().toLower();

    QString filePath;

    if (ui->radioButtonDefect->isChecked())
        filePath = defectDir;
    if (ui->radioButtonDiscrepancy->isChecked())
        filePath = discDir;
    if (ui->radioButtonOverage->isChecked())
        filePath = overDir;

    QDir dir(filePath + "/" + dirPrefix + " " + ui->editName->text());


    switch(policy)
    {
    case MkdirPolicy::Ignore:
        break;

    case MkdirPolicy::Ask:
        if (dir.exists())
            if (QMessageBox::warning(this, "Внимание!", "Данная директория уже существует. Хотите продолжить?",
                                     QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
                return;
        break;

    case MkdirPolicy::Block:
        if (dir.exists())
        {
            QMessageBox::critical(this, "Внимание!", "Данная директория уже существует!");
            return;
        }
        break;
    }

    for (auto & iter : photos)
    {
        QFile file(iter);
        if (file.open(QIODevice::ReadOnly))
        {
            QFileInfo finfo(iter);
            if (!dir.exists())
            {
                dir.mkdir(dir.path());
            }

            QString fileName = dir.path() + "/" + finfo.fileName();
            if (copyMovePhoto)
            {
                file.copy(fileName);
            }
            else
            {
                file.rename(fileName);
            }

            file.close();
            QApplication::clipboard()->setText(dir.path());
        }
        else
        {
            QMessageBox::critical(this, "Упс, что-то случилось", "Ошибка чтения файла");
        }
    }

    QMessageBox::information(this, "Успешный успех!", "Директория успешно создана. Файлы успешно скопированы. "
"Путь к директории помещен в буфер обмена");
}

