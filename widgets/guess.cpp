#include "Guess.h"
#include "ui_Guess.h"
#include <QDebug>

Guess::Guess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guess)
{
    ui->setupUi(this);
}

Guess::~Guess()
{
    delete ui;
}

void Guess::mostrarDatos(const QString &dni,
                         const QString &nombre,
                         const QString &telefono,
                         const QString &email,
                         const QString &departamento,
                         const QString &empresa,
                         const QString &estado,
                         const QString &rol,
                         const QPixmap &foto)
{
    ui->labelDni->setText(dni);
    ui->labelNombre->setText(nombre);
    ui->labelTelefono->setText(telefono);
    ui->labelEmail->setText(email);
    ui->labelDepartamento->setText(departamento);
    ui->labelEmpresa->setText(empresa);
    ui->labelEstado->setText(estado);
    ui->labelRol->setText(rol);

    if (!foto.isNull()) {
        ui->labelFoto->setPixmap(foto.scaled(
            ui->labelFoto->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));
    } else {
        ui->labelFoto->setText("No hay foto");
    }
}
