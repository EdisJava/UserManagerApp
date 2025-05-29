#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <QString>

class departamento {
public:
    departamento(int id, const QString &nombre, int empresaId);

    int getId() const;
    QString getNombre() const;
    int getEmpresaId() const;

    void setNombre(const QString &nombre);
    void setEmpresaId(int id);

private:
    int id;
    QString nombre;
    int empresaId;

};

#endif // DEPARTAMENTO_H
