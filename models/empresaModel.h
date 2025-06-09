#ifndef EMPRESAMODEL_H
#define EMPRESAMODEL_H

#include <string>

    class EmpresaModel{
    private:
    int id;
        std::string nombre;

    public:
    EmpresaModel(int id, const std::string& nombre);

        int getId() const;
        std::string getNombre() const;

        void setId(int id);
        void setNombre(const std::string& nombre);
};

#endif // EMPRESAMODEL_H\
