/********************************************************************************
** Form generated from reading UI file 'usuarioform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIOFORM_H
#define UI_USUARIOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usuarioForm
{
public:

    void setupUi(QWidget *usuarioForm)
    {
        if (usuarioForm->objectName().isEmpty())
            usuarioForm->setObjectName("usuarioForm");
        usuarioForm->resize(400, 300);

        retranslateUi(usuarioForm);

        QMetaObject::connectSlotsByName(usuarioForm);
    } // setupUi

    void retranslateUi(QWidget *usuarioForm)
    {
        usuarioForm->setWindowTitle(QCoreApplication::translate("usuarioForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usuarioForm: public Ui_usuarioForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIOFORM_H
