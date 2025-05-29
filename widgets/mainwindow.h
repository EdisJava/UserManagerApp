#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

#include "../models/usuario.h"    // Asumo que tienes esta clase definida
#include "guess.h"      // Widget donde mostrarás datos usuario
#include "ui_mainadmi.h"
#include "admicompany.h"
#include "empresaform.h"
#include "dptoform.h"
#include "users.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum RolUsuario {
    ADMIN_TOTAL,
    ADMIN_EMPRESA,
    USUARIO_ESTANDAR,
    ROL_INVALIDO
};

enum EstadoValidacionUsuario {
    EXISTE_Y_VALIDO,
    INACTIVO_O_SUSPENDIDO,
    NO_EXISTE
};

struct ResultadoValidacion {
    EstadoValidacionUsuario estado;
    RolUsuario rol;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onbtnEntrarClicked();
    void onBtnAdminEmpresaClicked();
    void onBtnAdminDepartamentosClicked();
    void onBtnAdminTrabajadoresClicked();
    void onBtnAdminCompanyClicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    Ui::MainAdmi *adminTotalFormUi = nullptr;
    Guess *guessWidget = nullptr;

    EmpresaForm *empresaWindow = nullptr;
    DptoForm *dptoWindow = nullptr;
    Users *Userwindow = nullptr;
    admicompany* adminCompanyWidget = nullptr;

    QString empresaAdmin;

    RolUsuario obtenerRolUsuario(const QString &nombreUsuario);
    usuario cargarUsuarioPorNombre(const QString &nombreUsuario);

    void mostrarDatosUsuarioEnGuess(const usuario &usuario);
    void mostrarPestanaSegunRol(RolUsuario rol);

    QString obtenerRutaFotoUsuario(const QString &dni);
    QString obtenerNombreDepartamento(int departamentoId);
    QString nombreUsuario;   // guarda el nombre introducido
    ResultadoValidacion validarUsuario(const QString &nombreUsuario);


};

#endif // MAINWINDOW_H
