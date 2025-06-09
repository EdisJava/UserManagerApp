#ifndef DEPARTMENTMODEL_H
#define DEPARTMENTMODEL_H

#include <string>

class DepartmentModel {
private:
    int id;
    std::string nombre;
    int empresaId;

public:
    DepartmentModel(int id, const std::string& nombre, int empresaId);

    int getId() const;
    std::string getNombre() const;
    int getEmpresaId() const;

    void setId(int id);
    void setNombre(const std::string& nombre);
    void setEmpresaId(int empresaId);
};

#endif // DEPARTMENTMODEL_H
