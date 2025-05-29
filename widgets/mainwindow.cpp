#include "mainwindow.h"
#include "empresaform.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "ui_mainadmi.h"
#include "admicompany.h"  // Incluye aquí la cabecera de AdminCompany
#include <QVBoxLayout>
#include <QSqlDatabase>
#include "guess.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),

    guessWidget(new Guess(this)),
    empresaWindow(nullptr),
    dptoWindow(nullptr),
    Userwindow(nullptr),
    adminCompanyWidget(nullptr)
{
    ui->setupUi(this);

    db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "La base de datos no está abierta.");
        return;
    }

    // Configurar AdminTotal UI en la pestaña 1 (ya hecho)
    QWidget *adminTotalWidget = new QWidget(ui->tabWidget->widget(1));
    adminTotalFormUi = new Ui::MainAdmi();
    adminTotalFormUi->setupUi(adminTotalWidget);
    QVBoxLayout *layout1 = new QVBoxLayout(ui->tabWidget->widget(1));
    layout1->addWidget(adminTotalWidget);
    ui->tabWidget->widget(1)->setLayout(layout1);

    QWidget *tab3 = ui->tabWidget->widget(3);
    QVBoxLayout *layout3 = new QVBoxLayout(tab3);
    layout3->addWidget(guessWidget);
    tab3->setLayout(layout3);

    // Ahora agrega admicompany embebido en la pestaña 2
 // padre es el widget de la pestaña 2
 /*   QVBoxLayout *layout2 = new QVBoxLayout(ui->tabWidget->widget(2));
    layout2->addWidget(adminCompanyWidget);
    ui->tabWidget->widget(2)->setLayout(layout2);*/

    // Deshabilitar todas las pestañas excepto login inicialmente
    for (int i = 1; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, false);
    }
    ui->tabWidget->setCurrentIndex(0);

    // Conexiones botón Entrar y demás
    connect(ui->btnEntrar, &QPushButton::clicked, this, &MainWindow::onbtnEntrarClicked);

    connect(adminTotalFormUi->btnDepartamentos, &QPushButton::clicked, this, &MainWindow::onBtnAdminDepartamentosClicked);
    connect(adminTotalFormUi->btnEmpresas, &QPushButton::clicked, this, &MainWindow::onBtnAdminEmpresaClicked);
    connect(adminTotalFormUi->btnUsuarios, &QPushButton::clicked, this, &MainWindow::onBtnAdminTrabajadoresClicked);
}

MainWindow::~MainWindow()
{
    if (db.isOpen())
        db.close();

    delete ui;
}

RolUsuario MainWindow::obtenerRolUsuario(const QString &nombreUsuario)
{
    if (nombreUsuario.toLower() == "admin") {
        return ADMIN_TOTAL;  // usuario especial hardcodeado
    }

    QSqlQuery query(db);
    query.prepare("SELECT rol, empresa, estado FROM usuarios WHERE LOWER(nombre) = :nombre");
    query.bindValue(":nombre", nombreUsuario.toLower());

    if (!query.exec()) {
        qDebug() << "Error en la consulta de rol:" << query.lastError().text();
        return ROL_INVALIDO;
    }

    if (query.next()) {
        QString rol = query.value(0).toString().toLower();
        empresaAdmin = query.value(1).toString();
        QString estado = query.value(2).toString().toLower();

        // Verificar si está inactivo o suspendido
        if (estado == "inactivo" || estado == "suspendido") {
            QMessageBox::warning(nullptr, "Acceso denegado", "Tu cuenta está " + estado + ". No puedes acceder al sistema.");
            return ROL_INVALIDO;
        }

        if (rol == "admintotal") return ADMIN_TOTAL;
        else if (rol == "adminempresa") return ADMIN_EMPRESA;
        else if (rol == "usuario") return USUARIO_ESTANDAR;
    }

    return ROL_INVALIDO;
}


void MainWindow::onbtnEntrarClicked()
{
    QString nombre = ui->lineEditUsuario->text().trimmed();
    qDebug() << "Botón Entrar pulsado. Usuario:" << nombre;

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Campo vacío", "Introduce un nombre de usuario.");
        return;
    }
    nombreUsuario = ui->lineEditUsuario->text().trimmed();
    ResultadoValidacion resultado = validarUsuario(nombre);

    switch (resultado.estado) {
    case NO_EXISTE:
        QMessageBox::critical(this, "Error", QString("El usuario \"%1\" no existe.").arg(nombre));
        return;

    case INACTIVO_O_SUSPENDIDO:
        QMessageBox::warning(this, "Acceso denegado", "Tu cuenta está inactiva o suspendida. Contacta con un administrador.");
        return;

    case EXISTE_Y_VALIDO:
        mostrarPestanaSegunRol(resultado.rol);
        return;
    }
}


