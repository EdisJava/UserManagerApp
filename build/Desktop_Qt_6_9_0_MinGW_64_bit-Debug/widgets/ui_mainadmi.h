/********************************************************************************
** Form generated from reading UI file 'mainadmi.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINADMI_H
#define UI_MAINADMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainAdmi
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QPushButton *btnGestionDepartamentos;
    QPushButton *btnGestionEmpresas;
    QPushButton *btnGestionUsuarios;

    void setupUi(QWidget *MainAdmi)
    {
        if (MainAdmi->objectName().isEmpty())
            MainAdmi->setObjectName("MainAdmi");
        MainAdmi->resize(400, 300);
        verticalLayout = new QVBoxLayout(MainAdmi);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(MainAdmi);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        btnGestionDepartamentos = new QPushButton(MainAdmi);
        btnGestionDepartamentos->setObjectName("btnGestionDepartamentos");

        verticalLayout->addWidget(btnGestionDepartamentos);

        btnGestionEmpresas = new QPushButton(MainAdmi);
        btnGestionEmpresas->setObjectName("btnGestionEmpresas");

        verticalLayout->addWidget(btnGestionEmpresas);

        btnGestionUsuarios = new QPushButton(MainAdmi);
        btnGestionUsuarios->setObjectName("btnGestionUsuarios");

        verticalLayout->addWidget(btnGestionUsuarios);


        retranslateUi(MainAdmi);

        QMetaObject::connectSlotsByName(MainAdmi);
    } // setupUi

    void retranslateUi(QWidget *MainAdmi)
    {
        MainAdmi->setWindowTitle(QCoreApplication::translate("MainAdmi", "Panel Administrativo", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainAdmi", "Panel de Administrador Total", nullptr));
        btnGestionDepartamentos->setText(QCoreApplication::translate("MainAdmi", "Gestionar Departamentos", nullptr));
        btnGestionEmpresas->setText(QCoreApplication::translate("MainAdmi", "Gestionar Empresas", nullptr));
        btnGestionUsuarios->setText(QCoreApplication::translate("MainAdmi", "Gestionar Usuarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainAdmi: public Ui_MainAdmi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMI_H
