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
#include <QDragEnterEvent>
#include <QRegularExpressionValidator>
#include <QList>
#include <QMimeData>
#include <QProcess>
#include <QHostInfo>

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
    void fillListWidget();

protected:
    bool eventFilter(QObject* object, QEvent* event);

private slots:
    void on_buttonBrowse_clicked();

    void on_buttonSubmit_clicked();

    void on_buttonHostName_clicked();

private:
    Ui::MainWindow *ui;
    SettingsForm* s;
    QString _startDir;
    QString _defectDir;
    QString _discDir;
    QString _overDir;
    QStringList _photos;
    MkdirPolicy _policy;
    bool _isCopyMode;

    double _fileSize;
};
#endif // MAINWINDOW_H