void MainWindow::mostrarPestanaSegunRol(RolUsuario rol)
{
    int indice = 0;
    QString titulo;

    switch (rol) {
    case ADMIN_TOTAL:
        indice = 1;
        titulo = QString("Bienvenido, %1 (Administrador Total)").arg(nombreUsuario);
        break;

    case ADMIN_EMPRESA:
        indice = 2;

        if (!adminCompanyWidget) {
            adminCompanyWidget = new admicompany(empresaAdmin, this);

            QVBoxLayout *layout2 = new QVBoxLayout(ui->tabWidget->widget(2));
            layout2->addWidget(adminCompanyWidget);
            ui->tabWidget->widget(2)->setLayout(layout2);
        }

        titulo = QString("Bienvenido, %1 (Admin de %2)").arg(nombreUsuario, empresaAdmin);
        break;

    case USUARIO_ESTANDAR:
        indice = 3;
        titulo = QString("Bienvenido, %1 (Usuario)").arg(nombreUsuario);

        if (guessWidget) {
            guessWidget->cargarDatosUsuario(nombreUsuario);  // <-- Aquí
        }

        break;

    default:
        indice = 0;
        break;
    }

    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        ui->tabWidget->setTabEnabled(i, i == indice);
    }

    ui->tabWidget->setCurrentIndex(indice);
    this->setWindowTitle(titulo);  // <- Actualiza el título con los datos
}


// Slots para los botones, cada uno con su código

void MainWindow::onBtnAdminEmpresaClicked()
{
    if (!empresaWindow) {
        empresaWindow = new EmpresaForm(this);
    }
    empresaWindow->show();
    empresaWindow->raise();
    empresaWindow->activateWindow();
}

void MainWindow::onBtnAdminDepartamentosClicked()
{
    if (!dptoWindow) {
        dptoWindow = new DptoForm(this);
    }
    dptoWindow->show();
    dptoWindow->raise();
    dptoWindow->activateWindow();
}

void MainWindow::onBtnAdminTrabajadoresClicked()
{
    if (!Userwindow) {
        Userwindow = new Users(this);
    }
    Userwindow->show();
    Userwindow->raise();
    Userwindow->activateWindow();
}

// Ejemplo para botón de AdminCompany si quieres mostrar ventana:

void MainWindow::onBtnAdminCompanyClicked()
{
    if (!adminCompanyWidget) {
        adminCompanyWidget = new admicompany(empresaAdmin, this);  // <-- Aquí la corrección
    }
    adminCompanyWidget->show();
    adminCompanyWidget->raise();
    adminCompanyWidget->activateWindow();
}

ResultadoValidacion MainWindow::validarUsuario(const QString &nombreUsuario)
{
    ResultadoValidacion resultado;
    resultado.rol = ROL_INVALIDO;

    if (nombreUsuario.toLower() == "admin") {
        resultado.estado = EXISTE_Y_VALIDO;
        resultado.rol = ADMIN_TOTAL;
        return resultado;
    }

    QSqlQuery query(db);
    query.prepare("SELECT rol, empresa, estado FROM usuarios WHERE LOWER(nombre) = :nombre");
    query.bindValue(":nombre", nombreUsuario.toLower());

    if (!query.exec()) {
        qDebug() << "Error en la consulta de rol:" << query.lastError().text();
        resultado.estado = NO_EXISTE;
        return resultado;
    }

    if (query.next()) {
        QString rol = query.value(0).toString().toLower();
        empresaAdmin = query.value(1).toString();
        QString estado = query.value(2).toString().toLower();

        if (estado == "inactivo" || estado == "suspendido") {
            resultado.estado = INACTIVO_O_SUSPENDIDO;
            return resultado;
        }

        resultado.estado = EXISTE_Y_VALIDO;
        if (rol == "admintotal") resultado.rol = ADMIN_TOTAL;
        else if (rol == "adminempresa") resultado.rol = ADMIN_EMPRESA;
        else if (rol == "usuario") resultado.rol = USUARIO_ESTANDAR;

        return resultado;
    }

    resultado.estado = NO_EXISTE;
    return resultado;
}
