#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include "mkdirPolicy.h"

#include <QDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();

private slots:
    void on_buttonStart_clicked();

    void on_buttonDefect_clicked();

    void on_buttonDisc_clicked();

    void on_buttonOver_clicked();

private:
    Ui::SettingsForm *ui;
};

#endif // SETTINGSFORM_H
