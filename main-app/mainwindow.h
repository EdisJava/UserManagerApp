#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum RolUsuario {
    ADMIN_TOTAL,
    ADMIN_EMPRESA,
    USUARIO_ESTANDAR,
    ROL_INVALIDO
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onbtnEntrarClicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    bool conectarBaseDeDatos();
    RolUsuario obtenerRolUsuario(const QString &nombreUsuario);
    void mostrarPestanaSegunRol(RolUsuario rol);
};

#endif // MAINWINDOW_H
