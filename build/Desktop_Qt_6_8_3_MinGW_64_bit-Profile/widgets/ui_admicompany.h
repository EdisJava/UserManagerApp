/********************************************************************************
** Form generated from reading UI file 'admicompany.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMICOMPANY_H
#define UI_ADMICOMPANY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdmiCompany
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitulo;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEmpresa;
    QPushButton *btnDepartamentos;
    QPushButton *btnUsuarios;

    void setupUi(QWidget *AdmiCompany)
    {
        if (AdmiCompany->objectName().isEmpty())
            AdmiCompany->setObjectName("AdmiCompany");
        AdmiCompany->resize(315, 66);
        verticalLayout = new QVBoxLayout(AdmiCompany);
        verticalLayout->setObjectName("verticalLayout");
        labelTitulo = new QLabel(AdmiCompany);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitulo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnEmpresa = new QPushButton(AdmiCompany);
        btnEmpresa->setObjectName("btnEmpresa");

        horizontalLayout->addWidget(btnEmpresa);

        btnDepartamentos = new QPushButton(AdmiCompany);
        btnDepartamentos->setObjectName("btnDepartamentos");

        horizontalLayout->addWidget(btnDepartamentos);

        btnUsuarios = new QPushButton(AdmiCompany);
        btnUsuarios->setObjectName("btnUsuarios");

        horizontalLayout->addWidget(btnUsuarios);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdmiCompany);

        QMetaObject::connectSlotsByName(AdmiCompany);
    } // setupUi

    void retranslateUi(QWidget *AdmiCompany)
    {
        AdmiCompany->setWindowTitle(QCoreApplication::translate("AdmiCompany", "Panel Empresa", nullptr));
        labelTitulo->setText(QCoreApplication::translate("AdmiCompany", "Administraci\303\263n de Empresa", nullptr));
        btnEmpresa->setText(QCoreApplication::translate("AdmiCompany", "Datos de la Empresa", nullptr));
        btnDepartamentos->setText(QCoreApplication::translate("AdmiCompany", "Departamentos", nullptr));
        btnUsuarios->setText(QCoreApplication::translate("AdmiCompany", "Usuarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdmiCompany: public Ui_AdmiCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMICOMPANY_H
