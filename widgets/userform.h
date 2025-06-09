#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include <QVariantMap>
#include "UsuarioDAO.h"

namespace Ui {
class UserForm;
}

class UserForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserForm(UsuarioDAO* dao, QWidget *parent = nullptr);
    ~UserForm();

    void setUserData(const QVariantMap &data);
    QVariantMap getUserData() const;
    void validarVisualmenteDNI(const QString &dni);

private slots:
    void on_btnGuardar_clicked();
    void on_btnCancelar_clicked();
    void on_btnSeleccionarFoto_clicked();

private:
    Ui::UserForm *ui;
    UsuarioDAO* dao;  // Puntero para no copiar el DAO

    void cargarDepartamentosYEmpresas();
};

#endif // USERFORM_H
