#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* buttonSettings = new QPushButton(this);
    buttonSettings->setGeometry(this->width() - 16, 0, 16, 16);

    this->setFixedSize(this->size());

    s = nullptr;
    fileSize = 0;

    ui->editName->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9а-яА-Я][a-zA-Z0-9а-яА-Я ]{0,50}")));

    QFile config("config.json");
    if (config.open(QIODevice::ReadOnly))
    {
        QJsonObject jObject = QJsonDocument::fromJson(config.readAll()).object();
        startDir = jObject["startDir"].toString();
        defectDir = jObject["defectDir"].toString();
        discDir = jObject["discrepancyDir"].toString();
        overDir = jObject["overageDir"].toString();
        policy = (MkdirPolicy)jObject["mkdirPolicy"].toInteger();
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

    connect(buttonSettings, &QPushButton::clicked, [this](){
        if (s)
        {
            delete s;
            s = nullptr;
        }
        SettingsForm* s = new SettingsForm(this);
        s->show();
    });

    updateDataOut();
}

MainWindow::~MainWindow()
{
    delete ui->editName->validator();
    delete ui;
}

void MainWindow::updateDataOut()
{
    QString data = "Загруженные фотографии:\n";

    for (auto & iter : photos)
        data.append('\t' + iter + '\n');

    data.append("Количество загруженных фотографий: " + QVariant(photos.size()).toString() + '\n');

    data.append("Размер загруженных фото: " + QVariant(fileSize).toString() + " KB\n");

    data.append("Имя новой директории: " + ui->editName->text() + '\n');

    data.append("Тип новой директории: ");

    for (auto & iter : ui->groupBox->findChildren<QRadioButton*>())
        if (iter->isChecked())
            data.append(iter->text());

    ui->labelDataOut->setText(data);
}


void MainWindow::on_buttonBrowse_clicked()
{
    photos = QFileDialog::getOpenFileNames(this, "Выбор фотокарточек", startDir, "*.png; *.jpg; *.jpeg");

    qDebug() << photos;

    fileSize = 0;

    ui->listWidget->clear();

    ui->listWidget->addItems(photos);

    for (auto & iter : photos)
    {
        QFileInfo info(iter);
        fileSize += info.size();
    }

    if (fileSize > (1024))
        fileSize /= (1024);

    updateDataOut();

    /*for (int i = 0; i < photos.size(); i++)
    {
        QLabel* photo = new QLabel(ui->scrollAreaWidgetContents);
        photo->setPixmap(photos.at(i));
        photo->setGeometry(photo->pixmap().rect());
        photo->show();
    }*/
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
            file.copy(dir.path() + "/" + finfo.fileName());
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

