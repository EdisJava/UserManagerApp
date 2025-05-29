#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class usuario {
public:
    usuario(int id, const QString &nombre, const QString &apellidos, const QString &dni, const QString &telefono, const QString &email,
            const QString &estado, const QString &contrasenha, const QString &puesto, int departamentoId);

    int getId() const;
    QString getNombre() const;
    QString getApellidos() const;
    QString getDni() const;
    QString getTelefono() const;
    QString getEmail() const;
    QString getEstado() const;
    QString getContrasenha() const;
    QString getPuesto() const;
    int getDepartamentoId() const;

    void setNombre(const QString &nombre);
    void setApellidos(const QString &apellidos);
    void setDni(const QString &dni);
    void setTelefono(const QString &telefono);
    void setEmail(const QString &email);
    void setEstado(const QString &estado);
    void setPuesto(const QString &puesto);
    void setDepartamentoId(int departamentoId);

private:
    int id, departamentoId;
    QString nombre, apellidos, dni, telefono, email, estado, contrasenha, puesto;

};

#endif // USUARIO_H
