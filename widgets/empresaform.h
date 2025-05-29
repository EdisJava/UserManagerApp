#ifndef EMPRESAFORM_H
#define EMPRESAFORM_H

#include <QDialog>

namespace Ui {
class EmpresaForm;
}

class EmpresaForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmpresaForm(QWidget *parent = nullptr);
    ~EmpresaForm();

signals:
    void empresaGuardada(const QString &nombre);

private slots:

    void onCrearClicked();
    void onBorrarClicked();
    void onEditarClicked();
    void onDeptClicked();

private:
    Ui::EmpresaForm *ui;
    QString rutaArchivo;

    void cargarLista();
    void guardarLista();
};

#endif // EMPRESAFORM_H
