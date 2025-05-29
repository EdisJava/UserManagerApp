#include "admicompany.h"
#include "ui_admicompany.h"
#include "userform.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

admicompany::admicompany(const QString& empresa, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admicompany),
    empresaAdmin(empresa)

{


    ui->setupUi(this);

    loadUsers();
     qDebug() << "Empresa del admin:" << empresaAdmin;
}

admicompany::~admicompany()
{
    delete ui;
}

void admicompany::loadUsers()
{
    ui->listWidget->clear();

    QSqlQuery query;
    query.prepare("SELECT dni, nombre FROM usuarios WHERE empresa = :empresa ORDER BY nombre ASC");
    query.bindValue(":empresa", empresaAdmin);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Error al cargar usuarios: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString itemText = query.value(0).toString() + " - " + query.value(1).toString();
        ui->listWidget->addItem(itemText);
    }
}

void admicompany::on_btnCrear_clicked()
{
    UserForm form(this);
    form.setModoAdminEmpresa(true);  // Bloquea el campo empresa

    if (form.exec() == QDialog::Accepted) {
        QStringList datos = form.getUsuario();
        datos[5] = empresaAdmin;  // Forzar empresa asignada

        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO usuarios (dni, nombre, telefono, email, departamento, empresa, estado, foto, rol)
            VALUES (:dni, :nombre, :telefono, :email, :departamento, :empresa, :estado, :foto, :rol)
        )");

        query.bindValue(":dni", datos[0]);
        query.bindValue(":nombre", datos[1]);
        query.bindValue(":telefono", datos[2]);
        query.bindValue(":email", datos[3]);
        query.bindValue(":departamento", datos[4]);
        query.bindValue(":empresa", empresaAdmin);
        query.bindValue(":estado", datos[6]);
        query.bindValue(":foto", datos[7]);
        query.bindValue(":rol", datos[8]);

        if (!query.exec()) {
            QMessageBox::warning(this, "Error", "No se pudo crear el usuario: " + query.lastError().text());
            return;
        }

        loadUsers();
    }
}

void admicompany::on_btnEditar_clicked()
{
    auto currentItem = ui->listWidget->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Editar usuario", "Selecciona un usuario para editar.");
        return;
    }

    QString dni = currentItem->text().split(" - ").value(0);

    QSqlQuery query;
    query.prepare("SELECT dni, nombre, telefono, email, departamento, empresa, estado, foto, rol FROM usuarios WHERE dni = :dni");
    query.bindValue(":dni", dni);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Error", "No se encontró información del usuario.");
        return;
    }

    UserForm form(this);
    form.setDatosUsuario(
        query.value(0).toString(),
        query.value(1).toString(),
        query.value(2).toString(),
        query.value(3).toString(),
        query.value(4).toString(),
        query.value(5).toString(),
        query.value(6).toString(),
        query.value(7).toString(),
        query.value(8).toString()
        );
    form.setModoAdminEmpresa(true);  // Restringe el campo empresa

    if (form.exec() == QDialog::Accepted) {
        QStringList datos = form.getUsuario();

        QSqlQuery updateQuery;
        updateQuery.prepare(R"(
            UPDATE usuarios SET nombre = :nombre, telefono = :telefono, email = :email,
            departamento = :departamento, empresa = :empresa, estado = :estado, foto = :foto, rol = :rol
            WHERE dni = :dni
        )");

        updateQuery.bindValue(":nombre", datos[1]);
        updateQuery.bindValue(":telefono", datos[2]);
        updateQuery.bindValue(":email", datos[3]);
        updateQuery.bindValue(":departamento", datos[4]);
        updateQuery.bindValue(":empresa", empresaAdmin);
        updateQuery.bindValue(":estado", datos[6]);
        updateQuery.bindValue(":foto", datos[7]);
        updateQuery.bindValue(":rol", datos[8]);
        updateQuery.bindValue(":dni", datos[0]);

        if (!updateQuery.exec()) {
            QMessageBox::warning(this, "Error", "No se pudo actualizar el usuario: " + updateQuery.lastError().text());
            return;
        }

        loadUsers();
    }
}

void admicompany::on_btnBorrar_clicked()
{
    auto currentItem = ui->listWidget->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Eliminar usuario", "Selecciona un usuario para eliminar.");
        return;
    }

    QString texto = currentItem->text();
    QString dni = texto.split(" - ").value(0);

    if (QMessageBox::question(this, "Confirmar eliminación",
                              "¿Seguro que quieres eliminar al usuario '" + texto + "'?") == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM usuarios WHERE dni = :dni");
        query.bindValue(":dni", dni);

        if (!query.exec()) {
            QMessageBox::warning(this, "Error", "No se pudo eliminar el usuario: " + query.lastError().text());
            return;
        }

        loadUsers();
    }
}

