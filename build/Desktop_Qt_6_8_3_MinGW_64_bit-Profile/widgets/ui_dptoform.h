/********************************************************************************
** Form generated from reading UI file 'dptoform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPTOFORM_H
#define UI_DPTOFORM_H

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

class Ui_DptoForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtNombre;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QWidget *DptoForm)
    {
        if (DptoForm->objectName().isEmpty())
            DptoForm->setObjectName("DptoForm");
        DptoForm->resize(300, 150);
        verticalLayout = new QVBoxLayout(DptoForm);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DptoForm);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtNombre = new QLineEdit(DptoForm);
        txtNombre->setObjectName("txtNombre");

        formLayout->setWidget(0, QFormLayout::FieldRole, txtNombre);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGuardar = new QPushButton(DptoForm);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(DptoForm);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DptoForm);

        QMetaObject::connectSlotsByName(DptoForm);
    } // setupUi

    void retranslateUi(QWidget *DptoForm)
    {
        DptoForm->setWindowTitle(QCoreApplication::translate("DptoForm", "Departamento", nullptr));
        label->setText(QCoreApplication::translate("DptoForm", "Nombre del Departamento:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("DptoForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("DptoForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DptoForm: public Ui_DptoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPTOFORM_H
