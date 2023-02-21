/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QToolButton *buttonBrowse;
    QListWidget *listWidget;
    QLineEdit *editPhotoPath;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *editName;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonDefect;
    QRadioButton *radioButtonDiscrepancy;
    QRadioButton *radioButtonOverage;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonTimetable;
    QPushButton *buttonSettings;
    QPushButton *buttonSubmit;
    QTextBrowser *textBrowserDataOut;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(499, 302);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBrowse = new QToolButton(centralwidget);
        buttonBrowse->setObjectName(QString::fromUtf8("buttonBrowse"));

        gridLayout->addWidget(buttonBrowse, 0, 1, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(listWidget, 1, 0, 1, 2);

        editPhotoPath = new QLineEdit(centralwidget);
        editPhotoPath->setObjectName(QString::fromUtf8("editPhotoPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editPhotoPath->sizePolicy().hasHeightForWidth());
        editPhotoPath->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(editPhotoPath, 0, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        editName = new QLineEdit(centralwidget);
        editName->setObjectName(QString::fromUtf8("editName"));
        sizePolicy1.setHeightForWidth(editName->sizePolicy().hasHeightForWidth());
        editName->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(editName);


        verticalLayout_5->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonDefect = new QRadioButton(groupBox);
        radioButtonDefect->setObjectName(QString::fromUtf8("radioButtonDefect"));
        radioButtonDefect->setChecked(true);

        verticalLayout_2->addWidget(radioButtonDefect);

        radioButtonDiscrepancy = new QRadioButton(groupBox);
        radioButtonDiscrepancy->setObjectName(QString::fromUtf8("radioButtonDiscrepancy"));

        verticalLayout_2->addWidget(radioButtonDiscrepancy);

        radioButtonOverage = new QRadioButton(groupBox);
        radioButtonOverage->setObjectName(QString::fromUtf8("radioButtonOverage"));

        verticalLayout_2->addWidget(radioButtonOverage);


        verticalLayout_4->addWidget(groupBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonTimetable = new QPushButton(centralwidget);
        buttonTimetable->setObjectName(QString::fromUtf8("buttonTimetable"));

        horizontalLayout_2->addWidget(buttonTimetable);

        buttonSettings = new QPushButton(centralwidget);
        buttonSettings->setObjectName(QString::fromUtf8("buttonSettings"));

        horizontalLayout_2->addWidget(buttonSettings);

        buttonSubmit = new QPushButton(centralwidget);
        buttonSubmit->setObjectName(QString::fromUtf8("buttonSubmit"));

        horizontalLayout_2->addWidget(buttonSubmit);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        textBrowserDataOut = new QTextBrowser(centralwidget);
        textBrowserDataOut->setObjectName(QString::fromUtf8("textBrowserDataOut"));

        gridLayout_2->addWidget(textBrowserDataOut, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WBHelper", nullptr));
        buttonBrowse->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        editPhotoPath->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\202\320\260\321\211\320\270\321\202\320\265 \321\201\321\216\320\264\320\260 \321\204\320\276\321\202\320\276\320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        radioButtonDefect->setText(QCoreApplication::translate("MainWindow", "\320\221\321\200\320\260\320\272", nullptr));
        radioButtonDiscrepancy->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\265", nullptr));
        radioButtonOverage->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\273\320\270\321\210\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\321\217", nullptr));
        buttonTimetable->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        buttonSettings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        buttonSubmit->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
