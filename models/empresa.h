#ifndef EMPRESA_H
#define EMPRESA_H

#include <QString>  //incluimos la clase QString para poder manejar cadenas de texto

//se define la clase empresa
class empresa {
public:

    //empleamos un constructor para inicializar el objeto con sus atributos
    empresa(int id, const QString &nombre);

    //métodos getters para acceder a sus atributos privados
    int getId() const;
    QString getNombre() const;

    //métodos setters para modificar los atributos
    void setNombre(const QString &nombre);

private:
    //atributos privados que representan los datos del departamento
    int id;
    QString nombre;
};

#endif // EMPRESA_H
