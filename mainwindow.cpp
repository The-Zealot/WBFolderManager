#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    s = nullptr;
    _fileSize = 0;

    ui->editName->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9а-яА-Я][a-zA-Z0-9а-яА-Я ]{0,50}")));

    QFile config("config.json");
    if (config.open(QIODevice::ReadOnly))
    {
        QJsonObject jObject = QJsonDocument::fromJson(config.readAll()).object();

        _startDir        = jObject["startDir"].toString();
        _defectDir       = jObject["defectDir"].toString();
        _discDir         = jObject["discrepancyDir"].toString();
        _overDir         = jObject["overageDir"].toString();
        _policy          = (MkdirPolicy)jObject["mkdirPolicy"].toInteger();
        _isCopyMode      = jObject["copyMovePhoto"].toBool();

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
        _photos.removeAt(ui->listWidget->currentRow());
        fillListWidget();
        updateDataOut();

    });
    connect(ui->buttonSettings, &QPushButton::clicked, [this](){
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

    if (_fileSize >= (1024 * 1024))
    {
        _fileSize /= (1024 * 1024);
        postfixFileSize = " MB";
    }
    if (_fileSize >= 1024)
    {
        _fileSize /= 1024;
        postfixFileSize = " KB";
    }

    int temp = _fileSize * 100;
    _fileSize = temp;
    _fileSize /= 100;

    qDebug() << temp << _fileSize;

    QString data = "Отладочная информация\nЗагруженные фотографии:\n";

    for (auto & iter : _photos)
        data.append(iter + '\n');

    data.append("Количество загруженных фотографий: " + QVariant(_photos.size()).toString() + '\n');

    data.append("Размер загруженных фото: " + QVariant(_fileSize).toString() + postfixFileSize + '\n');

    data.append("Имя новой директории: " + ui->editName->text() + '\n');

    data.append("Тип новой директории: ");

    for (auto & iter : ui->groupBox->findChildren<QRadioButton*>())
        if (iter->isChecked())
            data.append(iter->text());

    ui->textBrowserDataOut->setText(data);

    qDebug() << "updateDataOut() was called";
}

void MainWindow::fillListWidget()
{
    _fileSize = 0;

    ui->listWidget->clear();

    ui->listWidget->addItems(_photos);

    for (auto & iter : _photos)
    {
        QFileInfo info(iter);
        _fileSize += info.size();
    }
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
            _photos.append(iter.toLocalFile());
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
    _photos = QFileDialog::getOpenFileNames(this, "Выбор фотокарточек", _startDir, "*.png; *.jpg; *.jpeg");

    qDebug() << _photos;

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
        filePath = _defectDir;
    if (ui->radioButtonDiscrepancy->isChecked())
        filePath = _discDir;
    if (ui->radioButtonOverage->isChecked())
        filePath = _overDir;

    QDir dir(filePath + "/" + dirPrefix + " " + ui->editName->text());


    switch(_policy)
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

    for (auto & iter : _photos)
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
            if (_isCopyMode)
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

        if (!_isCopyMode)
        {
            _photos.clear();
            updateDataOut();
        }
    }



    QMessageBox::information(this, "Успешный успех!", "Директория успешно создана. Файлы успешно скопированы. "
"Путь к директории помещен в буфер обмена");
}


void MainWindow::on_buttonHostName_clicked()
{
    QString name    = QHostInfo::localHostName();
    QString ip      = QHostInfo::fromName(name).addresses().last().toString();

    QString text = QString( "Имя компьютера в сети:  %1\n"
                            "IPv4 компьютера в сети:  %2\n")
                            .arg(name)
                            .arg(ip);
    QMessageBox::information(this, "Данные сети компьютера", text);
}

