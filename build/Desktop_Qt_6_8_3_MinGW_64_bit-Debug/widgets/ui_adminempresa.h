/********************************************************************************
** Form generated from reading UI file 'adminempresa.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINEMPRESA_H
#define UI_ADMINEMPRESA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminEmpresa
{
public:

    void setupUi(QWidget *AdminEmpresa)
    {
        if (AdminEmpresa->objectName().isEmpty())
            AdminEmpresa->setObjectName("AdminEmpresa");
        AdminEmpresa->resize(400, 300);

        retranslateUi(AdminEmpresa);

        QMetaObject::connectSlotsByName(AdminEmpresa);
    } // setupUi

    void retranslateUi(QWidget *AdminEmpresa)
    {
        AdminEmpresa->setWindowTitle(QCoreApplication::translate("AdminEmpresa", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminEmpresa: public Ui_AdminEmpresa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINEMPRESA_H
