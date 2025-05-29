#include "guess.h"
#include "ui_guess.h"
#include <QFile>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

Guess::Guess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Guess)
{
ui->setupUi(this);
    // Conectar botón Editar (si lo tienes)
}

Guess::~Guess()
{
    delete ui;
}

void Guess::setDatosUsuario(const QString &dni,
                            const QString &nombre,
                            const QString &telefono,
                            const QString &email,
                            const QString &departamento,
                            const QString &empresa,
                            const QString &estado,
                            const QString &foto,
                            const QString &rol)
{
    ui->labelDni->setText(dni);
    ui->labelNombre->setText(nombre);
    ui->labelTelefono->setText(telefono);
    ui->labelEmail->setText(email);
    ui->labelDepartamento->setText(departamento);
    ui->labelEmpresa->setText(empresa);
    ui->labelEstado->setText(estado);
    ui->labelRol->setText(rol);

    if (QFile::exists(foto)) {
        QPixmap pixmap(foto);
        ui->labelFoto->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->labelFoto->setText("No hay foto");
        ui->labelFoto->setAlignment(Qt::AlignCenter);
    }
}

void Guess::cargarDatosUsuario(const QString &nombre)
{
    QSqlQuery query;
    query.prepare("SELECT dni, nombre, telefono, email, departamento, empresa, estado, foto, rol "
                  "FROM usuarios WHERE LOWER(nombre) = :nombre");
    query.bindValue(":nombre", nombre.toLower());

    if (!query.exec()) {
        qDebug() << "Error al consultar usuario:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        // Obtener los datos
        QString dni = query.value(0).toString();
        QString nombreReal = query.value(1).toString();
        QString telefono = query.value(2).toString();
        QString email = query.value(3).toString();
        QString departamento = query.value(4).toString();
        QString empresa = query.value(5).toString();
        QString estado = query.value(6).toString();
        QString fotoPath = query.value(7).toString();
        QString rol = query.value(8).toString();

        // Asumimos que tienes QLabel con estos objectName:
        findChild<QLabel*>("labelDni")->setText("DNI: " + dni);
        findChild<QLabel*>("labelNombre")->setText("Nombre: " + nombreReal);
        findChild<QLabel*>("labelTelefono")->setText("Teléfono: " + telefono);
        findChild<QLabel*>("labelEmail")->setText("Email: " + email);
        findChild<QLabel*>("labelDepartamento")->setText("Departamento: " + departamento);
        findChild<QLabel*>("labelEmpresa")->setText("Empresa: " + empresa);
        findChild<QLabel*>("labelEstado")->setText("Estado: " + estado);
        findChild<QLabel*>("labelRol")->setText("Rol: " + rol);

        QLabel *fotoLabel = findChild<QLabel*>("labelFoto");
        if (!fotoPath.isEmpty() && QFile::exists(fotoPath)) {
            QPixmap foto(fotoPath);
            fotoLabel->setPixmap(foto.scaled(fotoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            fotoLabel->setText("Sin foto");
        }

    } else {
        qDebug() << "No se encontraron datos para el usuario:" << nombre;
    }
}


