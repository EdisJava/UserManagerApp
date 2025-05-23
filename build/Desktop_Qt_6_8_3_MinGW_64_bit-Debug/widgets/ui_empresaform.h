/********************************************************************************
** Form generated from reading UI file 'empresaform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPRESAFORM_H
#define UI_EMPRESAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_empresaForm
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *empresaForm)
    {
        if (empresaForm->objectName().isEmpty())
            empresaForm->setObjectName("empresaForm");
        empresaForm->resize(800, 600);
        centralwidget = new QWidget(empresaForm);
        centralwidget->setObjectName("centralwidget");
        empresaForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(empresaForm);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        empresaForm->setMenuBar(menubar);
        statusbar = new QStatusBar(empresaForm);
        statusbar->setObjectName("statusbar");
        empresaForm->setStatusBar(statusbar);

        retranslateUi(empresaForm);

        QMetaObject::connectSlotsByName(empresaForm);
    } // setupUi

    void retranslateUi(QMainWindow *empresaForm)
    {
        empresaForm->setWindowTitle(QCoreApplication::translate("empresaForm", "empresaForm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class empresaForm: public Ui_empresaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPRESAFORM_H
