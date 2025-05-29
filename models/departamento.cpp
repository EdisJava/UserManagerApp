#include "departamento.h" // Incluimos el archivo de header con la definición de la clase

//empleamos un constructor que inicializa los atributos usando una lista de inicialización
departamento::departamento(int id, const QString &nombre, int empresaId) : id(id), nombre(nombre), empresaId(empresaId) {
}

//getters
    int departamento::getId() const{
        return id;
    }
    QString departamento::getNombre() const{
        return nombre;
    }
    int departamento::getEmpresaId() const{
        return empresaId;
    }

//setters
    void departamento::setNombre(const QString &nombre){
        this ->nombre = nombre;
    }
    void departamento::setEmpresaId(int id){
        this->empresaId = id;
    }

