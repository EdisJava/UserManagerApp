/********************************************************************************
** Form generated from reading UI file 'guess.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESS_H
#define UI_GUESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Guess
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelInfo;
    QLineEdit *lineEditGuestName;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Guess)
    {
        if (Guess->objectName().isEmpty())
            Guess->setObjectName("Guess");
        verticalLayout = new QVBoxLayout(Guess);
        verticalLayout->setObjectName("verticalLayout");
        labelInfo = new QLabel(Guess);
        labelInfo->setObjectName("labelInfo");
        labelInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelInfo);

        lineEditGuestName = new QLineEdit(Guess);
        lineEditGuestName->setObjectName("lineEditGuestName");

        verticalLayout->addWidget(lineEditGuestName);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(Guess);
        btnOk->setObjectName("btnOk");

        buttonLayout->addWidget(btnOk);

        btnCancel = new QPushButton(Guess);
        btnCancel->setObjectName("btnCancel");

        buttonLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(Guess);

        btnOk->setDefault(true);


        QMetaObject::connectSlotsByName(Guess);
    } // setupUi

    void retranslateUi(QDialog *Guess)
    {
        Guess->setWindowTitle(QCoreApplication::translate("Guess", "Acceso Usuario Invitado", nullptr));
        labelInfo->setText(QCoreApplication::translate("Guess", "Por favor, ingresa tu nombre de invitado", nullptr));
        lineEditGuestName->setPlaceholderText(QCoreApplication::translate("Guess", "Nombre Invitado", nullptr));
        btnOk->setText(QCoreApplication::translate("Guess", "Aceptar", nullptr));
        btnCancel->setText(QCoreApplication::translate("Guess", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Guess: public Ui_Guess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESS_H
