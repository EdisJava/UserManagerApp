#include "users.h"
#include "ui_users.h"
#include "userform.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
    // Inicialmente sin usuario logueado
    usuarioActualDni.clear();
    usuarioActualRol.clear();
    usuarioActualEmpresa.clear();

    loadUsers();

    connect(ui->listWidget, &QListWidget::currentItemChanged,
            this, &Users::mostrarFotoUsuario);
}

Users::~Users()
{
    delete ui;
}

void Users::setUsuarioActual(const QString &dni, const QString &rol, const QString &empresa)
{
    usuarioActualDni = dni;
    usuarioActualRol = rol;
    usuarioActualEmpresa = empresa;

    // Si es admin de empresa, filtra por la empresa del usuario
    if (usuarioActualRol == "admin_empresa") {
        setEmpresaFiltro(usuarioActualEmpresa);
    } else {
        setEmpresaFiltro(QString()); // Sin filtro
    }
}

void Users::loadUsers()
{
    ui->listWidget->clear();

    QSqlQuery query;
    if (empresaFiltro.isEmpty()) {
        query.prepare("SELECT dni, nombre FROM usuarios ORDER BY nombre ASC");
    } else {
        query.prepare("SELECT dni, nombre FROM usuarios WHERE empresa = :empresa ORDER BY nombre ASC");
        query.bindValue(":empresa", empresaFiltro);
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Error al cargar usuarios: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString itemText = query.value(0).toString() + " - " + query.value(1).toString();
        ui->listWidget->addItem(itemText);
    }

    query.finish();
}

void Users::on_btnNuevoUsuario_clicked()
{
    UserForm *form = new UserForm(this);

    // Pasar modo admin_empresa si aplica
    form->setModoAdminEmpresa(usuarioActualRol == "admin_empresa");

    connect(form, &UserForm::usuarioGuardado, this, &Users::loadUsers);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void Users::on_btnAddUser_clicked()
{
    UserForm *form = new UserForm(this);

    form->setModoAdminEmpresa(usuarioActualRol == "admin_empresa");

    connect(form, &UserForm::usuarioGuardado, this, &Users::loadUsers);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void Users::on_btnEditUser_clicked()
{
    auto currentItem = ui->listWidget->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Editar usuario", "Selecciona un usuario para editar.");
        return;
    }

    QString dni = currentItem->text().split(" - ").at(0);

    QSqlQuery query;
    query.prepare("SELECT dni, nombre, telefono, email, departamento, empresa, estado, foto, rol FROM usuarios WHERE dni = :dni");
    query.bindValue(":dni", dni);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Error", "No se encontró información del usuario.");
        return;
    }

    UserForm *form = new UserForm(this);

    form->setDatosUsuario(
        query.value(0).toString(),  // dni
        query.value(1).toString(),  // nombre
        query.value(2).toString(),  // telefono
        query.value(3).toString(),  // email
        query.value(4).toString(),  // departamento
        query.value(5).toString(),  // empresa
        query.value(6).toString(),  // estado
        query.value(7).toString(),  // foto
        query.value(8).toString()   // rol
        );

    // Indicar si está en modo admin_empresa para desactivar cambio empresa
    form->setModoAdminEmpresa(usuarioActualRol == "admin_empresa");

    connect(form, &UserForm::usuarioGuardado, this, &Users::loadUsers);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->exec();
}

void Users::on_btnDeleteUser_clicked()
{
    auto currentItem = ui->listWidget->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Eliminar usuario", "Selecciona un usuario para eliminar.");
        return;
    }

    QString texto = currentItem->text();
    QString dni = texto.split(" - ").at(0);

    if (QMessageBox::question(this, "Confirmar eliminación",
                              "¿Seguro que quieres eliminar al usuario '" + texto + "'?") == QMessageBox::Yes) {

        QSqlQuery query;
        query.prepare("DELETE FROM usuarios WHERE dni = :dni");
        query.bindValue(":dni", dni);

        if (!query.exec()) {
            QMessageBox::warning(this, "Error", "No se pudo eliminar el usuario: " + query.lastError().text());
            return;
        }

        query.finish();
        loadUsers();
    }
}

void Users::mostrarFotoUsuario(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(previous);

    if (!current) {
        ui->labelFoto->clear();
        return;
    }

    QString dni = current->text().split(" - ").at(0);

    QSqlQuery query;
    query.prepare("SELECT foto FROM usuarios WHERE dni = :dni");
    query.bindValue(":dni", dni);

    if (!query.exec() || !query.next()) {
        ui->labelFoto->clear();
        return;
    }

    QString rutaFoto = query.value(0).toString();

    if (rutaFoto.isEmpty()) {
        ui->labelFoto->clear();
        return;
    }

    QPixmap pixmap(rutaFoto);
    if (pixmap.isNull()) {
        ui->labelFoto->setText("Imagen no válida");
        return;
    }

    ui->labelFoto->setPixmap(pixmap.scaled(ui->labelFoto->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Users::setEmpresaFiltro(const QString &empresa)
{
    this->empresaFiltro = empresa;
    loadUsers();
}

void Users::cargarUsuarios()
{
    // Esto parece duplicado, lo reemplaza loadUsers con filtro.
    // Puedes eliminar esta función si no la usas.
}
