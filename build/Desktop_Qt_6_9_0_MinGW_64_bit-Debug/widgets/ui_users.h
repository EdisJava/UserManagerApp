/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QListView *listView;
    QLabel *labelFoto;
    QWidget *buttonWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *btnEditUser;
    QPushButton *btnAddUser;
    QPushButton *btnDeleteUser;

    void setupUi(QDialog *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName("Users");
        Users->resize(480, 320);
        listView = new QListView(Users);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(9, 9, 281, 192));
        labelFoto = new QLabel(Users);
        labelFoto->setObjectName("labelFoto");
        labelFoto->setGeometry(QRect(310, 10, 141, 181));
        labelFoto->setFrameShape(QFrame::Shape::Box);
        labelFoto->setAlignment(Qt::AlignmentFlag::AlignCenter);
        buttonWidget = new QWidget(Users);
        buttonWidget->setObjectName("buttonWidget");
        buttonWidget->setGeometry(QRect(10, 210, 441, 40));
        buttonLayout = new QHBoxLayout(buttonWidget);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        btnEditUser = new QPushButton(buttonWidget);
        btnEditUser->setObjectName("btnEditUser");

        buttonLayout->addWidget(btnEditUser);

        btnAddUser = new QPushButton(buttonWidget);
        btnAddUser->setObjectName("btnAddUser");

        buttonLayout->addWidget(btnAddUser);

        btnDeleteUser = new QPushButton(buttonWidget);
        btnDeleteUser->setObjectName("btnDeleteUser");

        buttonLayout->addWidget(btnDeleteUser);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QDialog *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "Gesti\303\263n de Usuarios", nullptr));
        labelFoto->setText(QCoreApplication::translate("Users", "Foto", nullptr));
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
