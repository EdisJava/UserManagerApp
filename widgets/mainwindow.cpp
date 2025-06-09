#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "EmpresaForm.h"
#include "DptoForm.h"
#include "userform.h"
#include "Users.h"
#include "Guess.h"
#include "mainadmi.h"
#include "DepartamentoDAO.h"
#include "database.h"
#include "admicompany.h"
#include "../Database/usuarioDAO.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QDebug>
#include <QVBoxLayout>
#include <QApplication>

// Constructor de la ventana principal
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    admiCompany(nullptr),
    empresaForm(nullptr),
    dptoForm(nullptr),
    userForm(nullptr),
    usersWindow(nullptr),
    guessForm(nullptr),
    mainAdmi(nullptr),
    departamentoDAO(new DepartamentoDAO)
{
    ui->setupUi(this);

    // Intentar abrir la base de datos
    if (!database::open()) {
        QMessageBox::critical(this, tr("Error"), tr("No se pudo conectar a la base de datos."));
        qApp->quit();
        return;
    }

    // Solo habilita la pestaña de login al inicio
    if (ui->tabWidget) {
        for (int i = 1; i < ui->tabWidget->count(); ++i)
            ui->tabWidget->setTabEnabled(i, false);
        ui->tabWidget->setCurrentIndex(0);
    }

    // Conectar botón de entrar con su handler
    connect(ui->btnEntrar, &QPushButton::clicked, this, &MainWindow::on_btnEntrar_clicked);
}

// Destructor de la ventana principal
MainWindow::~MainWindow()
{
    // Liberar memoria de los formularios abiertos
    delete empresaForm;
    delete dptoForm;
    delete userForm;
    delete usersWindow;
    delete guessForm;
    delete mainAdmi;
    delete admiCompany;
    delete departamentoDAO;
    delete ui;

    // Cerrar conexión a base de datos
    database::close();
}

// Método llamado al hacer clic en el botón "Entrar"
void MainWindow::on_btnEntrar_clicked()
{
    QString usuario = ui->lineEditUsuario->text().trimmed();

    // Validación básica: campo vacío
    if (usuario.isEmpty()) {
        mostrarMensaje("Por favor, introduzca un nombre de usuario.");
        return;
    }

    // Asegurar que la BD esté abierta
    QSqlDatabase &db = database::get();
    if (!db.isOpen() && !database::open()) {
        mostrarMensaje("Error al abrir la base de datos.");
        return;
    }

    // Caso especial para el usuario "admin" global
    if (usuario.toLower() == "admin") {
        if (!mainAdmi) {
            mainAdmi = new MainAdmi(this);
            QWidget *tabAdmin = ui->tabWidget->widget(1);
            if (tabAdmin->layout()) {
                tabAdmin->layout()->addWidget(mainAdmi);
            } else {
                QVBoxLayout *layout = new QVBoxLayout(tabAdmin);
                layout->addWidget(mainAdmi);
                tabAdmin->setLayout(layout);
            }
        }

        // Deshabilitar otras pestañas, mostrar la de admin
        for (int i = 0; i < ui->tabWidget->count(); ++i)
            ui->tabWidget->setTabEnabled(i, false);

        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setCurrentIndex(1);

        mostrarMensaje("Bienvenido administrador total.");
        ui->lineEditUsuario->clear();
        return;
    }

    // Consultar rol y estado del usuario desde la base de datos
    QSqlQuery query(db);
    query.prepare("SELECT rol, estado FROM usuarios WHERE nombre = ?");
    query.bindValue(0, usuario);

    if (!query.exec() || !query.next()) {
        mostrarMensaje("Usuario no encontrado.");
        return;
    }

    QString rol = query.value(0).toString().toLower();
    QString estado = query.value(1).toString().toLower();

    if (estado != "activo") {
        mostrarMensaje("Usuario inactivo. No puede iniciar sesión.");
        return;
    }

    // Obtener todos los datos del usuario
    QSqlQuery queryDatos(db);
    queryDatos.prepare("SELECT dni, nombre, telefono, email, departamento, empresa, estado, rol, foto FROM usuarios WHERE nombre = ?");
    queryDatos.bindValue(0, usuario);

    if (!queryDatos.exec() || !queryDatos.next()) {
        mostrarMensaje("Error al cargar datos del usuario.");
        return;
    }

    // Validar DNI antes de continuar
    QString dni = queryDatos.value("dni").toString();
    if (!validarDNI(dni)) {
        mostrarMensaje("El DNI del usuario no es válido.");
        return;
    }

    // Cargar el resto de los datos
    QString nombre = queryDatos.value("nombre").toString();
    QString telefono = queryDatos.value("telefono").toString();
    QString email = queryDatos.value("email").toString();
    QString departamento = queryDatos.value("departamento").toString();
    QString empresa = queryDatos.value("empresa").toString();
    empresaDelAdminEmpresa = empresa;
    QString estadoUsr = queryDatos.value("estado").toString();
    QString rolUsr = queryDatos.value("rol").toString();

    QPixmap foto;
    auto fotoData = queryDatos.value("foto").toString();
    if (!fotoData.isEmpty())
        foto.load(fotoData);

    // Construir mapa de datos del usuario
    QVariantMap usuarioData;
    usuarioData["dni"] = dni;
    usuarioData["nombre"] = nombre;
    usuarioData["telefono"] = telefono;
    usuarioData["email"] = email;
    usuarioData["departamento"] = departamento;
    usuarioData["empresa"] = empresa;
    usuarioData["estado"] = estadoUsr;
    usuarioData["rol"] = rolUsr;
    usuarioData["foto"] = foto;

    // Determinar qué tipo de formulario mostrar según el rol
    if (rol == "admin") {
        if (!userForm) {
            userForm = new UserForm(&usuarioDAO, this);
            QWidget *tabAdmin = ui->tabWidget->widget(1);
            QLayout *layout = tabAdmin->layout();
            if (!layout) {
                layout = new QVBoxLayout(tabAdmin);
                tabAdmin->setLayout(layout);
            }
            if (layout->indexOf(userForm) == -1) {
                layout->addWidget(userForm);
            }
        }

        // Validar visualmente el DNI (campo rojo si es inválido)
        userForm->validarVisualmenteDNI(dni);

        // Mostrar pestaña correspondiente
        for (int i = 0; i < ui->tabWidget->count(); ++i)
            ui->tabWidget->setTabEnabled(i, false);

        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setCurrentIndex(1);

        ui->lineEditUsuario->clear();
        return;
    }
    else if (rol == "adminempresa") {
        QWidget *tabAdminEmp = ui->tabWidget->widget(2);

        if (!admiCompany) {
            admiCompany = new AdmiCompany(this);
            if (tabAdminEmp->layout()) {
                tabAdminEmp->layout()->addWidget(admiCompany);
            } else {
                QVBoxLayout *layout = new QVBoxLayout(tabAdminEmp);
                layout->addWidget(admiCompany);
                tabAdminEmp->setLayout(layout);
            }

            // Conexión de señal para gestión de usuarios
            connect(admiCompany, &AdmiCompany::gestionarUsuariosSolicitado, this, &MainWindow::abrirGestionUsuarios);
        }

        // Mostrar pestaña de admin de empresa
        admiCompany->show();
        for (int i = 0; i < ui->tabWidget->count(); ++i)
            ui->tabWidget->setTabEnabled(i, false);
        ui->tabWidget->setTabEnabled(2, true);
        ui->tabWidget->setCurrentIndex(2);

        ui->lineEditUsuario->clear();
    }
    else if (rol == "usuario") {
        if (!guessForm) {
            guessForm = new Guess(this);
            QWidget *tabUsuario = ui->tabWidget->widget(3);
            if (tabUsuario->layout()) {
                tabUsuario->layout()->addWidget(guessForm);
            } else {
                QVBoxLayout *layout = new QVBoxLayout(tabUsuario);
                layout->addWidget(guessForm);
                tabUsuario->setLayout(layout);
            }
        }

        // Mostrar formulario del usuario estándar
        guessForm->mostrarDatos(dni, nombre, telefono, email, departamento, empresa, estadoUsr, rolUsr, foto);

        for (int i = 0; i < ui->tabWidget->count(); ++i)
            ui->tabWidget->setTabEnabled(i, false);
        ui->tabWidget->setTabEnabled(3, true);
        ui->tabWidget->setCurrentIndex(3);
        guessForm->show();
    }
    else {
        // Rol no reconocido
        mostrarMensaje("Rol no válido.");
        return;
    }

    // Una vez logueado, ocultar pestaña de login
    ui->tabWidget->setTabEnabled(0, false);
    ui->lineEditUsuario->clear();
}

