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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmpresaForm
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *Crear;
    QPushButton *Borrar;
    QPushButton *Editar;
    QPushButton *NuevoDept;
    QListWidget *listWidget;

    void setupUi(QWidget *EmpresaForm)
    {
        if (EmpresaForm->objectName().isEmpty())
            EmpresaForm->setObjectName("EmpresaForm");
        EmpresaForm->resize(505, 559);
        verticalLayout = new QVBoxLayout(EmpresaForm);
        verticalLayout->setObjectName("verticalLayout");
        Crear = new QPushButton(EmpresaForm);
        Crear->setObjectName("Crear");

        verticalLayout->addWidget(Crear);

        Borrar = new QPushButton(EmpresaForm);
        Borrar->setObjectName("Borrar");

        verticalLayout->addWidget(Borrar);

        Editar = new QPushButton(EmpresaForm);
        Editar->setObjectName("Editar");

        verticalLayout->addWidget(Editar);

        NuevoDept = new QPushButton(EmpresaForm);
        NuevoDept->setObjectName("NuevoDept");

        verticalLayout->addWidget(NuevoDept);

        listWidget = new QListWidget(EmpresaForm);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(EmpresaForm);

        QMetaObject::connectSlotsByName(EmpresaForm);
    } // setupUi

    void retranslateUi(QWidget *EmpresaForm)
    {
        EmpresaForm->setWindowTitle(QCoreApplication::translate("EmpresaForm", "Empresa", nullptr));
        Crear->setText(QCoreApplication::translate("EmpresaForm", "Crear", nullptr));
        Borrar->setText(QCoreApplication::translate("EmpresaForm", "Borrar", nullptr));
        Editar->setText(QCoreApplication::translate("EmpresaForm", "Editar", nullptr));
        NuevoDept->setText(QCoreApplication::translate("EmpresaForm", "A\303\261adir departamento", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmpresaForm: public Ui_EmpresaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESAFORM_H
