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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelDni;
    QLineEdit *txtDni;
    QLabel *labelNombre;
    QLineEdit *txtNombre;
    QLabel *labelTelefono;
    QLineEdit *txtTelefono;
    QLabel *labelEmail;
    QLineEdit *txtEmail;
    QLabel *labelDepartamento;
    QComboBox *comboBoxDepartamento;
    QLabel *labelEmpresa;
    QComboBox *comboBoxEmpresa;
    QLabel *labelEstado;
    QComboBox *comboBoxEstado;
    QHBoxLayout *horizontalLayoutImagen;
    QLineEdit *txtImagen;
    QPushButton *btnExaminar;
    QLabel *labelImagen;
    QComboBox *comboBoxRol;
    QLabel *labelRol;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName("UserForm");
        UserForm->resize(400, 370);
        verticalLayout = new QVBoxLayout(UserForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelDni = new QLabel(UserForm);
        labelDni->setObjectName("labelDni");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDni);

        txtDni = new QLineEdit(UserForm);
        txtDni->setObjectName("txtDni");

        formLayout->setWidget(0, QFormLayout::FieldRole, txtDni);

        labelNombre = new QLabel(UserForm);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNombre);

        txtNombre = new QLineEdit(UserForm);
        txtNombre->setObjectName("txtNombre");

        formLayout->setWidget(1, QFormLayout::FieldRole, txtNombre);

        labelTelefono = new QLabel(UserForm);
        labelTelefono->setObjectName("labelTelefono");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTelefono);

        txtTelefono = new QLineEdit(UserForm);
        txtTelefono->setObjectName("txtTelefono");

        formLayout->setWidget(2, QFormLayout::FieldRole, txtTelefono);

        labelEmail = new QLabel(UserForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelEmail);

        txtEmail = new QLineEdit(UserForm);
        txtEmail->setObjectName("txtEmail");

        formLayout->setWidget(3, QFormLayout::FieldRole, txtEmail);

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
        comboBoxEstado->setObjectName("comboBoxEstado");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxEstado);

        horizontalLayoutImagen = new QHBoxLayout();
        horizontalLayoutImagen->setObjectName("horizontalLayoutImagen");
        txtImagen = new QLineEdit(UserForm);
        txtImagen->setObjectName("txtImagen");

        horizontalLayoutImagen->addWidget(txtImagen);

        btnExaminar = new QPushButton(UserForm);
        btnExaminar->setObjectName("btnExaminar");

        horizontalLayoutImagen->addWidget(btnExaminar);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayoutImagen);

        labelImagen = new QLabel(UserForm);
        labelImagen->setObjectName("labelImagen");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelImagen);

        comboBoxRol = new QComboBox(UserForm);
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->addItem(QString());
        comboBoxRol->setObjectName("comboBoxRol");

        formLayout->setWidget(8, QFormLayout::FieldRole, comboBoxRol);

        labelRol = new QLabel(UserForm);
        labelRol->setObjectName("labelRol");

        formLayout->setWidget(8, QFormLayout::LabelRole, labelRol);


        verticalLayout->addLayout(formLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        btnGuardar = new QPushButton(UserForm);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayoutButtons->addWidget(btnGuardar);

        btnCancelar = new QPushButton(UserForm);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayoutButtons->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayoutButtons);


        retranslateUi(UserForm);

        btnGuardar->setDefault(true);


        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QDialog *UserForm)
    {
        UserForm->setWindowTitle(QCoreApplication::translate("UserForm", "Formulario Usuario", nullptr));
        labelDni->setText(QCoreApplication::translate("UserForm", "DNI:", nullptr));
        labelNombre->setText(QCoreApplication::translate("UserForm", "Nombre:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("UserForm", "Tel\303\251fono:", nullptr));
        labelEmail->setText(QCoreApplication::translate("UserForm", "Email:", nullptr));
        labelDepartamento->setText(QCoreApplication::translate("UserForm", "Departamento:", nullptr));
        labelEmpresa->setText(QCoreApplication::translate("UserForm", "Empresa:", nullptr));
        labelEstado->setText(QCoreApplication::translate("UserForm", "Estado:", nullptr));
        btnExaminar->setText(QCoreApplication::translate("UserForm", "Examinar", nullptr));
        labelImagen->setText(QCoreApplication::translate("UserForm", "Imagen:", nullptr));
        comboBoxRol->setItemText(0, QCoreApplication::translate("UserForm", "AdminTotal", nullptr));
        comboBoxRol->setItemText(1, QCoreApplication::translate("UserForm", "AdminEmpresa", nullptr));
        comboBoxRol->setItemText(2, QCoreApplication::translate("UserForm", "Usuario", nullptr));

        labelRol->setText(QCoreApplication::translate("UserForm", "Rol:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("UserForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("UserForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
