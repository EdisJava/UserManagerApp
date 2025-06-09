#include "DepartamentoDAO.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DepartamentoDAO::DepartamentoDAO()
{
    if (!database::open()) {
        qDebug() << "No se pudo abrir la base de datos en DepartamentoDAO";
    }
}

bool DepartamentoDAO::insertarDepartamento(const QVariantMap &departamento, QString &errorMsg)
{
    QSqlQuery query(database::get());
    query.prepare("INSERT INTO departamentos (nombre) VALUES (:nombre)");
    query.bindValue(":nombre", departamento.value("nombre"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        return false;
    }
    return true;
}

bool DepartamentoDAO::actualizarDepartamento(const QVariantMap &departamento, QString &errorMsg)
{
    QSqlQuery query(database::get());
    query.prepare("UPDATE departamentos SET nombre = :nombre WHERE id = :id");
    query.bindValue(":nombre", departamento.value("nombre"));
    query.bindValue(":id", departamento.value("id"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        return false;
    }
    return true;
}

bool DepartamentoDAO::eliminarDepartamento(int id, QString &errorMsg)
{
    QSqlQuery query(database::get());
    query.prepare("DELETE FROM departamentos WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        return false;
    }
    return true;
}

QVariantMap DepartamentoDAO::obtenerDepartamento(int id)
{
    QVariantMap result;
    QSqlQuery query(database::get());
    query.prepare("SELECT id, nombre FROM departamentos WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        result["id"] = query.value(0);
        result["nombre"] = query.value(1);
    }
    return result;
}

QList<QVariantMap> DepartamentoDAO::listarDepartamentos()
{
    QList<QVariantMap> lista;
    QSqlQuery query(database::get());
    query.prepare("SELECT id, nombre FROM departamentos ORDER BY nombre ASC");

    if (query.exec()) {
        while (query.next()) {
            QVariantMap dep;
            dep["id"] = query.value(0);
            dep["nombre"] = query.value(1);
            lista.append(dep);
        }
    }
    return lista;
}

bool DepartamentoDAO::existeNombreDepartamento(const QString &nombre, int idExcluir)
{
    QSqlQuery query(database::get());

    if (idExcluir < 0) {
        query.prepare("SELECT COUNT(*) FROM departamentos WHERE nombre = :nombre");
        query.bindValue(":nombre", nombre);
    } else {
        query.prepare("SELECT COUNT(*) FROM departamentos WHERE nombre = :nombre AND id != :id");
        query.bindValue(":nombre", nombre);
        query.bindValue(":id", idExcluir);
    }

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}
