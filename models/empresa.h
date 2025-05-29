#ifndef EMPRESA_H
#define EMPRESA_H

#include <QString>

class empresa {
public:
    empresa(int id, const QString &nombre);

    int getId() const;
    QString getNombre() const;
    void setNombre(const QString &nombre);

private:
    int id;
    QString nombre;
};

#endif // EMPRESA_H
