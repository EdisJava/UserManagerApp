
#ifndef MAINADMI_H
#define MAINADMI_H

#include <QWidget>

class Users;

namespace Ui {
class MainAdmi;
}

class MainAdmi : public QWidget
{
    Q_OBJECT

public:
    explicit MainAdmi(QWidget *parent = nullptr);
    ~MainAdmi();

private slots:
    void on_btnEmpresas_clicked();
    void on_btnDepartamentos_clicked();
    void on_btnUsuarios_clicked();

private:
    Ui::MainAdmi *ui;

    QWidget *empresaForm = nullptr;
    QWidget *dptoForm = nullptr;
    Users *usersWidget = nullptr; // Instancia de la clase que muestra la lista
};

#endif // MAINADMI_H
