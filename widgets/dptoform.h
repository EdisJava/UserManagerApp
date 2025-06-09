#ifndef DPTOFORM_H
#define DPTOFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QList>
#include <QVariantMap>
#include "DepartamentoDAO.h"
#include <QDialog>

namespace Ui {
class DptoForm;
}

class DptoForm : public QDialog
{
    Q_OBJECT

public:
    explicit DptoForm(DepartamentoDAO *dao, QWidget *parent = nullptr);
    ~DptoForm();

private slots:
    void slotCrearDepartamento();
    void slotEditarDepartamento();
    void slotBorrarDepartamento();
    void seleccionarDepartamento(const QModelIndex &current);

    void on_DptoForm_accepted();

private:
    Ui::DptoForm *ui;
    QStandardItemModel *model;

    DepartamentoDAO *dao;

    int idDepartamentoSeleccionado;

    void limpiarFormulario();
    void cargarDepartamentos();
};

#endif // DPTOFORM_H
