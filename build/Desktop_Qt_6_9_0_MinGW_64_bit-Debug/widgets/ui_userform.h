/********************************************************************************
** Form generated from reading UI file 'userform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
    QLabel *labelRol;
    QComboBox *comboBoxRol;
    QLabel *labelFoto;
    QLineEdit *lineEditFoto;
    QPushButton *btnSeleccionarFoto;
    QLabel *labelFotoRuta;
    QLabel *labelPreviewImage;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName("UserForm");
        UserForm->resize(475, 506);
        verticalLayout = new QVBoxLayout(UserForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelDni = new QLabel(UserForm);
        labelDni->setObjectName("labelDni");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelDni);

        lineEditDni = new QLineEdit(UserForm);
        lineEditDni->setObjectName("lineEditDni");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditDni);

        labelNombre = new QLabel(UserForm);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelNombre);

        lineEditNombre = new QLineEdit(UserForm);
        lineEditNombre->setObjectName("lineEditNombre");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditNombre);

        labelTelefono = new QLabel(UserForm);
        labelTelefono->setObjectName("labelTelefono");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelTelefono);

        lineEditTelefono = new QLineEdit(UserForm);
        lineEditTelefono->setObjectName("lineEditTelefono");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEditTelefono);

        labelEmail = new QLabel(UserForm);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(UserForm);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEditEmail);

        labelDepartamento = new QLabel(UserForm);
        labelDepartamento->setObjectName("labelDepartamento");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelDepartamento);

        comboBoxDepartamento = new QComboBox(UserForm);
        comboBoxDepartamento->setObjectName("comboBoxDepartamento");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, comboBoxDepartamento);

        labelEmpresa = new QLabel(UserForm);
        labelEmpresa->setObjectName("labelEmpresa");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelEmpresa);

        comboBoxEmpresa = new QComboBox(UserForm);
        comboBoxEmpresa->setObjectName("comboBoxEmpresa");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, comboBoxEmpresa);

        labelEstado = new QLabel(UserForm);
        labelEstado->setObjectName("labelEstado");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, labelEstado);

        comboBoxEstado = new QComboBox(UserForm);
        comboBoxEstado->setObjectName("comboBoxEstado");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, comboBoxEstado);

        labelRol = new QLabel(UserForm);
        labelRol->setObjectName("labelRol");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, labelRol);

        comboBoxRol = new QComboBox(UserForm);
        comboBoxRol->setObjectName("comboBoxRol");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, comboBoxRol);

        labelFoto = new QLabel(UserForm);
        labelFoto->setObjectName("labelFoto");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, labelFoto);

        lineEditFoto = new QLineEdit(UserForm);
        lineEditFoto->setObjectName("lineEditFoto");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, lineEditFoto);

        btnSeleccionarFoto = new QPushButton(UserForm);
        btnSeleccionarFoto->setObjectName("btnSeleccionarFoto");

        formLayout->setWidget(9, QFormLayout::ItemRole::FieldRole, btnSeleccionarFoto);

        labelFotoRuta = new QLabel(UserForm);
        labelFotoRuta->setObjectName("labelFotoRuta");

        formLayout->setWidget(10, QFormLayout::ItemRole::FieldRole, labelFotoRuta);


        verticalLayout->addLayout(formLayout);

        labelPreviewImage = new QLabel(UserForm);
        labelPreviewImage->setObjectName("labelPreviewImage");
        labelPreviewImage->setMinimumSize(QSize(200, 150));
        labelPreviewImage->setFrameShape(QFrame::Shape::Box);
        labelPreviewImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelPreviewImage);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

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
        UserForm->setWindowTitle(QCoreApplication::translate("UserForm", "Gesti\303\263n de Usuario", nullptr));
        labelDni->setText(QCoreApplication::translate("UserForm", "DNI:", nullptr));
        labelNombre->setText(QCoreApplication::translate("UserForm", "Nombre:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("UserForm", "Tel\303\251fono:", nullptr));
        labelEmail->setText(QCoreApplication::translate("UserForm", "Email:", nullptr));
        labelDepartamento->setText(QCoreApplication::translate("UserForm", "Departamento:", nullptr));
        labelEmpresa->setText(QCoreApplication::translate("UserForm", "Empresa:", nullptr));
        labelEstado->setText(QCoreApplication::translate("UserForm", "Estado:", nullptr));
        labelRol->setText(QCoreApplication::translate("UserForm", "Rol:", nullptr));
        labelFoto->setText(QCoreApplication::translate("UserForm", "Foto (ruta):", nullptr));
        btnSeleccionarFoto->setText(QCoreApplication::translate("UserForm", "Seleccionar Foto", nullptr));
        labelFotoRuta->setText(QString());
        labelPreviewImage->setText(QCoreApplication::translate("UserForm", "Previsualizaci\303\263n", nullptr));
        btnGuardar->setText(QCoreApplication::translate("UserForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("UserForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
