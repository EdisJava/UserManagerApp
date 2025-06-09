#include "UsuarioModel.h"

    UsuarioModel::UsuarioModel(int id, const std::string& nombre, const std::string& correo, int departamentoId)\
    : id(id), nombre(nombre), correo(correo), departamentoId(departamentoId) {
    }

    int UsuarioModel::getId() const{
        return id;
    }
    std::string UsuarioModel::getNombre() const {
        return nombre;
    }
    std::string UsuarioModel::getCorreo() const {
        return correo;
    }
    int UsuarioModel::getDepartamentoId() const {
        return departamentoId;
    }

    void UsuarioModel::setId(int id) {
        this->id = id;
    }
    void UsuarioModel::setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }
    void UsuarioModel::setCorreo(const std::string& correo){
        this->correo = correo;
    }
    void UsuarioModel::setDepartamentoId(int departamentoId) {
        this->departamentoId = departamentoId;
    }

