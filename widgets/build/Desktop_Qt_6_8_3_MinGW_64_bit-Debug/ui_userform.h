/********************************************************************************
** Form generated from reading UI file 'userform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFORM_H
#define UI_USERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsuarioForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNombre;
    QLineEdit *txtNombre;
    QLabel *labelDni;
    QLineEdit *txtDni;
    QLabel *labelTelefono;
    QLineEdit *txtTelefono;
    QLabel *labelEmail;
    QLineEdit *txtEmail;
    QHBoxLayout *buttonLayout;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QWidget *UsuarioForm)
    {
        if (UsuarioForm->objectName().isEmpty())
            UsuarioForm->setObjectName("UsuarioForm");
        UsuarioForm->resize(350, 220);
        verticalLayout = new QVBoxLayout(UsuarioForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelNombre = new QLabel(UsuarioForm);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombre);

        txtNombre = new QLineEdit(UsuarioForm);
        txtNombre->setObjectName("txtNombre");

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);

        labelDni = new QLabel(UsuarioForm);
        labelDni->setObjectName("labelDni");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDni);

        txtDni = new QLineEdit(UsuarioForm);
        txtDni->setObjectName("txtDni");

        formLayout->setWidget(1, QFormLayout::FieldRole, txtDni);

        labelTelefono = new QLabel(UsuarioForm);
        labelTelefono->setObjectName("labelTelefono");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTelefono);

        txtTelefono = new QLineEdit(UsuarioForm);
        txtTelefono->setObjectName("txtTelefono");

        formLayout->setWidget(2, QFormLayout::FieldRole, txtTelefono);

        labelEmail = new QLabel(UsuarioForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelEmail);

        txtEmail = new QLineEdit(UsuarioForm);
        txtEmail->setObjectName("txtEmail");

        formLayout->setWidget(3, QFormLayout::FieldRole, txtEmail);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnGuardar = new QPushButton(UsuarioForm);
        btnGuardar->setObjectName("btnGuardar");

        buttonLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(UsuarioForm);
        btnCancelar->setObjectName("btnCancelar");

        buttonLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(UsuarioForm);

        QMetaObject::connectSlotsByName(UsuarioForm);
    } // setupUi

    void retranslateUi(QWidget *UsuarioForm)
    {
        UsuarioForm->setWindowTitle(QCoreApplication::translate("UsuarioForm", "Formulario Usuario", nullptr));
        labelNombre->setText(QCoreApplication::translate("UsuarioForm", "Nombre:", nullptr));
        labelDni->setText(QCoreApplication::translate("UsuarioForm", "DNI:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("UsuarioForm", "Tel\303\251fono:", nullptr));
        labelEmail->setText(QCoreApplication::translate("UsuarioForm", "Email:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("UsuarioForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("UsuarioForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsuarioForm: public Ui_UsuarioForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
