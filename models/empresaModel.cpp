#include "EmpresaModel.h"

    EmpresaModel::EmpresaModel(int id, const std::string& nombre)
    : id(id), nombre(nombre) {
        }

    int EmpresaModel::getId() const { return id;
    }
    std::string EmpresaModel::getNombre() const {
        return nombre;
    }

    void EmpresaModel::setId(int id) {
        this->id = id;
    }
    void EmpresaModel::setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }
