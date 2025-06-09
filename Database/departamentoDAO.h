#ifndef DEPARTAMENTODAO_H
#define DEPARTAMENTODAO_H

#include <QVariantMap>
#include <QList>
#include <QString>

class DepartamentoDAO
{
public:
    DepartamentoDAO();

    bool insertarDepartamento(const QVariantMap &departamento, QString &errorMsg);
    bool actualizarDepartamento(const QVariantMap &departamento, QString &errorMsg);
    bool eliminarDepartamento(int id, QString &errorMsg);

    QVariantMap obtenerDepartamento(int id);
    QList<QVariantMap> listarDepartamentos();

    bool existeNombreDepartamento(const QString &nombre, int idExcluir = -1);
};

#endif // DEPARTAMENTODAO_H
