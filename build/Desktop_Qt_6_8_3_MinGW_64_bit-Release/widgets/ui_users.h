/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableUsers;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAddUser;
    QPushButton *btnEditUser;
    QPushButton *btnDeleteUser;

    void setupUi(QWidget *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName("Users");
        Users->resize(480, 320);
        verticalLayout = new QVBoxLayout(Users);
        verticalLayout->setObjectName("verticalLayout");
        tableUsers = new QTableWidget(Users);
        tableUsers->setObjectName("tableUsers");
        tableUsers->setColumnCount(4);
        tableUsers->setRowCount(0);
        tableUsers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableUsers->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(tableUsers);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnAddUser = new QPushButton(Users);
        btnAddUser->setObjectName("btnAddUser");

        buttonLayout->addWidget(btnAddUser);

        btnEditUser = new QPushButton(Users);
        btnEditUser->setObjectName("btnEditUser");

        buttonLayout->addWidget(btnEditUser);

        btnDeleteUser = new QPushButton(Users);
        btnDeleteUser->setObjectName("btnDeleteUser");

        buttonLayout->addWidget(btnDeleteUser);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QWidget *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Gesti\303\263n de Usuarios", nullptr));
        tableUsers->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("Users", "ID", nullptr),
            QCoreApplication::translate("Users", "Nombre", nullptr),
            QCoreApplication::translate("Users", "Email", nullptr),
            QCoreApplication::translate("Users", "Rol", nullptr)});
        btnAddUser->setText(QCoreApplication::translate("Users", "Agregar Usuario", nullptr));
        btnEditUser->setText(QCoreApplication::translate("Users", "Editar Usuario", nullptr));
        btnDeleteUser->setText(QCoreApplication::translate("Users", "Eliminar Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
