#include "usuario.h"  // Incluimos el archivo de header con la definición de la clase

//empleamos un constructor que inicializa los atributos usando una lista de inicialización
usuario::usuario(int id, const QString &nombre, const QString &apellidos, const QString &dni, const QString &telefono, const QString &email,
                 const QString &estado, const QString &contrasenha, const QString &puesto, int departamentoId) : id(id), nombre(nombre), apellidos(apellidos),
             dni(dni), telefono(telefono), email(email), estado(estado), contrasenha(contrasenha), puesto(puesto), departamentoId(departamentoId) {
}

//getters
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

//setters
    void usuario::setNombre(const QString &nombre){
        this ->nombre = nombre;
    }
    void usuario::setApellidos(const QString &apellidos){
        this->apellidos = apellidos;
    }
    void usuario::setDni(const QString &dni){
        this->dni = dni;
    }
    void usuario::setTelefono(const QString &telefono){
        this->telefono = telefono;
    }
    void usuario::setEmail(const QString &email){
        this->email = email;
    }
    void usuario::setEstado(const QString &estado){
        this->estado = estado;
    }
    void usuario::setPuesto(const QString &puesto){
        this->puesto = puesto;
    }
    void usuario::setDepartamentoId(int departamentoId){
        this->departamentoId = departamentoId;
    }
