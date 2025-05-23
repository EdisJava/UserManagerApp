#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar botón "Entrar" con el slot correspondiente
    connect(ui->btnEntrar, &QPushButton::clicked,
            this, &::MainWindow::onbtnEntrarClicked);

    // Conexión a la base de datos
    if (!conectarBaseDeDatos()) {
        QMessageBox::critical(this, "Error",
                              "No se pudo conectar a la base de datos.");
    }

    // Mostrar solo la pestaña Login al inicio
    ui->tabWidget->setCurrentIndex(0);
    for (int i = 1; i < ui->tabWidget->count(); ++i)
        ui->tabWidget->setTabEnabled(i, false);
}

MainWindow::~MainWindow()
{
    if (db.isOpen())
        db.close();

    delete ui;
}

bool MainWindow::conectarBaseDeDatos()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");

    if (!db.open()) {
        qDebug() << "Error al abrir DB:" << db.lastError().text();
        return false;
    }

    return true;
}

RolUsuario MainWindow::obtenerRolUsuario(const QString &nombreUsuario)
{
    if (nombreUsuario.toLower() == "admin")
        return ADMIN_TOTAL;

    QSqlQuery query(db);
    query.prepare("SELECT puesto FROM usuario WHERE LOWER(nombre) = :nombre");
    query.bindValue(":nombre", nombreUsuario.toLower());

    if (!query.exec()) {
        qDebug() << "Error en consulta SQL:" << query.lastError().text();
        return ROL_INVALIDO;
    }

    if (query.next()) {
        QString puesto = query.value(0).toString().toLower();

        if (puesto == "admin_empresa")
            return ADMIN_EMPRESA;
        else if (puesto == "trabajador")
            return USUARIO_ESTANDAR;
    }

    return ROL_INVALIDO;
}

void MainWindow::onbtnEntrarClicked()
{
    QString nombre = ui->lineEditUsuario->text().trimmed();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Campo vacío",
                             "Introduce un nombre de usuario.");
        return;
    }

    RolUsuario rol = obtenerRolUsuario(nombre);
    if (rol == ROL_INVALIDO) {
        QMessageBox::critical(this, "Error",
                              QString("El usuario \"%1\" no existe.").arg(nombre));
        return;
    }

    mostrarPestanaSegunRol(rol);
}

void MainWindow::mostrarPestanaSegunRol(RolUsuario rol)
{
    int indice = 0;  // Por defecto login o error

    switch (rol) {
    case ADMIN_TOTAL:      indice = 1; break;  // Pestaña 1 = Admin Total
    case ADMIN_EMPRESA:    indice = 2; break;  // Pestaña 2 = Admin Empresa
    case USUARIO_ESTANDAR: indice = 3; break;  // Pestaña 3 = Usuario Estándar
    default:               indice = 0; break;  // Login o error
    }

    // Activar sólo la pestaña correspondiente, desactivar las demás
    for (int i = 1; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, i == indice);
    }

    ui->tabWidget->setCurrentIndex(indice);
}

