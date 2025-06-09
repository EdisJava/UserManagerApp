#include "MainAdmi.h"
#include "ui_MainAdmi.h"

MainAdmi::MainAdmi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAdmi),
    users(nullptr),
    empresaForm(nullptr),
    dptoForm(nullptr),
    departamentoDAO()  // <-- inicializas el atributo, no la clase
{
    ui->setupUi(this);

    connect(ui->btnGestionUsuarios, &QPushButton::clicked, this, &MainAdmi::abrirGestionUsuarios);
    connect(ui->btnGestionEmpresas, &QPushButton::clicked, this, &MainAdmi::abrirGestionEmpresas);
    connect(ui->btnGestionDepartamentos, &QPushButton::clicked, this, &MainAdmi::abrirGestionDepartamentos);
}

MainAdmi::~MainAdmi()
{
    delete users;
    delete empresaForm;
    delete dptoForm;
    delete ui;
}

void MainAdmi::abrirGestionUsuarios()
{
    if (!users) {
        users = new Users(this);  // 'this' es un QWidget*
    }
    users->show();
    users->raise();
    users->activateWindow();
}

void MainAdmi::abrirGestionEmpresas()
{
    if (!empresaForm) {
        empresaForm = new EmpresaForm(this);
    }
    empresaForm->show();
    empresaForm->raise();
    empresaForm->activateWindow();
}

void MainAdmi::abrirGestionDepartamentos()
{
    if (!dptoForm) {
        dptoForm = new DptoForm(&departamentoDAO, this);

    }
    dptoForm->show();
    dptoForm->raise();
    dptoForm->activateWindow();
}
