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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdmiCompany
{
public:
    QVBoxLayout *verticalLayoutMain;
    QListWidget *listWidgetCompanies;
    QFormLayout *formLayoutCompany;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QLabel *labelDireccion;
    QLineEdit *lineEditDireccion;
    QLabel *labelTelefono;
    QLineEdit *lineEditTelefono;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelEstado;
    QComboBox *comboBoxEstado;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAgregar;
    QPushButton *btnEditar;
    QPushButton *btnEliminar;

    void setupUi(QDialog *AdmiCompany)
    {
        if (AdmiCompany->objectName().isEmpty())
            AdmiCompany->setObjectName("AdmiCompany");
        verticalLayoutMain = new QVBoxLayout(AdmiCompany);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        listWidgetCompanies = new QListWidget(AdmiCompany);
        listWidgetCompanies->setObjectName("listWidgetCompanies");

        verticalLayoutMain->addWidget(listWidgetCompanies);

        formLayoutCompany = new QFormLayout();
        formLayoutCompany->setObjectName("formLayoutCompany");
        labelNombre = new QLabel(AdmiCompany);
        labelNombre->setObjectName("labelNombre");

        formLayoutCompany->setWidget(0, QFormLayout::LabelRole, labelNombre);

        lineEditNombre = new QLineEdit(AdmiCompany);
        lineEditNombre->setObjectName("lineEditNombre");

        formLayoutCompany->setWidget(0, QFormLayout::FieldRole, lineEditNombre);

        labelDireccion = new QLabel(AdmiCompany);
        labelDireccion->setObjectName("labelDireccion");

        formLayoutCompany->setWidget(1, QFormLayout::LabelRole, labelDireccion);

        lineEditDireccion = new QLineEdit(AdmiCompany);
        lineEditDireccion->setObjectName("lineEditDireccion");

        formLayoutCompany->setWidget(1, QFormLayout::FieldRole, lineEditDireccion);

        labelTelefono = new QLabel(AdmiCompany);
        labelTelefono->setObjectName("labelTelefono");

        formLayoutCompany->setWidget(2, QFormLayout::LabelRole, labelTelefono);

        lineEditTelefono = new QLineEdit(AdmiCompany);
        lineEditTelefono->setObjectName("lineEditTelefono");

        formLayoutCompany->setWidget(2, QFormLayout::FieldRole, lineEditTelefono);

        labelEmail = new QLabel(AdmiCompany);
        labelEmail->setObjectName("labelEmail");

        formLayoutCompany->setWidget(3, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(AdmiCompany);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayoutCompany->setWidget(3, QFormLayout::FieldRole, lineEditEmail);

        labelEstado = new QLabel(AdmiCompany);
        labelEstado->setObjectName("labelEstado");

        formLayoutCompany->setWidget(4, QFormLayout::LabelRole, labelEstado);

        comboBoxEstado = new QComboBox(AdmiCompany);
        comboBoxEstado->addItem(QString());
        comboBoxEstado->addItem(QString());
        comboBoxEstado->setObjectName("comboBoxEstado");

        formLayoutCompany->setWidget(4, QFormLayout::FieldRole, comboBoxEstado);


        verticalLayoutMain->addLayout(formLayoutCompany);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        btnAgregar = new QPushButton(AdmiCompany);
        btnAgregar->setObjectName("btnAgregar");

        horizontalLayoutButtons->addWidget(btnAgregar);

        btnEditar = new QPushButton(AdmiCompany);
        btnEditar->setObjectName("btnEditar");

        horizontalLayoutButtons->addWidget(btnEditar);

        btnEliminar = new QPushButton(AdmiCompany);
        btnEliminar->setObjectName("btnEliminar");

        horizontalLayoutButtons->addWidget(btnEliminar);


        verticalLayoutMain->addLayout(horizontalLayoutButtons);


        retranslateUi(AdmiCompany);

        QMetaObject::connectSlotsByName(AdmiCompany);
    } // setupUi

    void retranslateUi(QDialog *AdmiCompany)
    {
        AdmiCompany->setWindowTitle(QCoreApplication::translate("AdmiCompany", "Administrar Empresas", nullptr));
        labelNombre->setText(QCoreApplication::translate("AdmiCompany", "Nombre:", nullptr));
        labelDireccion->setText(QCoreApplication::translate("AdmiCompany", "Direcci\303\263n:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("AdmiCompany", "Tel\303\251fono:", nullptr));
        labelEmail->setText(QCoreApplication::translate("AdmiCompany", "Email:", nullptr));
        labelEstado->setText(QCoreApplication::translate("AdmiCompany", "Estado:", nullptr));
        comboBoxEstado->setItemText(0, QCoreApplication::translate("AdmiCompany", "Activo", nullptr));
        comboBoxEstado->setItemText(1, QCoreApplication::translate("AdmiCompany", "Inactivo", nullptr));

        btnAgregar->setText(QCoreApplication::translate("AdmiCompany", "Agregar", nullptr));
        btnEditar->setText(QCoreApplication::translate("AdmiCompany", "Editar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("AdmiCompany", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdmiCompany: public Ui_AdmiCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMICOMPANY_H
