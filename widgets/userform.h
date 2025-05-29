#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class UserForm;
}

class UserForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = nullptr);
    ~UserForm();

    void setDatosUsuario(const QString &dni,
                         const QString &nombre,
                         const QString &telefono,
                         const QString &email,
                         const QString &departamento,
                         const QString &empresa,
                         const QString &estado,
                         const QString &foto,
                         const QString &rol);

    QStringList getUsuario() const;
    void cargarListasDesdeBD();
    void loadDepartamentos();
    void loadEmpresas();
public:
    void setModoAdminEmpresa(bool esAdminEmpresa);

signals:
    void usuarioGuardado();

private slots:
    void on_btnGuardar_clicked();
    void on_btnExaminar_clicked();

private:
    bool m_esAdminEmpresa = false;

private:
    Ui::UserForm *ui;
    bool modoEdicion;          // ✅ aquí sí
    QString dniOriginal;       // ✅ aquí sí

    bool existeUsuario(const QString &dni);
};

#endif // USERFORM_H
