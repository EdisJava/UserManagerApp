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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DptoForm
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *btnCrear;
    QPushButton *btnBorrar;
    QPushButton *btnEditar;
    QPushButton *btnAsignarUsr;

    void setupUi(QWidget *DptoForm)
    {
        if (DptoForm->objectName().isEmpty())
            DptoForm->setObjectName("DptoForm");
        DptoForm->resize(493, 314);
        verticalLayout = new QVBoxLayout(DptoForm);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(DptoForm);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        btnCrear = new QPushButton(DptoForm);
        btnCrear->setObjectName("btnCrear");

        verticalLayout->addWidget(btnCrear);

        btnBorrar = new QPushButton(DptoForm);
        btnBorrar->setObjectName("btnBorrar");

        verticalLayout->addWidget(btnBorrar);

        btnEditar = new QPushButton(DptoForm);
        btnEditar->setObjectName("btnEditar");

        verticalLayout->addWidget(btnEditar);

        btnAsignarUsr = new QPushButton(DptoForm);
        btnAsignarUsr->setObjectName("btnAsignarUsr");

        verticalLayout->addWidget(btnAsignarUsr);


        retranslateUi(DptoForm);

        QMetaObject::connectSlotsByName(DptoForm);
    } // setupUi

    void retranslateUi(QWidget *DptoForm)
    {
        DptoForm->setWindowTitle(QCoreApplication::translate("DptoForm", "Departamento", nullptr));
        btnCrear->setText(QCoreApplication::translate("DptoForm", "Crear", nullptr));
        btnBorrar->setText(QCoreApplication::translate("DptoForm", "Borrar", nullptr));
        btnEditar->setText(QCoreApplication::translate("DptoForm", "Editar", nullptr));
        btnAsignarUsr->setText(QCoreApplication::translate("DptoForm", "Asignar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DptoForm: public Ui_DptoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPTOFORM_H
