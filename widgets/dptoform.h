#ifndef DPTOFORM_H
#define DPTOFORM_H

#include <QDialog>

namespace Ui {
class DptoForm;
}

class DptoForm : public QDialog
{
    Q_OBJECT

public:
    explicit DptoForm(QWidget *parent = nullptr);
    ~DptoForm();

private slots:
    void on_btnCrear_clicked();
    void on_btnBorrar_clicked();
    void on_btnEditar_clicked();
    void on_btnAsignarUsr_clicked();


signals:
    void departamentoGuardado(const QString &nombre);

private:
    Ui::DptoForm *ui;

    void cargarDepartamentos();
    void guardarDepartamentos();
};

#endif // DPTOFORM_H
