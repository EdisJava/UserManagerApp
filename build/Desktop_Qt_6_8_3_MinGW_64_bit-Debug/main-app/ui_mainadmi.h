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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainAdmi
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnEmpresas;
    QPushButton *btnDepartamentos;
    QPushButton *btnUsuarios;

    void setupUi(QMainWindow *MainAdmi)
    {
        if (MainAdmi->objectName().isEmpty())
            MainAdmi->setObjectName("MainAdmi");
        MainAdmi->resize(400, 300);
        centralwidget = new QWidget(MainAdmi);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        btnEmpresas = new QPushButton(centralwidget);
        btnEmpresas->setObjectName("btnEmpresas");

        verticalLayout->addWidget(btnEmpresas);

        btnDepartamentos = new QPushButton(centralwidget);
        btnDepartamentos->setObjectName("btnDepartamentos");

        verticalLayout->addWidget(btnDepartamentos);

        btnUsuarios = new QPushButton(centralwidget);
        btnUsuarios->setObjectName("btnUsuarios");

        verticalLayout->addWidget(btnUsuarios);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        MainAdmi->setCentralWidget(centralwidget);

        retranslateUi(MainAdmi);

        QMetaObject::connectSlotsByName(MainAdmi);
    } // setupUi

    void retranslateUi(QMainWindow *MainAdmi)
    {
        MainAdmi->setWindowTitle(QCoreApplication::translate("MainAdmi", "Administrador General", nullptr));
        btnEmpresas->setText(QCoreApplication::translate("MainAdmi", "Gestionar Empresas", nullptr));
        btnDepartamentos->setText(QCoreApplication::translate("MainAdmi", "Gestionar Departamentos", nullptr));
        btnUsuarios->setText(QCoreApplication::translate("MainAdmi", "Gestionar Usuarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainAdmi: public Ui_MainAdmi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMI_H
