#include "EmpresaDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

EmpresaDAO::EmpresaDAO()
{
    // Aquí no hacemos nada, pero se podría verificar conexión si quieres.
}

bool EmpresaDAO::insertarEmpresa(const QVariantMap &empresa, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("INSERT INTO empresas (nombre) VALUES (:nombre)");
    query.bindValue(":nombre", empresa.value("nombre"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        qDebug() << "Error insertarEmpresa:" << errorMsg;
        return false;
    }
    return true;
}

bool EmpresaDAO::actualizarEmpresa(const QVariantMap &empresa, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("UPDATE empresas SET nombre = :nombre WHERE id = :id");
    query.bindValue(":id", empresa.value("id"));
    query.bindValue(":nombre", empresa.value("nombre"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        qDebug() << "Error actualizarEmpresa:" << errorMsg;
        return false;
    }
    return true;
}

bool EmpresaDAO::eliminarEmpresa(int id, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("DELETE FROM empresas WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        qDebug() << "Error eliminarEmpresa:" << errorMsg;
        return false;
    }
    return true;
}

QVariantMap EmpresaDAO::obtenerEmpresa(int id)
{
    QVariantMap empresa;
    QSqlQuery query;
    query.prepare("SELECT id, nombre FROM empresas WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        empresa["id"] = query.value("id");
        empresa["nombre"] = query.value("nombre");
    } else {
        qDebug() << "Error obtenerEmpresa:" << query.lastError().text();
    }
    return empresa;
}

QList<QVariantMap> EmpresaDAO::listarEmpresas()
{
    QList<QVariantMap> lista;
    QSqlQuery query;
    if (!query.exec("SELECT id, nombre FROM empresas ORDER BY nombre ASC")) {
        qDebug() << "Error listarEmpresas:" << query.lastError().text();
        return lista;
    }

    while (query.next()) {
        QVariantMap empresa;
        empresa["id"] = query.value("id");
        empresa["nombre"] = query.value("nombre");
        lista.append(empresa);
    }
    return lista;
}
