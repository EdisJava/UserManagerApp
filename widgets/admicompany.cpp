#include "AdmiCompany.h"
#include "ui_AdmiCompany.h"
#include "../Database/usuarioDAO.h"

AdmiCompany::AdmiCompany(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdmiCompany)
{
    ui->setupUi(this);

    connect(ui->btnGestionDepartamentos, &QPushButton::clicked,
            this, &AdmiCompany::on_btnGestionDepartamentos_clicked);
    connect(ui->btnGestionUsuarios, &QPushButton::clicked, this, &AdmiCompany::gestionarUsuariosSolicitado);

}

AdmiCompany::~AdmiCompany()
{
    delete ui;
}

void AdmiCompany::on_btnGestionDepartamentos_clicked()
{
    emit gestionarDepartamentos();
    if (!dptoForm) {
        dptoForm = new DptoForm(&departamentoDAO, this);
    }
    dptoForm->show();
    dptoForm->raise();
    dptoForm->activateWindow();
}
void AdmiCompany::setEmpresaActual(const QString &empresa)
{
    m_empresaActual = empresa;
}

QString AdmiCompany::empresaActual() const
{
    return m_empresaActual;
}

// void AdmiCompany::on_btnGestionUsuarios_clicked()
// {
//     emit gestionarUsuarios();
//     if (!userForm) {
//         userForm = new UserForm(&usuarioDAO, this);
//     }
//     userForm->show();
//     userForm->raise();
//     userForm->activateWindow();
// }
