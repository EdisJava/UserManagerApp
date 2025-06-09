/********************************************************************************
** Form generated from reading UI file 'admicompany.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMICOMPANY_H
#define UI_ADMICOMPANY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdmiCompany
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QPushButton *btnGestionDepartamentos;
    QPushButton *btnGestionUsuarios;

    void setupUi(QWidget *AdmiCompany)
    {
        if (AdmiCompany->objectName().isEmpty())
            AdmiCompany->setObjectName("AdmiCompany");
        AdmiCompany->resize(350, 250);
        verticalLayout = new QVBoxLayout(AdmiCompany);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(AdmiCompany);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTitle->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelTitle->setFont(font);

        verticalLayout->addWidget(labelTitle);

        btnGestionDepartamentos = new QPushButton(AdmiCompany);
        btnGestionDepartamentos->setObjectName("btnGestionDepartamentos");

        verticalLayout->addWidget(btnGestionDepartamentos);

        btnGestionUsuarios = new QPushButton(AdmiCompany);
        btnGestionUsuarios->setObjectName("btnGestionUsuarios");

        verticalLayout->addWidget(btnGestionUsuarios);


        retranslateUi(AdmiCompany);

        QMetaObject::connectSlotsByName(AdmiCompany);
    } // setupUi

    void retranslateUi(QWidget *AdmiCompany)
    {
        AdmiCompany->setWindowTitle(QCoreApplication::translate("AdmiCompany", "Administraci\303\263n Empresa", nullptr));
        labelTitle->setText(QCoreApplication::translate("AdmiCompany", "Panel de Administrador Empresa", nullptr));
        btnGestionDepartamentos->setText(QCoreApplication::translate("AdmiCompany", "Gestionar Departamentos", nullptr));
        btnGestionUsuarios->setText(QCoreApplication::translate("AdmiCompany", "Gestionar Usuarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdmiCompany: public Ui_AdmiCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMICOMPANY_H
