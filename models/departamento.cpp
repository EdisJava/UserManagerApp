#include "departamento.h"

departamento::departamento(int id, const QString &nombre, int empresaId) : id(id), nombre(nombre), empresaId(empresaId) {
}

    int departamento::getId() const{
        return id;
    }
    QString departamento::getNombre() const{
        return nombre;
    }
    int departamento::getEmpresaId() const{
        return empresaId;
    }

    void departamento::setNombre(const QString &nombre){
        this ->nombre = nombre;
    }
    void departamento::setEmpresaId(int id){
        this->empresaId = id;
    }

