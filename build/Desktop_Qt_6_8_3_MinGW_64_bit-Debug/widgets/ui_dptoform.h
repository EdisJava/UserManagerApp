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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DptoForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *labelNombre;
    QLineEdit *lineEditNombre;
    QLabel *labelDescripcion;
    QTextEdit *textEditDescripcion;
    QLabel *labelEmpresa;
    QComboBox *comboBoxEmpresa;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QDialog *DptoForm)
    {
        if (DptoForm->objectName().isEmpty())
            DptoForm->setObjectName("DptoForm");
        DptoForm->resize(400, 250);
        verticalLayout = new QVBoxLayout(DptoForm);
        verticalLayout->setObjectName("verticalLayout");
        formWidget = new QWidget(DptoForm);
        formWidget->setObjectName("formWidget");
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelNombre = new QLabel(formWidget);
        labelNombre->setObjectName("labelNombre");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNombre);

        lineEditNombre = new QLineEdit(formWidget);
        lineEditNombre->setObjectName("lineEditNombre");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNombre);

        labelDescripcion = new QLabel(formWidget);
        labelDescripcion->setObjectName("labelDescripcion");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDescripcion);

        textEditDescripcion = new QTextEdit(formWidget);
        textEditDescripcion->setObjectName("textEditDescripcion");

        formLayout->setWidget(1, QFormLayout::FieldRole, textEditDescripcion);

        labelEmpresa = new QLabel(formWidget);
        labelEmpresa->setObjectName("labelEmpresa");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelEmpresa);

        comboBoxEmpresa = new QComboBox(formWidget);
        comboBoxEmpresa->setObjectName("comboBoxEmpresa");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxEmpresa);


        verticalLayout->addWidget(formWidget);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        btnGuardar = new QPushButton(DptoForm);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayoutButtons->addWidget(btnGuardar);

        btnCancelar = new QPushButton(DptoForm);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayoutButtons->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayoutButtons);


        retranslateUi(DptoForm);

        QMetaObject::connectSlotsByName(DptoForm);
    } // setupUi

    void retranslateUi(QDialog *DptoForm)
    {
        DptoForm->setWindowTitle(QCoreApplication::translate("DptoForm", "Gesti\303\263n de Departamentos", nullptr));
        labelNombre->setText(QCoreApplication::translate("DptoForm", "Nombre:", nullptr));
        labelDescripcion->setText(QCoreApplication::translate("DptoForm", "Descripci\303\263n:", nullptr));
        labelEmpresa->setText(QCoreApplication::translate("DptoForm", "Empresa:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("DptoForm", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("DptoForm", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DptoForm: public Ui_DptoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPTOFORM_H
