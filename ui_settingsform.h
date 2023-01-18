/********************************************************************************
** Form generated from reading UI file 'settingsform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFORM_H
#define UI_SETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editStartDirection;
    QToolButton *buttonStart;
    QLabel *label_2;
    QLineEdit *editDefectDirection;
    QToolButton *buttonDefect;
    QLabel *label_3;
    QLineEdit *editDiscrepancyDirection;
    QToolButton *buttonDisc;
    QLabel *label_4;
    QLineEdit *editOverageDirection;
    QToolButton *buttonOver;
    QPushButton *buttonSave;

    void setupUi(QDialog *SettingsForm)
    {
        if (SettingsForm->objectName().isEmpty())
            SettingsForm->setObjectName(QString::fromUtf8("SettingsForm"));
        SettingsForm->resize(269, 263);
        gridLayout = new QGridLayout(SettingsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SettingsForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        editStartDirection = new QLineEdit(SettingsForm);
        editStartDirection->setObjectName(QString::fromUtf8("editStartDirection"));

        gridLayout->addWidget(editStartDirection, 1, 0, 1, 1);

        buttonStart = new QToolButton(SettingsForm);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        gridLayout->addWidget(buttonStart, 1, 1, 1, 1);

        label_2 = new QLabel(SettingsForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        editDefectDirection = new QLineEdit(SettingsForm);
        editDefectDirection->setObjectName(QString::fromUtf8("editDefectDirection"));

        gridLayout->addWidget(editDefectDirection, 3, 0, 1, 1);

        buttonDefect = new QToolButton(SettingsForm);
        buttonDefect->setObjectName(QString::fromUtf8("buttonDefect"));

        gridLayout->addWidget(buttonDefect, 3, 1, 1, 1);

        label_3 = new QLabel(SettingsForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 2);

        editDiscrepancyDirection = new QLineEdit(SettingsForm);
        editDiscrepancyDirection->setObjectName(QString::fromUtf8("editDiscrepancyDirection"));

        gridLayout->addWidget(editDiscrepancyDirection, 5, 0, 1, 1);

        buttonDisc = new QToolButton(SettingsForm);
        buttonDisc->setObjectName(QString::fromUtf8("buttonDisc"));

        gridLayout->addWidget(buttonDisc, 5, 1, 1, 1);

        label_4 = new QLabel(SettingsForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        editOverageDirection = new QLineEdit(SettingsForm);
        editOverageDirection->setObjectName(QString::fromUtf8("editOverageDirection"));

        gridLayout->addWidget(editOverageDirection, 7, 0, 1, 1);

        buttonOver = new QToolButton(SettingsForm);
        buttonOver->setObjectName(QString::fromUtf8("buttonOver"));

        gridLayout->addWidget(buttonOver, 7, 1, 1, 1);

        buttonSave = new QPushButton(SettingsForm);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));

        gridLayout->addWidget(buttonSave, 8, 0, 1, 2);


        retranslateUi(SettingsForm);

        QMetaObject::connectSlotsByName(SettingsForm);
    } // setupUi

    void retranslateUi(QDialog *SettingsForm)
    {
        SettingsForm->setWindowTitle(QCoreApplication::translate("SettingsForm", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270", nullptr));
        label->setText(QCoreApplication::translate("SettingsForm", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217", nullptr));
        buttonStart->setText(QCoreApplication::translate("SettingsForm", "...", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsForm", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217 \320\261\321\200\320\260\320\272\320\260", nullptr));
        buttonDefect->setText(QCoreApplication::translate("SettingsForm", "...", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsForm", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217 \320\275\320\265\321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\271", nullptr));
        buttonDisc->setText(QCoreApplication::translate("SettingsForm", "...", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsForm", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217 \320\270\320\267\320\273\320\270\321\210\320\265\320\272", nullptr));
        buttonOver->setText(QCoreApplication::translate("SettingsForm", "...", nullptr));
        buttonSave->setText(QCoreApplication::translate("SettingsForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsForm: public Ui_SettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFORM_H
