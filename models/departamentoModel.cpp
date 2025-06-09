#include "departamentoModel.h"

DepartmentModel::DepartmentModel(int id, const std::string& nombre, int empresaId)
    : id(id), nombre(nombre), empresaId(empresaId)
{
}

int DepartmentModel::getId() const {
    return id;
}

std::string DepartmentModel::getNombre() const {
    return nombre;
}

int DepartmentModel::getEmpresaId() const {
    return empresaId;
}

void DepartmentModel::setId(int id) {
    this->id = id;
}

void DepartmentModel::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void DepartmentModel::setEmpresaId(int empresaId) {
    this->empresaId = empresaId;
}
