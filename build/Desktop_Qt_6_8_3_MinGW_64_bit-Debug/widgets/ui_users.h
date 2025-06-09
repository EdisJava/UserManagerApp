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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *labelFoto;
    QHBoxLayout *buttonLayout;
    QPushButton *btnNuevoUsuario;
    QPushButton *btnEditUser;
    QPushButton *btnDeleteUser;

    void setupUi(QDialog *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName("Users");
        verticalLayout = new QVBoxLayout(Users);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(Users);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        labelFoto = new QLabel(Users);
        labelFoto->setObjectName("labelFoto");
        labelFoto->setMinimumSize(QSize(200, 200));
        labelFoto->setFrameShape(QFrame::Box);
        labelFoto->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelFoto);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnNuevoUsuario = new QPushButton(Users);
        btnNuevoUsuario->setObjectName("btnNuevoUsuario");

        buttonLayout->addWidget(btnNuevoUsuario);

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

    void retranslateUi(QDialog *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Gesti\303\263n de Usuarios", nullptr));
        btnNuevoUsuario->setText(QCoreApplication::translate("Users", "Nuevo Usuario", nullptr));
        btnEditUser->setText(QCoreApplication::translate("Users", "Editar Usuario", nullptr));
        btnDeleteUser->setText(QCoreApplication::translate("Users", "Eliminar Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
