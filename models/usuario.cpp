#include "usuario.h"

usuario::usuario(int id, const QString &nombre, const QString &apellidos, const QString &dni, const QString &telefono, const QString &email,
                 const QString &estado, const QString &contrasenha, const QString &puesto, int departamentoId) : id(id), nombre(nombre), apellidos(apellidos),
             dni(dni), telefono(telefono), email(email), estado(estado), contrasenha(contrasenha), puesto(puesto), departamentoId(departamentoId) {
}

int usuario::getId() const{
    return id;
}
QString usuario::getNombre() const{
    return nombre;
}
QString usuario::getApellidos() const{
    return apellidos;
}
QString usuario::getDni() const{
    return dni;
}
QString usuario::getTelefono() const{
    return telefono;
}
QString usuario::getEmail() const{
    return email;
}
QString usuario::getEstado() const{
    return estado;
}

QString usuario::getPuesto() const{
    return puesto;
}
int usuario::getDepartamentoId()const{
    return departamentoId;
}
