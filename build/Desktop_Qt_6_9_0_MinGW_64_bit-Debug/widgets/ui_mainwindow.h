/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *Login;
    QVBoxLayout *loginLayout;
    QSpacerItem *verticalSpacerTop;
    QVBoxLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditUsuario;
    QPushButton *btnEntrar;
    QSpacerItem *verticalSpacerBottom;
    QWidget *AdminTotal;
    QWidget *AdminEmpresa;
    QVBoxLayout *verticalLayout;
    QWidget *UsuarioEstandar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(631, 441);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        Login = new QWidget();
        Login->setObjectName("Login");
        loginLayout = new QVBoxLayout(Login);
        loginLayout->setObjectName("loginLayout");
        verticalSpacerTop = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(verticalSpacerTop);

        formLayout = new QVBoxLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->addWidget(label);

        lineEditUsuario = new QLineEdit(Login);
        lineEditUsuario->setObjectName("lineEditUsuario");

        formLayout->addWidget(lineEditUsuario);

        btnEntrar = new QPushButton(Login);
        btnEntrar->setObjectName("btnEntrar");

        formLayout->addWidget(btnEntrar);


        loginLayout->addLayout(formLayout);

        verticalSpacerBottom = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(verticalSpacerBottom);

        tabWidget->addTab(Login, QString());
        AdminTotal = new QWidget();
        AdminTotal->setObjectName("AdminTotal");
        tabWidget->addTab(AdminTotal, QString());
        AdminEmpresa = new QWidget();
        AdminEmpresa->setObjectName("AdminEmpresa");
        verticalLayout = new QVBoxLayout(AdminEmpresa);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget->addTab(AdminEmpresa, QString());
        UsuarioEstandar = new QWidget();
        UsuarioEstandar->setObjectName("UsuarioEstandar");
        tabWidget->addTab(UsuarioEstandar, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 631, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Inserte su nombre de usuario", nullptr));
        btnEntrar->setText(QCoreApplication::translate("MainWindow", "Entrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Login), QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AdminTotal), QCoreApplication::translate("MainWindow", "Admin Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AdminEmpresa), QCoreApplication::translate("MainWindow", "Admin Empresa", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(UsuarioEstandar), QCoreApplication::translate("MainWindow", "Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
