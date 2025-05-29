#include "empresaform.h"
#include "ui_empresaform.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

EmpresaForm::EmpresaForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmpresaForm)
{
    ui->setupUi(this);

    // Crear ruta segura donde guardar archivo
    QString base = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(base);
    if (!dir.exists()) dir.mkpath(".");

    rutaArchivo = base + "/empresas.txt";

    cargarLista();

    connect(ui->Crear, &QPushButton::clicked, this, &EmpresaForm::onCrearClicked);
    connect(ui->Borrar, &QPushButton::clicked, this, &EmpresaForm::onBorrarClicked);
    connect(ui->Editar, &QPushButton::clicked, this, &EmpresaForm::onEditarClicked);
    connect(ui->NuevoDept, &QPushButton::clicked, this, &EmpresaForm::onDeptClicked);
}

EmpresaForm::~EmpresaForm()
{
    delete ui;
}


void EmpresaForm::cargarLista()
{
    ui->listWidget->clear();

    QSqlQuery query;
    if (!query.exec("SELECT nombre FROM empresas ORDER BY nombre ASC")) {
        QMessageBox::warning(this, "Error BD", "Error al cargar empresas: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString nombre = query.value(0).toString();
        ui->listWidget->addItem(nombre);
    }
}
void EmpresaForm::guardarLista()
{
    QFile file(rutaArchivo);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo de empresas.");
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << "\n";
    }

    file.close();
}

void EmpresaForm::onCrearClicked()
{
    bool ok;
    QString nombre = QInputDialog::getText(this, tr("Crear Empresa"),
                                           tr("Nombre de la empresa:"), QLineEdit::Normal,
                                           "", &ok);
    if (ok && !nombre.isEmpty()) {
        // Verificar si ya existe
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM empresas WHERE nombre = ?");
        checkQuery.addBindValue(nombre);
        if (!checkQuery.exec() || !checkQuery.next()) {
            QMessageBox::warning(this, "Error BD", "Error al verificar empresa: " + checkQuery.lastError().text());
            return;
        }
        if (checkQuery.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Empresa duplicada", "Ya existe una empresa con ese nombre.");
            return;
        }

        // Insertar empresa
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO empresas (nombre) VALUES (?)");
        insertQuery.addBindValue(nombre);
        if (!insertQuery.exec()) {
            QMessageBox::warning(this, "Error BD", "No se pudo crear empresa: " + insertQuery.lastError().text());
            return;
        }

        cargarLista();
        QMessageBox::information(this, "Empresa creada", "Empresa '" + nombre + "' creada correctamente.");
    }
}


void EmpresaForm::onBorrarClicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Seleccionar empresa", "Debes seleccionar una empresa para borrar.");
        return;
    }

    QString nombre = item->text();

    if (QMessageBox::question(this, "Confirmar borrado",
                              "¿Seguro que quieres borrar la empresa '" + nombre + "'?") == QMessageBox::Yes) {
        delete item;
        guardarLista();
        QMessageBox::information(this, "Empresa borrada", "Empresa '" + nombre + "' borrada correctamente.");
    }
}

void EmpresaForm::onEditarClicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Seleccionar empresa", "Debes seleccionar una empresa para editar.");
        return;
    }

    bool ok;
    QString nombreActual = item->text();
    QString nombreNuevo = QInputDialog::getText(this, tr("Editar Empresa"),
                                                tr("Nuevo nombre:"), QLineEdit::Normal,
                                                nombreActual, &ok);
    if (ok && !nombreNuevo.isEmpty()) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *otherItem = ui->listWidget->item(i);
            if (otherItem != item && otherItem->text().compare(nombreNuevo, Qt::CaseInsensitive) == 0) {
                QMessageBox::warning(this, "Nombre duplicado", "Ya existe una empresa con ese nombre.");
                return;
            }
        }

        item->setText(nombreNuevo);
        guardarLista();
        QMessageBox::information(this, "Empresa editada", "Empresa renombrada correctamente.");
    }
}

void EmpresaForm::onDeptClicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Seleccionar empresa", "Debes seleccionar una empresa para añadir departamento.");
        return;
    }

    bool ok;
    QString departamento = QInputDialog::getText(this, tr("Agregar Departamento"),
                                                 tr("Nombre del departamento:"), QLineEdit::Normal,
                                                 "", &ok);
    if (ok && !departamento.isEmpty()) {
        QMessageBox::information(this, "Departamento añadido",
                                 "Departamento '" + departamento + "' añadido a la empresa '" + item->text() + "'.");
    }
}
