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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editPhotoPath;
    QToolButton *buttonBrowse;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *editName;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonDefect;
    QRadioButton *radioButtonDiscrepancy;
    QRadioButton *radioButtonOverage;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *buttonSubmit;
    QSpacerItem *horizontalSpacer;
    QLabel *labelDataOut;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(676, 334);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editPhotoPath = new QLineEdit(centralwidget);
        editPhotoPath->setObjectName(QString::fromUtf8("editPhotoPath"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editPhotoPath->sizePolicy().hasHeightForWidth());
        editPhotoPath->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(editPhotoPath);

        buttonBrowse = new QToolButton(centralwidget);
        buttonBrowse->setObjectName(QString::fromUtf8("buttonBrowse"));

        horizontalLayout->addWidget(buttonBrowse);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(listWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        editName = new QLineEdit(centralwidget);
        editName->setObjectName(QString::fromUtf8("editName"));
        sizePolicy.setHeightForWidth(editName->sizePolicy().hasHeightForWidth());
        editName->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(editName);


        verticalLayout_4->addLayout(verticalLayout_3);

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


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonSubmit = new QPushButton(groupBox_2);
        buttonSubmit->setObjectName(QString::fromUtf8("buttonSubmit"));

        gridLayout_2->addWidget(buttonSubmit, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        labelDataOut = new QLabel(groupBox_2);
        labelDataOut->setObjectName(QString::fromUtf8("labelDataOut"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelDataOut->sizePolicy().hasHeightForWidth());
        labelDataOut->setSizePolicy(sizePolicy3);
        labelDataOut->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelDataOut->setWordWrap(true);

        gridLayout_2->addWidget(labelDataOut, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WBHelper", nullptr));
        editPhotoPath->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\202\320\260\321\211\320\270\321\202\320\265 \321\201\321\216\320\264\320\260 \321\204\320\276\321\202\320\276\320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", nullptr));
        buttonBrowse->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        radioButtonDefect->setText(QCoreApplication::translate("MainWindow", "\320\221\321\200\320\260\320\272", nullptr));
        radioButtonDiscrepancy->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\265", nullptr));
        radioButtonOverage->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\273\320\270\321\210\320\272\320\270", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        buttonSubmit->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        labelDataOut->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
