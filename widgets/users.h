#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

    void setUsuarioActual(const QString &dni, const QString &rol, const QString &empresa);

private slots:
    void loadUsers();
    void on_btnNuevoUsuario_clicked();
    void on_btnAddUser_clicked();
    void on_btnEditUser_clicked();
    void on_btnDeleteUser_clicked();
    void mostrarFotoUsuario(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::Users *ui;

    // Variables para almacenar datos del usuario que está usando la app
    QString usuarioActualDni;
    QString usuarioActualRol;
    QString usuarioActualEmpresa;

    // Para filtrar usuarios que puede ver (admins de empresa solo ven los suyos)
    QString empresaFiltro;

    void cargarUsuarios();
    void setEmpresaFiltro(const QString &empresa);
};

#endif // USERS_H
