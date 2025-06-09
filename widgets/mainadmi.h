#ifndef MAINADMI_H
#define MAINADMI_H

#include <QWidget>

// Incluye los headers de los formularios que usarás (asegúrate que existen)
#include "UserForm.h"
#include "empresaForm.h"
#include "DptoForm.h"
#include "users.h"

namespace Ui {
class MainAdmi;
}

class MainAdmi : public QWidget
{
    Q_OBJECT

public:
    explicit MainAdmi(QWidget *parent = nullptr);
    ~MainAdmi();

signals:
    void btnGestionUsuariosClicked();
    void btnGestionEmpresasClicked();
    void btnGestionDepartamentosClicked();

private slots:
    void abrirGestionUsuarios();
    void abrirGestionEmpresas();
    void abrirGestionDepartamentos();

private:
    Ui::MainAdmi *ui;

    // Punteros a los formularios hijos
    Users *users;
    EmpresaForm *empresaForm;
    DptoForm *dptoForm;
      DepartamentoDAO departamentoDAO;
    QWidget *widgetActual = nullptr;
};

#endif // MAINADMI_H
