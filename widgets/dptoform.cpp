#include "dptoform.h"
#include "ui_dptoform.h"
#include <QMessageBox>
#include <QStandardItem>

DptoForm::DptoForm(DepartamentoDAO *dao, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::DptoForm),
    model(new QStandardItemModel(this)),
    dao(dao),
    idDepartamentoSeleccionado(-1)
{
    ui->setupUi(this);

    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nombre");

    ui->tableViewDepartamentos->setModel(model);
    ui->tableViewDepartamentos->hideColumn(0); // ocultar id
    ui->tableViewDepartamentos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDepartamentos->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->btnCrear, &QPushButton::clicked, this, &DptoForm::slotCrearDepartamento);
    connect(ui->btnEditar, &QPushButton::clicked, this, &DptoForm::slotEditarDepartamento);
    connect(ui->btnBorrar, &QPushButton::clicked, this, &DptoForm::slotBorrarDepartamento);
    connect(ui->tableViewDepartamentos->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, &DptoForm::seleccionarDepartamento);

    limpiarFormulario();
    cargarDepartamentos();
}

DptoForm::~DptoForm()
{
    delete ui;
}

void DptoForm::limpiarFormulario()
{
    idDepartamentoSeleccionado = -1;
    ui->lineEditNombre->clear();
    ui->tableViewDepartamentos->clearSelection();
}

void DptoForm::cargarDepartamentos()
{
    model->removeRows(0, model->rowCount());

    QList<QVariantMap> departamentos = dao->listarDepartamentos();

    for (const QVariantMap &dep : departamentos) {
        QList<QStandardItem *> fila;
        fila.append(new QStandardItem(dep.value("id").toString()));
        fila.append(new QStandardItem(dep.value("nombre").toString()));
        model->appendRow(fila);
    }

    limpiarFormulario();
}

void DptoForm::seleccionarDepartamento(const QModelIndex &current)
{
    if (!current.isValid()) {
        limpiarFormulario();
        return;
    }

    idDepartamentoSeleccionado = model->data(model->index(current.row(), 0)).toInt();
    QString nombre = model->data(model->index(current.row(), 1)).toString();
    ui->lineEditNombre->setText(nombre);
}

void DptoForm::slotCrearDepartamento()
{
    QString nombre = ui->lineEditNombre->text().trimmed();
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre no puede estar vacío.");
        return;
    }

    if (dao->existeNombreDepartamento(nombre)) {
        QMessageBox::warning(this, "Error", "Ya existe un departamento con ese nombre.");
        return;
    }

    QVariantMap departamento;
    departamento["nombre"] = nombre;

    QString errorMsg;
    if (!dao->insertarDepartamento(departamento, errorMsg)) {
        QMessageBox::critical(this, "Error", "No se pudo insertar el departamento:\n" + errorMsg);
        return;
    }

    cargarDepartamentos();
}

void DptoForm::slotEditarDepartamento()
{
    if (idDepartamentoSeleccionado < 0) {
        QMessageBox::warning(this, "Error", "Seleccione un departamento para editar.");
        return;
    }

    QString nombre = ui->lineEditNombre->text().trimmed();
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre no puede estar vacío.");
        return;
    }

    if (dao->existeNombreDepartamento(nombre, idDepartamentoSeleccionado)) {
        QMessageBox::warning(this, "Error", "Ya existe un departamento con ese nombre.");
        return;
    }

    QVariantMap departamento;
    departamento["id"] = idDepartamentoSeleccionado;
    departamento["nombre"] = nombre;

    QString errorMsg;
    if (!dao->actualizarDepartamento(departamento, errorMsg)) {
        QMessageBox::critical(this, "Error", "No se pudo actualizar el departamento:\n" + errorMsg);
        return;
    }

    cargarDepartamentos();
}

void DptoForm::slotBorrarDepartamento()
{
    if (idDepartamentoSeleccionado < 0) {
        QMessageBox::warning(this, "Error", "Seleccione un departamento para borrar.");
        return;
    }

    int ret = QMessageBox::question(this, "Confirmar borrado",
                                    "¿Está seguro de que desea borrar este departamento?",
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        QString errorMsg;
        if (!dao->eliminarDepartamento(idDepartamentoSeleccionado, errorMsg)) {
            QMessageBox::critical(this, "Error", "No se pudo borrar el departamento:\n" + errorMsg);
            return;
        }
        cargarDepartamentos();
    }
}

void DptoForm::on_DptoForm_accepted()
{

}

