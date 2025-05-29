/********************************************************************************
** Form generated from reading UI file 'empresaform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPRESAFORM_H
#define UI_EMPRESAFORM_H

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

class Ui_EmpresaForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNombre;
    QLineEdit *txtNombre;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QWidget *EmpresaForm)
    {
        if (EmpresaForm->objectName().isEmpty())
            EmpresaForm->setObjectName("EmpresaForm");
        EmpresaForm->resize(300, 150);
        verticalLayout = new QVBoxLayout(EmpresaForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelNombre = new QLabel(EmpresaForm);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombre);

        txtNombre = new QLineEdit(EmpresaForm);
        txtNombre->setObjectName("txtNombre");

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGuardar = new QPushButton(EmpresaForm);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(EmpresaForm);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EmpresaForm);

        QMetaObject::connectSlotsByName(EmpresaForm);
    } // setupUi

    void retranslateUi(QWidget *EmpresaForm)
    {
        EmpresaForm->setWindowTitle(QCoreApplication::translate("EmpresaForm", "Empresa", nullptr));
        labelNombre->setText(QCoreApplication::translate("EmpresaForm", "Nombre de la empresa:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("EmpresaForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("EmpresaForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmpresaForm: public Ui_EmpresaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESAFORM_H
