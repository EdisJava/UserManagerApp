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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QListWidget *listWidget;
    QLabel *labelFoto;
    QWidget *widget;
    QHBoxLayout *buttonLayout;
    QPushButton *btnEditUser;
    QPushButton *btnAddUser;
    QPushButton *btnDeleteUser;

    void setupUi(QWidget *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName("Users");
        Users->resize(480, 320);
        listWidget = new QListWidget(Users);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(9, 9, 281, 192));
        labelFoto = new QLabel(Users);
        labelFoto->setObjectName("labelFoto");
        labelFoto->setGeometry(QRect(310, 10, 141, 181));
        widget = new QWidget(Users);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 210, 282, 26));
        buttonLayout = new QHBoxLayout(widget);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        btnEditUser = new QPushButton(widget);
        btnEditUser->setObjectName("btnEditUser");

        buttonLayout->addWidget(btnEditUser);

        btnAddUser = new QPushButton(widget);
        btnAddUser->setObjectName("btnAddUser");

        buttonLayout->addWidget(btnAddUser);

        btnDeleteUser = new QPushButton(widget);
        btnDeleteUser->setObjectName("btnDeleteUser");

        buttonLayout->addWidget(btnDeleteUser);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QWidget *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Gesti\303\263n de Usuarios", nullptr));
        labelFoto->setText(QCoreApplication::translate("Users", "TextLabel", nullptr));
        btnEditUser->setText(QCoreApplication::translate("Users", "Editar Usuario", nullptr));
        btnAddUser->setText(QCoreApplication::translate("Users", "Agregar Usuario", nullptr));
        btnDeleteUser->setText(QCoreApplication::translate("Users", "Eliminar Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
