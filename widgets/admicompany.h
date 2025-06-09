#ifndef ADMICONPANY_H
#define ADMICONPANY_H

#include <QWidget>
#include "DptoForm.h"
#include "UserForm.h"
#include "DepartamentoDAO.h"
#include "UsuarioDAO.h"

namespace Ui {
class AdmiCompany;
}

class AdmiCompany : public QWidget
{
    Q_OBJECT

public:
    explicit AdmiCompany(QWidget *parent = nullptr);
    ~AdmiCompany();
    void setEmpresaActual(const QString &empresa);
    QString empresaActual() const;

signals:
    void gestionarDepartamentos();
    void gestionarUsuarios();
    void gestionarUsuariosSolicitado();


private slots:
    void on_btnGestionDepartamentos_clicked();
    // void on_btnGestionUsuarios_clicked();

private:
    Ui::AdmiCompany *ui;
    DptoForm *dptoForm = nullptr;
    UserForm *userForm = nullptr;
    DepartamentoDAO departamentoDAO;
    UsuarioDAO usuarioDAO;
    QString m_empresaActual;
};

#endif // ADMICONPANY_H
