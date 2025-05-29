#include "mainadmi.h"
#include "ui_MainAdmi.h"
#include <QMessageBox>

#include "empresaForm.h"
#include "dptoform.h"
#include "userform.h"
#include "users.h"

#include <QDebug>

MainAdmi::MainAdmi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAdmi)
{
    ui->setupUi(this);

    connect(ui->btnEmpresas, &QPushButton::clicked, this, &MainAdmi::on_btnEmpresas_clicked);
    connect(ui->btnDepartamentos, &QPushButton::clicked, this, &MainAdmi::on_btnDepartamentos_clicked);
    connect(ui->btnUsuarios, &QPushButton::clicked, this, &MainAdmi::on_btnUsuarios_clicked);
}

MainAdmi::~MainAdmi()
{
    delete ui;
}

void MainAdmi::on_btnEmpresas_clicked()
{
    EmpresaForm *form = new EmpresaForm(this);
    connect(form, &EmpresaForm::empresaGuardada, this, [](const QString &nombre){
        QMessageBox::information(nullptr, "Éxito", "Empresa guardada: " + nombre);
    });
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}

void MainAdmi::on_btnDepartamentos_clicked()
{
    DptoForm *form = new DptoForm(this);
    connect(form, &DptoForm::departamentoGuardado, this, [](const QString &nombre){
        QMessageBox::information(nullptr, "Éxito", "Departamento guardado: " + nombre);
    });
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}

void MainAdmi::on_btnUsuarios_clicked()
{
    if (!usersWidget) {
        usersWidget = new Users(this);
        usersWidget->setAttribute(Qt::WA_DeleteOnClose);
        connect(usersWidget, &QObject::destroyed, this, [this]() {
            usersWidget = nullptr;
        });
    }
    usersWidget->show();
    usersWidget->raise();
    usersWidget->activateWindow();
}