// Mostrar un mensaje en la barra de estado durante 5 segundos
void MainWindow::mostrarMensaje(const QString &mensaje)
{
    if (statusBar())
        statusBar()->showMessage(mensaje, 5000);
}

// Abre el formulario de gestión de empresas
void MainWindow::abrirGestionEmpresas()
{
    if (!empresaForm)
        empresaForm = new EmpresaForm(this);

    empresaForm->setModal(true);
    empresaForm->show();
    empresaForm->raise();
    empresaForm->activateWindow();
}

// Abre el formulario de gestión de departamentos
void MainWindow::abrirGestionDepartamentos()
{
    if (!dptoForm)
        dptoForm = new DptoForm(departamentoDAO, this);

    dptoForm->setModal(true);
    dptoForm->show();
    dptoForm->raise();
    dptoForm->activateWindow();
}

// Abre el formulario de gestión de usuarios
void MainWindow::abrirGestionUsuarios()
{
    if (!usersWindow) {
        usersWindow = new Users(this);
        usersWindow->setWindowModality(Qt::ApplicationModal);
    }

    usersWindow->setEmpresaFiltro(empresaDelAdminEmpresa); // Usa la empresa del admin empresa
    usersWindow->show();
    usersWindow->raise();
    usersWindow->activateWindow();
}

// Acción del menú para salir de la aplicación
void MainWindow::on_actionSalir_triggered()
{
    qApp->quit();
}

// Acción del menú "Acerca de"
void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this, tr("Acerca de"), tr("Aplicación de ejemplo\nDesarrollada con Qt."));
}

// Función para validar que un DNI sea correcto
bool MainWindow::validarDNI(const QString &dni)
{
    if (dni.length() != 9)
        return false;

    QString numeros = dni.left(8);
    QChar letra = dni.at(8).toUpper();

    bool ok;
    int num = numeros.toInt(&ok);
    if (!ok)
        return false;

    static const QString letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    int pos = num % 23;

    return letra == letras.at(pos);
}
