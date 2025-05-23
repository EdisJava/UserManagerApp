/********************************************************************************
** Form generated from reading UI file 'mainadmi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINADMI_H
#define UI_MAINADMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainAdmi
{
public:

    void setupUi(QWidget *MainAdmi)
    {
        if (MainAdmi->objectName().isEmpty())
            MainAdmi->setObjectName("MainAdmi");
        MainAdmi->resize(400, 300);

        retranslateUi(MainAdmi);

        QMetaObject::connectSlotsByName(MainAdmi);
    } // setupUi

    void retranslateUi(QWidget *MainAdmi)
    {
        MainAdmi->setWindowTitle(QCoreApplication::translate("MainAdmi", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainAdmi: public Ui_MainAdmi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMI_H
