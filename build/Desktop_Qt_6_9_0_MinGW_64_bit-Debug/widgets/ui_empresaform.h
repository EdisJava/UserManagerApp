/********************************************************************************
** Form generated from reading UI file 'empresaform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPRESAFORM_H
#define UI_EMPRESAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmpresaForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableViewEmpresas;
    QHBoxLayout *horizontalLayoutForm;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QHBoxLayout *horizontalLayoutBotones;
    QPushButton *btnCrear;
    QPushButton *btnEditar;
    QPushButton *btnBorrar;

    void setupUi(QWidget *EmpresaForm)
    {
        if (EmpresaForm->objectName().isEmpty())
            EmpresaForm->setObjectName("EmpresaForm");
        EmpresaForm->resize(758, 540);
        verticalLayout = new QVBoxLayout(EmpresaForm);
        verticalLayout->setObjectName("verticalLayout");
        tableViewEmpresas = new QTableView(EmpresaForm);
        tableViewEmpresas->setObjectName("tableViewEmpresas");

        verticalLayout->addWidget(tableViewEmpresas);

        horizontalLayoutForm = new QHBoxLayout();
        horizontalLayoutForm->setObjectName("horizontalLayoutForm");
        labelNombre = new QLabel(EmpresaForm);
        labelNombre->setObjectName("labelNombre");

        horizontalLayoutForm->addWidget(labelNombre);

        lineEditNombre = new QLineEdit(EmpresaForm);
        lineEditNombre->setObjectName("lineEditNombre");

        horizontalLayoutForm->addWidget(lineEditNombre);


        verticalLayout->addLayout(horizontalLayoutForm);

        horizontalLayoutBotones = new QHBoxLayout();
        horizontalLayoutBotones->setObjectName("horizontalLayoutBotones");
        btnCrear = new QPushButton(EmpresaForm);
        btnCrear->setObjectName("btnCrear");

        horizontalLayoutBotones->addWidget(btnCrear);

        btnEditar = new QPushButton(EmpresaForm);
        btnEditar->setObjectName("btnEditar");

        horizontalLayoutBotones->addWidget(btnEditar);

        btnBorrar = new QPushButton(EmpresaForm);
        btnBorrar->setObjectName("btnBorrar");

        horizontalLayoutBotones->addWidget(btnBorrar);


        verticalLayout->addLayout(horizontalLayoutBotones);


        retranslateUi(EmpresaForm);

        QMetaObject::connectSlotsByName(EmpresaForm);
    } // setupUi

    void retranslateUi(QWidget *EmpresaForm)
    {
        EmpresaForm->setWindowTitle(QCoreApplication::translate("EmpresaForm", "Gesti\303\263n de Empresas", nullptr));
        labelNombre->setText(QCoreApplication::translate("EmpresaForm", "Nombre:", nullptr));
        btnCrear->setText(QCoreApplication::translate("EmpresaForm", "Crear", nullptr));
        btnEditar->setText(QCoreApplication::translate("EmpresaForm", "Editar", nullptr));
        btnBorrar->setText(QCoreApplication::translate("EmpresaForm", "Borrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmpresaForm: public Ui_EmpresaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESAFORM_H
