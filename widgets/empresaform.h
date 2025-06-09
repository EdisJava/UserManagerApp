#ifndef EMPRESAFORM_H
#define EMPRESAFORM_H

#include <QDialog>
#include <QVariantMap>
#include <QList>
#include "EmpresaDAO.h"

namespace Ui {
class EmpresaForm;
}

class EmpresaForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmpresaForm(QWidget *parent = nullptr);
    ~EmpresaForm();

private slots:
    void on_btnCrear_clicked();
    void on_btnEditar_clicked();
    void on_btnBorrar_clicked();

private:
    Ui::EmpresaForm *ui;
    EmpresaDAO dao;
    QList<QVariantMap> listaEmpresas;

    void cargarEmpresas();
    void limpiarFormulario();

};

#endif // EMPRESAFORM_H
