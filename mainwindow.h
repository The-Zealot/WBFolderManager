#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingsform.h"
#include "MkdirPolicy.h"

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateDataOut();

private slots:
    void on_buttonBrowse_clicked();

    void on_buttonSubmit_clicked();

private:
    Ui::MainWindow *ui;
    SettingsForm* s;
    QString startDir;
    QString defectDir;
    QString discDir;
    QString overDir;
    QStringList photos;
    MkdirPolicy policy;

    int fileSize;
};
#endif // MAINWINDOW_H
