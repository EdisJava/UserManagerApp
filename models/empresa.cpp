#include "empresa.h"

empresa::empresa(int id, const QString &nombre) : id(id), nombre(nombre) {
}
        int empresa::getId() const{
            return id;
        }
        QString empresa::getNombre() const{
            return nombre;
        }
        void empresa::setNombre(const QString &nombre){
            this->nombre=nombre;
        }
