#include "settingsform.h"
#include "ui_settingsform.h"

SettingsForm::SettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);

    this->setModal(true);

    QFile file("config.json");
    file.open(QIODevice::ReadOnly);
    QJsonObject jObject;
    jObject = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    ui->editStartDirection->setText(jObject["startDir"].toString());
    ui->editDefectDirection->setText(jObject["defectDir"].toString());
    ui->editDiscrepancyDirection->setText(jObject["discrepancyDir"].toString());
    ui->editOverageDirection->setText(jObject["overageDir"].toString());

    connect(ui->buttonSave, &QPushButton::clicked, [this](){
        QJsonObject jObject;
        jObject["startDir"]         = ui->editStartDirection->text();
        jObject["defectDir"]        = ui->editDefectDirection->text();
        jObject["discrepancyDir"]   = ui->editDiscrepancyDirection->text();
        jObject["overageDir"]       = ui->editOverageDirection->text();

        QJsonDocument json(jObject);
        QFile file("config.json");
        file.open(QIODevice::WriteOnly);
        file.write(json.toJson());
        file.close();

        QMessageBox::information(this, "Внесение изменений", "Перезапустите программу, чтобы изменения вступили в силу");

        delete this;
    });
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::on_buttonStart_clicked()
{
    ui->editStartDirection->setText(QFileDialog::getExistingDirectory(this, "Выбор начальной директории"));
}


void SettingsForm::on_buttonDefect_clicked()
{
    ui->editDefectDirection->setText(QFileDialog::getExistingDirectory(this, "Выбор директории брака"));
}


void SettingsForm::on_buttonDisc_clicked()
{
    ui->editDiscrepancyDirection->setText(QFileDialog::getExistingDirectory(this, "Выбор директории несоответствия"));
}


void SettingsForm::on_buttonOver_clicked()
{
    ui->editOverageDirection->setText(QFileDialog::getExistingDirectory(this, "Выбор директории излишек"));

}

