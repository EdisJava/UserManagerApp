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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admicompany
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCrear;
    QPushButton *btnEditar;
    QPushButton *btnBorrar;

    void setupUi(QWidget *admicompany)
    {
        if (admicompany->objectName().isEmpty())
            admicompany->setObjectName("admicompany");
        admicompany->resize(400, 300);
        verticalLayout = new QVBoxLayout(admicompany);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(admicompany);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnCrear = new QPushButton(admicompany);
        btnCrear->setObjectName("btnCrear");

        horizontalLayout->addWidget(btnCrear);

        btnEditar = new QPushButton(admicompany);
        btnEditar->setObjectName("btnEditar");

        horizontalLayout->addWidget(btnEditar);

        btnBorrar = new QPushButton(admicompany);
        btnBorrar->setObjectName("btnBorrar");

        horizontalLayout->addWidget(btnBorrar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(admicompany);

        QMetaObject::connectSlotsByName(admicompany);
    } // setupUi

    void retranslateUi(QWidget *admicompany)
    {
        admicompany->setWindowTitle(QCoreApplication::translate("admicompany", "Gesti\303\263n de Usuarios - Empresa", nullptr));
        btnCrear->setText(QCoreApplication::translate("admicompany", "Crear", nullptr));
        btnEditar->setText(QCoreApplication::translate("admicompany", "Editar", nullptr));
        btnBorrar->setText(QCoreApplication::translate("admicompany", "Borrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admicompany: public Ui_admicompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMICOMPANY_H
