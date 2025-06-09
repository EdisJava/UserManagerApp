/********************************************************************************
** Form generated from reading UI file 'guess.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESS_H
#define UI_GUESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Guess
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelDniText;
    QLabel *labelDni;
    QLabel *labelNombreText;
    QLabel *labelNombre;
    QLabel *labelTelefonoText;
    QLabel *labelTelefono;
    QLabel *labelEmailText;
    QLabel *labelEmail;
    QLabel *labelDepartamentoText;
    QLabel *labelDepartamento;
    QLabel *labelEmpresaText;
    QLabel *labelEmpresa;
    QLabel *labelEstadoText;
    QLabel *labelEstado;
    QLabel *labelRolText;
    QLabel *labelRol;
    QLabel *labelFoto;

    void setupUi(QWidget *Guess)
    {
        if (Guess->objectName().isEmpty())
            Guess->setObjectName("Guess");
        Guess->resize(362, 311);
        verticalLayout = new QVBoxLayout(Guess);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelDniText = new QLabel(Guess);
        labelDniText->setObjectName("labelDniText");

        gridLayout->addWidget(labelDniText, 0, 0, 1, 1);

        labelDni = new QLabel(Guess);
        labelDni->setObjectName("labelDni");

        gridLayout->addWidget(labelDni, 0, 1, 1, 1);

        labelNombreText = new QLabel(Guess);
        labelNombreText->setObjectName("labelNombreText");

        gridLayout->addWidget(labelNombreText, 1, 0, 1, 1);

        labelNombre = new QLabel(Guess);
        labelNombre->setObjectName("labelNombre");

        gridLayout->addWidget(labelNombre, 1, 1, 1, 1);

        labelTelefonoText = new QLabel(Guess);
        labelTelefonoText->setObjectName("labelTelefonoText");

        gridLayout->addWidget(labelTelefonoText, 2, 0, 1, 1);

        labelTelefono = new QLabel(Guess);
        labelTelefono->setObjectName("labelTelefono");

        gridLayout->addWidget(labelTelefono, 2, 1, 1, 1);

        labelEmailText = new QLabel(Guess);
        labelEmailText->setObjectName("labelEmailText");

        gridLayout->addWidget(labelEmailText, 3, 0, 1, 1);

        labelEmail = new QLabel(Guess);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 3, 1, 1, 1);

        labelDepartamentoText = new QLabel(Guess);
        labelDepartamentoText->setObjectName("labelDepartamentoText");

        gridLayout->addWidget(labelDepartamentoText, 4, 0, 1, 1);

        labelDepartamento = new QLabel(Guess);
        labelDepartamento->setObjectName("labelDepartamento");

        gridLayout->addWidget(labelDepartamento, 4, 1, 1, 1);

        labelEmpresaText = new QLabel(Guess);
        labelEmpresaText->setObjectName("labelEmpresaText");

        gridLayout->addWidget(labelEmpresaText, 5, 0, 1, 1);

        labelEmpresa = new QLabel(Guess);
        labelEmpresa->setObjectName("labelEmpresa");

        gridLayout->addWidget(labelEmpresa, 5, 1, 1, 1);

        labelEstadoText = new QLabel(Guess);
        labelEstadoText->setObjectName("labelEstadoText");

        gridLayout->addWidget(labelEstadoText, 6, 0, 1, 1);

        labelEstado = new QLabel(Guess);
        labelEstado->setObjectName("labelEstado");

        gridLayout->addWidget(labelEstado, 6, 1, 1, 1);

        labelRolText = new QLabel(Guess);
        labelRolText->setObjectName("labelRolText");

        gridLayout->addWidget(labelRolText, 7, 0, 1, 1);

        labelRol = new QLabel(Guess);
        labelRol->setObjectName("labelRol");

        gridLayout->addWidget(labelRol, 7, 1, 1, 1);

        labelFoto = new QLabel(Guess);
        labelFoto->setObjectName("labelFoto");
        labelFoto->setMinimumSize(QSize(120, 120));
        labelFoto->setFrameShape(QFrame::Shape::Box);
        labelFoto->setFrameShadow(QFrame::Shadow::Raised);
        labelFoto->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelFoto, 0, 2, 6, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Guess);

        QMetaObject::connectSlotsByName(Guess);
    } // setupUi

    void retranslateUi(QWidget *Guess)
    {
        Guess->setWindowTitle(QCoreApplication::translate("Guess", "Guess", nullptr));
        labelDniText->setText(QCoreApplication::translate("Guess", "DNI:", nullptr));
        labelDni->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelNombreText->setText(QCoreApplication::translate("Guess", "Nombre:", nullptr));
        labelNombre->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelTelefonoText->setText(QCoreApplication::translate("Guess", "Tel\303\251fono:", nullptr));
        labelTelefono->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelEmailText->setText(QCoreApplication::translate("Guess", "Email:", nullptr));
        labelEmail->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelDepartamentoText->setText(QCoreApplication::translate("Guess", "Departamento:", nullptr));
        labelDepartamento->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelEmpresaText->setText(QCoreApplication::translate("Guess", "Empresa:", nullptr));
        labelEmpresa->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelEstadoText->setText(QCoreApplication::translate("Guess", "Estado:", nullptr));
        labelEstado->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelRolText->setText(QCoreApplication::translate("Guess", "Rol:", nullptr));
        labelRol->setText(QCoreApplication::translate("Guess", "---", nullptr));
        labelFoto->setText(QCoreApplication::translate("Guess", "No hay foto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Guess: public Ui_Guess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESS_H
