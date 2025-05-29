/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Login;
    QLineEdit *lineEditUsuario;
    QPushButton *btnEntrar;
    QLabel *label;
    QWidget *AdminTotal;
    QWidget *AdminEmpresa;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *UsuarioEstandar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(150, 50, 581, 441));
        Login = new QWidget();
        Login->setObjectName("Login");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        lineEditUsuario = new QLineEdit(Login);
        lineEditUsuario->setObjectName("lineEditUsuario");
        lineEditUsuario->setGeometry(QRect(130, 140, 231, 21));
        btnEntrar = new QPushButton(Login);
        btnEntrar->setObjectName("btnEntrar");
        btnEntrar->setGeometry(QRect(200, 200, 80, 24));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 120, 153, 16));
        tabWidget->addTab(Login, QString());
        AdminTotal = new QWidget();
        AdminTotal->setObjectName("AdminTotal");
        tabWidget->addTab(AdminTotal, QString());
        AdminEmpresa = new QWidget();
        AdminEmpresa->setObjectName("AdminEmpresa");
        verticalLayoutWidget = new QWidget(AdminEmpresa);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 581, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(AdminEmpresa, QString());
        UsuarioEstandar = new QWidget();
        UsuarioEstandar->setObjectName("UsuarioEstandar");
        tabWidget->addTab(UsuarioEstandar, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnEntrar->setText(QCoreApplication::translate("MainWindow", "Entrar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Inserte su nombre de usuario", nullptr));
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
