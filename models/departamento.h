#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <QString> //incluimos la clase QString para poder manejar cadenas de texto

//se define la clase departamento
class departamento {
public:
    //empleamos un constructor para inicializar el objeto con sus atributos
    departamento(int id, const QString &nombre, int empresaId);

    //métodos getters para acceder a sus atributos privados
    int getId() const;
    QString getNombre() const;
    int getEmpresaId() const;

    //métodos setters para modificar los atributos
    void setNombre(const QString &nombre);
    void setEmpresaId(int id);

private:
    //atributos privados que representan los datos del departamento
    int id;
    QString nombre;
    int empresaId;

};

#endif // DEPARTAMENTO_H
