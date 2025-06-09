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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelDNI;
    QLineEdit *lineEditDni;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QLabel *labelTelefono;
    QLineEdit *lineEditTelefono;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelDepartamento;
    QComboBox *comboBoxDepartamento;
    QLabel *labelEmpresa;
    QComboBox *comboBoxEmpresa;
    QLabel *labelEstado;
    QComboBox *comboBoxEstado;
    QLabel *labelFoto;
    QLineEdit *lineEditFoto;
    QLabel *labelRol;
    QComboBox *comboBoxRol;
    QHBoxLayout *buttonLayout;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName("UserForm");
        verticalLayout = new QVBoxLayout(UserForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelDNI = new QLabel(UserForm);
        labelDNI->setObjectName("labelDNI");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDNI);

        lineEditDni = new QLineEdit(UserForm);
        lineEditDni->setObjectName("lineEditDni");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditDni);

        labelNombre = new QLabel(UserForm);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNombre);

        lineEditNombre = new QLineEdit(UserForm);
        lineEditNombre->setObjectName("lineEditNombre");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditNombre);

        labelTelefono = new QLabel(UserForm);
        labelTelefono->setObjectName("labelTelefono");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTelefono);

        lineEditTelefono = new QLineEdit(UserForm);
        lineEditTelefono->setObjectName("lineEditTelefono");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTelefono);

        labelEmail = new QLabel(UserForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(UserForm);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditEmail);

        labelDepartamento = new QLabel(UserForm);
        labelDepartamento->setObjectName("labelDepartamento");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDepartamento);

        comboBoxDepartamento = new QComboBox(UserForm);
        comboBoxDepartamento->setObjectName("comboBoxDepartamento");

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxDepartamento);

        labelEmpresa = new QLabel(UserForm);
        labelEmpresa->setObjectName("labelEmpresa");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelEmpresa);

        comboBoxEmpresa = new QComboBox(UserForm);
        comboBoxEmpresa->setObjectName("comboBoxEmpresa");

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxEmpresa);

        labelEstado = new QLabel(UserForm);
        labelEstado->setObjectName("labelEstado");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelEstado);

        comboBoxEstado = new QComboBox(UserForm);
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->setObjectName("comboBoxEstado");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxEstado);

        labelFoto = new QLabel(UserForm);
        labelFoto->setObjectName("labelFoto");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelFoto);

        lineEditFoto = new QLineEdit(UserForm);
        lineEditFoto->setObjectName("lineEditFoto");

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditFoto);

        labelRol = new QLabel(UserForm);
        labelRol->setObjectName("labelRol");

        formLayout->setWidget(8, QFormLayout::LabelRole, labelRol);

        comboBoxRol = new QComboBox(UserForm);
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->setObjectName("comboBoxRol");

        formLayout->setWidget(8, QFormLayout::FieldRole, comboBoxRol);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnGuardar = new QPushButton(UserForm);
        btnGuardar->setObjectName("btnGuardar");

        buttonLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(UserForm);
        btnCancelar->setObjectName("btnCancelar");

        buttonLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QDialog *UserForm)
    {
        UserForm->setWindowTitle(QCoreApplication::translate("UserForm", "Formulario de Usuario", nullptr));
        labelDNI->setText(QCoreApplication::translate("UserForm", "DNI:", nullptr));
        labelNombre->setText(QCoreApplication::translate("UserForm", "Nombre:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("UserForm", "Tel\303\251fono:", nullptr));
        labelEmail->setText(QCoreApplication::translate("UserForm", "Email:", nullptr));
        labelDepartamento->setText(QCoreApplication::translate("UserForm", "Departamento:", nullptr));
        labelEmpresa->setText(QCoreApplication::translate("UserForm", "Empresa:", nullptr));
        labelEstado->setText(QCoreApplication::translate("UserForm", "Estado:", nullptr));
        comboBoxEstado->setItemText(0, QCoreApplication::translate("UserForm", "Activo", nullptr));
        comboBoxEstado->setItemText(1, QCoreApplication::translate("UserForm", "Inactivo", nullptr));

        labelFoto->setText(QCoreApplication::translate("UserForm", "Foto:", nullptr));
        labelRol->setText(QCoreApplication::translate("UserForm", "Rol:", nullptr));
        comboBoxRol->setItemText(0, QCoreApplication::translate("UserForm", "usuario", nullptr));
        comboBoxRol->setItemText(1, QCoreApplication::translate("UserForm", "admin_empresa", nullptr));
        comboBoxRol->setItemText(2, QCoreApplication::translate("UserForm", "admin", nullptr));

        btnGuardar->setText(QCoreApplication::translate("UserForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("UserForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
