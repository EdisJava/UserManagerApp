#ifndef USUARIOMODEL_H
#define USUARIOMODEL_H

#include <string>

    class UsuarioModel {
    private:
    int id;
        std::string nombre;
        std::string correo;
        int departamentoId;
\
    public:
    UsuarioModel(int id, const std::string& nombre, const std::string& correo, int departamentoId);
\
        int getId() const;
        std::string getNombre() const;
        std::string getCorreo() const;
        int getDepartamentoId() const;

        void setId(int id);
        void setNombre(const std::string& nombre);
        void setCorreo(const std::string& correo);
        void setDepartamentoId(int departamentoId);
};

#endif // USUARIOMODEL_H
