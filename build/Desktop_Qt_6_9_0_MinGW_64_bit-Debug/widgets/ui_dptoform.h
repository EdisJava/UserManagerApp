/********************************************************************************
** Form generated from reading UI file 'dptoform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPTOFORM_H
#define UI_DPTOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DptoForm
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableViewDepartamentos;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnCrear;
    QPushButton *btnEditar;
    QPushButton *btnBorrar;

    void setupUi(QDialog *DptoForm)
    {
        if (DptoForm->objectName().isEmpty())
            DptoForm->setObjectName("DptoForm");
        DptoForm->resize(392, 301);
        verticalLayout = new QVBoxLayout(DptoForm);
        verticalLayout->setObjectName("verticalLayout");
        tableViewDepartamentos = new QTableView(DptoForm);
        tableViewDepartamentos->setObjectName("tableViewDepartamentos");

        verticalLayout->addWidget(tableViewDepartamentos);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelNombre = new QLabel(DptoForm);
        labelNombre->setObjectName("labelNombre");

        horizontalLayout->addWidget(labelNombre);

        lineEditNombre = new QLineEdit(DptoForm);
        lineEditNombre->setObjectName("lineEditNombre");

        horizontalLayout->addWidget(lineEditNombre);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnCrear = new QPushButton(DptoForm);
        btnCrear->setObjectName("btnCrear");

        horizontalLayoutButtons->addWidget(btnCrear);

        btnEditar = new QPushButton(DptoForm);
        btnEditar->setObjectName("btnEditar");

        horizontalLayoutButtons->addWidget(btnEditar);

        btnBorrar = new QPushButton(DptoForm);
        btnBorrar->setObjectName("btnBorrar");

        horizontalLayoutButtons->addWidget(btnBorrar);


        verticalLayout->addLayout(horizontalLayoutButtons);


        retranslateUi(DptoForm);

        QMetaObject::connectSlotsByName(DptoForm);
    } // setupUi

    void retranslateUi(QDialog *DptoForm)
    {
        DptoForm->setWindowTitle(QCoreApplication::translate("DptoForm", "Gesti\303\263n de Departamentos", nullptr));
        labelNombre->setText(QCoreApplication::translate("DptoForm", "Nombre:", nullptr));
        btnCrear->setText(QCoreApplication::translate("DptoForm", "Crear", nullptr));
        btnEditar->setText(QCoreApplication::translate("DptoForm", "Editar", nullptr));
        btnBorrar->setText(QCoreApplication::translate("DptoForm", "Borrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DptoForm: public Ui_DptoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPTOFORM_H
