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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalir;
    QAction *actionNuevo;
    QAction *actionGuardar;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelWelcome;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuEditar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName("actionNuevo");
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName("actionGuardar");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelWelcome = new QLabel(centralwidget);
        labelWelcome->setObjectName("labelWelcome");
        labelWelcome->setAlignment(Qt::AlignCenter);
        labelWelcome->setMinimumSize(QSize(400, 200));

        verticalLayout->addWidget(labelWelcome);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 20));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuEditar = new QMenu(menubar);
        menuEditar->setObjectName("menuEditar");
        MainWindow->setMenuBar(menubar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(mainToolBar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuEditar->menuAction());
        menuArchivo->addAction(actionSalir);
        mainToolBar->addAction(actionNuevo);
        mainToolBar->addAction(actionGuardar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Aplicaci\303\263n Principal", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionNuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        labelWelcome->setText(QCoreApplication::translate("MainWindow", "Bienvenido a la Aplicaci\303\263n", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "&Archivo", nullptr));
        menuEditar->setTitle(QCoreApplication::translate("MainWindow", "&Editar", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Barra de Herramientas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
