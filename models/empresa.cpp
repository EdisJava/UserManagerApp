#include "empresa.h"  // Incluimos el archivo de header con la definición de la clase

//empleamos un constructor que inicializa los atributos usando una lista de inicialización
empresa::empresa(int id, const QString &nombre) : id(id), nombre(nombre) {
}

//getters
        int empresa::getId() const{
            return id;
        }
        QString empresa::getNombre() const{
            return nombre;
        }

//setter
        void empresa::setNombre(const QString &nombre){
            this->nombre=nombre;
        }
