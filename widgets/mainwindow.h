#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UsuarioDAO.h"
#include "DepartamentoDAO.h"

class EmpresaForm;
class DptoForm;
class UserForm;
class Guess;
class MainAdmi;
class AdmiCompany;
class Users;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEntrar_clicked();
    void on_actionSalir_triggered();
    void on_actionAcerca_de_triggered();

    void abrirGestionEmpresas();
    void abrirGestionDepartamentos();
    void abrirGestionUsuarios();

private:
    void mostrarMensaje(const QString &mensaje);
    bool validarDNI(const QString &dni);
QString empresaDelAdminEmpresa;
    Ui::MainWindow *ui;

    AdmiCompany *admiCompany = nullptr;
    EmpresaForm *empresaForm = nullptr;
    DptoForm *dptoForm = nullptr;
    UserForm *userForm = nullptr;  // Aquí usersForm es UserForm (individual)
    Users *usersWindow = nullptr;   // Aquí usersWindow es la ventana lista de usuarios

    Guess *guessForm = nullptr;
    MainAdmi *mainAdmi = nullptr;

    DepartamentoDAO *departamentoDAO = nullptr;

    UsuarioDAO usuarioDAO;
};

#endif // MAINWINDOW_H
