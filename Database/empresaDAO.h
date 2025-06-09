#ifndef EMPRESADAO_H
#define EMPRESADAO_H

#include <QString>
#include <QVariantMap>
#include <QList>

class EmpresaDAO
{
public:
    EmpresaDAO();

    bool insertarEmpresa(const QVariantMap &empresa, QString &errorMsg);
    bool actualizarEmpresa(const QVariantMap &empresa, QString &errorMsg);
    bool eliminarEmpresa(int id, QString &errorMsg);
    QVariantMap obtenerEmpresa(int id);
    QList<QVariantMap> listarEmpresas();
};

#endif // EMPRESADAO_H
