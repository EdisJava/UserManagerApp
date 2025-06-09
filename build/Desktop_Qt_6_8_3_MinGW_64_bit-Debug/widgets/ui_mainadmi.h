/********************************************************************************
** Form generated from reading UI file 'mainadmi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINADMI_H
#define UI_MAINADMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainAdmi
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QListWidget *listWidgetUsers;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAddUser;
    QPushButton *btnEditUser;
    QPushButton *btnDeleteUser;

    void setupUi(QDialog *MainAdmi)
    {
        if (MainAdmi->objectName().isEmpty())
            MainAdmi->setObjectName("MainAdmi");
        verticalLayout = new QVBoxLayout(MainAdmi);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(MainAdmi);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTitle->setMinimumSize(QSize(300, 40));

        verticalLayout->addWidget(labelTitle);

        listWidgetUsers = new QListWidget(MainAdmi);
        listWidgetUsers->setObjectName("listWidgetUsers");
        listWidgetUsers->setMinimumSize(QSize(250, 150));

        verticalLayout->addWidget(listWidgetUsers);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnAddUser = new QPushButton(MainAdmi);
        btnAddUser->setObjectName("btnAddUser");

        buttonLayout->addWidget(btnAddUser);

        btnEditUser = new QPushButton(MainAdmi);
        btnEditUser->setObjectName("btnEditUser");

        buttonLayout->addWidget(btnEditUser);

        btnDeleteUser = new QPushButton(MainAdmi);
        btnDeleteUser->setObjectName("btnDeleteUser");

        buttonLayout->addWidget(btnDeleteUser);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(MainAdmi);

        QMetaObject::connectSlotsByName(MainAdmi);
    } // setupUi

    void retranslateUi(QDialog *MainAdmi)
    {
        MainAdmi->setWindowTitle(QCoreApplication::translate("MainAdmi", "Panel Administrativo", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainAdmi", "Panel de Administraci\303\263n", nullptr));
        btnAddUser->setText(QCoreApplication::translate("MainAdmi", "Agregar Usuario", nullptr));
        btnEditUser->setText(QCoreApplication::translate("MainAdmi", "Editar Usuario", nullptr));
        btnDeleteUser->setText(QCoreApplication::translate("MainAdmi", "Eliminar Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainAdmi: public Ui_MainAdmi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMI_H
