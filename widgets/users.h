#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include <QStandardItemModel>
#include <QVariantMap>
#include "UsuarioDAO.h"
#include "userform.h" // Debe existir y declarar la clase UsuarioDAO correctamente

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

     void abrirUserFormConDatos(const QVariantMap &datos);
    void setEmpresaFiltro(const QString &empresa);


private:
    Ui::Users *ui;
    QStandardItemModel *model;         // Modelo para mostrar usuarios en la lista
    QList<QVariantMap> listaUsuarios;  // Lista de usuarios cargados desde la BD
    UsuarioDAO dao;
 UserForm *userForm = nullptr;        // Objeto DAO para acceso a datos

    void cargarUsuarios();             // Carga usuarios en el modelo y lista
 QString empresaFiltro;


private slots:
    void on_btnAddUser_clicked();     // Añadir usuario
    void on_btnEditUser_clicked();    // Editar usuario seleccionado
    void on_btnDeleteUser_clicked();  // Eliminar usuario seleccionado
    void on_listView_clicked(const QModelIndex &index);  // Mostrar datos y foto al seleccionar usuario
    void on_btnAgregarUsuario_clicked();
};

#endif // USERS_H
