/********************************************************************************
** Form generated from reading UI file 'dptoform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPTOFORM_H
#define UI_DPTOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dptoForm
{
public:

    void setupUi(QWidget *dptoForm)
    {
        if (dptoForm->objectName().isEmpty())
            dptoForm->setObjectName("dptoForm");
        dptoForm->resize(400, 300);

        retranslateUi(dptoForm);

        QMetaObject::connectSlotsByName(dptoForm);
    } // setupUi

    void retranslateUi(QWidget *dptoForm)
    {
        dptoForm->setWindowTitle(QCoreApplication::translate("dptoForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dptoForm: public Ui_dptoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPTOFORM_H
