#include "dptoform.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_dptoform.h"

#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QMessageBox>

DptoForm::DptoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DptoForm)
{
    ui->setupUi(this);
    cargarDepartamentos();

}

DptoForm::~DptoForm()
{
    guardarDepartamentos();
    delete ui;
}

void DptoForm::cargarDepartamentos()
{
    ui->listWidget->clear();

    QSqlQuery query;
    if (!query.exec("SELECT nombre FROM departamentos ORDER BY nombre ASC")) {
        QMessageBox::warning(this, "Error BD", "Error al cargar departamentos: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString nombre = query.value(0).toString();
        ui->listWidget->addItem(nombre);
    }
}


void DptoForm::guardarDepartamentos()
{
    QFile file("departamentos.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << "\n";
    }

    file.close();
}

void DptoForm::on_btnCrear_clicked()
{
    bool ok;
    QString nombre = QInputDialog::getText(this, tr("Crear Departamento"),
                                           tr("Nombre del departamento:"), QLineEdit::Normal,
                                           "", &ok);
    if (ok && !nombre.isEmpty()) {
        // Verificar si ya existe
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM departamentos WHERE nombre = ?");
        checkQuery.addBindValue(nombre);
        if (!checkQuery.exec() || !checkQuery.next()) {
            QMessageBox::warning(this, "Error BD", "Error al verificar departamento: " + checkQuery.lastError().text());
            return;
        }
        if (checkQuery.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Duplicado", "Ya existe un departamento con ese nombre.");
            return;
        }

        // Insertar departamento
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO departamentos (nombre) VALUES (?)");
        insertQuery.addBindValue(nombre);
        if (!insertQuery.exec()) {
            QMessageBox::warning(this, "Error BD", "No se pudo crear departamento: " + insertQuery.lastError().text());
            return;
        }

        cargarDepartamentos();
        emit departamentoGuardado(nombre);
    }
}


void DptoForm::on_btnBorrar_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Selecciona", "Debes seleccionar un departamento.");
        return;
    }

    if (QMessageBox::question(this, "Borrar",
                              "¿Estás seguro de borrar el departamento '" + item->text() + "'?") == QMessageBox::Yes) {
        delete item;
    }
}

void DptoForm::on_btnEditar_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Selecciona", "Debes seleccionar un departamento.");
        return;
    }

    bool ok;
    QString nuevoNombre = QInputDialog::getText(this, tr("Editar Departamento"),
                                                tr("Nuevo nombre:"), QLineEdit::Normal,
                                                item->text(), &ok);
    if (ok && !nuevoNombre.isEmpty()) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *otro = ui->listWidget->item(i);
            if (otro != item && otro->text().compare(nuevoNombre, Qt::CaseInsensitive) == 0) {
                QMessageBox::warning(this, "Duplicado", "Ya existe un departamento con ese nombre.");
                return;
            }
        }
        item->setText(nuevoNombre);
    }
}

void DptoForm::on_btnAsignarUsr_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Selecciona", "Selecciona un departamento para asignar usuarios.");
        return;
    }

    QMessageBox::information(this, "Asignar Usuario", "Aquí abrirías la ventana para asignar usuarios al departamento: " + item->text());
    // Aquí podrías abrir tu ventana `Asignar`
}

