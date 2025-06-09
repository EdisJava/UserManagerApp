#include "EmpresaForm.h"
#include "ui_EmpresaForm.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QHeaderView>

EmpresaForm::EmpresaForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmpresaForm)
{
    ui->setupUi(this);

    // Configurar tableView solo 1 vez
    ui->tableViewEmpresas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewEmpresas->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewEmpresas->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewEmpresas->horizontalHeader()->setStretchLastSection(true);

    cargarEmpresas();
}

EmpresaForm::~EmpresaForm()
{
    delete ui;
}

void EmpresaForm::cargarEmpresas()
{
    listaEmpresas = dao.listarEmpresas();

    // Eliminar modelo anterior si existe para evitar fugas y conflictos
    QAbstractItemModel *modeloAnterior = ui->tableViewEmpresas->model();
    if (modeloAnterior) {
        delete modeloAnterior;
        ui->tableViewEmpresas->setModel(nullptr);
    }

    int filas = listaEmpresas.size();

    QStandardItemModel *model = new QStandardItemModel(filas, 1, this);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));

    for (int row = 0; row < filas; ++row) {
        QVariantMap empresa = listaEmpresas.at(row);
        QString nombre = empresa.value("nombre").toString();
        QStandardItem *itemNombre = new QStandardItem(nombre);
        model->setItem(row, 0, itemNombre);
    }

    ui->tableViewEmpresas->setModel(model);
    ui->tableViewEmpresas->resizeColumnsToContents();
    ui->tableViewEmpresas->horizontalHeader()->setStretchLastSection(true);
}

void EmpresaForm::limpiarFormulario()
{
    ui->lineEditNombre->clear();
    ui->tableViewEmpresas->clearSelection();
}

void EmpresaForm::on_btnCrear_clicked()
{
    QString nombre = ui->lineEditNombre->text().trimmed();
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("El nombre no puede estar vacío"));
        return;
    }

    QVariantMap empresa;
    empresa["nombre"] = nombre;

    QString errorMsg;
    if (!dao.insertarEmpresa(empresa, errorMsg)) {
        QMessageBox::critical(this, tr("Error al crear"), errorMsg);
        return;
    }

    cargarEmpresas();
    limpiarFormulario();
}

void EmpresaForm::on_btnEditar_clicked()
{
    QModelIndexList seleccion = ui->tableViewEmpresas->selectionModel()->selectedRows();
    if (seleccion.count() != 1) {
        QMessageBox::warning(this, tr("Editar Empresa"), tr("Seleccione una empresa para editar"));
        return;
    }

    int fila = seleccion.at(0).row();

    if (fila < 0 || fila >= listaEmpresas.size()) {
        QMessageBox::critical(this, tr("Error"), tr("Selección inválida"));
        return;
    }

    QVariantMap empresa = listaEmpresas.at(fila);
    QString nuevoNombre = ui->lineEditNombre->text().trimmed();

    if (nuevoNombre.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("El nombre no puede estar vacío"));
        return;
    }

    empresa["nombre"] = nuevoNombre;

    QString errorMsg;
    if (!dao.actualizarEmpresa(empresa, errorMsg)) {
        QMessageBox::critical(this, tr("Error al editar"), errorMsg);
        return;
    }

    cargarEmpresas();
    limpiarFormulario();
}

void EmpresaForm::on_btnBorrar_clicked()
{
    QModelIndexList seleccion = ui->tableViewEmpresas->selectionModel()->selectedRows();
    if (seleccion.count() != 1) {
        QMessageBox::warning(this, tr("Borrar Empresa"), tr("Seleccione una empresa para borrar"));
        return;
    }

    int fila = seleccion.at(0).row();

    if (fila < 0 || fila >= listaEmpresas.size()) {
        QMessageBox::critical(this, tr("Error"), tr("Selección inválida"));
        return;
    }

    int id = listaEmpresas.at(fila).value("id").toInt();

    QString errorMsg;
    if (!dao.eliminarEmpresa(id, errorMsg)) {
        QMessageBox::critical(this, tr("Error al borrar"), errorMsg);
        return;
    }

    cargarEmpresas();
    limpiarFormulario();
}
