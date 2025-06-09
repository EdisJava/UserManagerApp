#include "UsuarioDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QVariant>

UsuarioDAO::UsuarioDAO() {}

bool UsuarioDAO::insertarUsuario(const QVariantMap &usuario, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (dni, nombre, telefono, email, departamento, empresa, estado, foto, rol) "
                  "VALUES (:dni, :nombre, :telefono, :email, :departamento, :empresa, :estado, :foto, :rol)");

    query.bindValue(":dni", usuario.value("dni"));
    query.bindValue(":nombre", usuario.value("nombre"));
    query.bindValue(":telefono", usuario.value("telefono"));
    query.bindValue(":email", usuario.value("email"));
    query.bindValue(":departamento", usuario.value("departamento"));
    query.bindValue(":empresa", usuario.value("empresa"));
    query.bindValue(":estado", usuario.value("estado"));

    QString rutaFoto = usuario.value("foto").toString();
    if (!rutaFoto.isEmpty() && QFile::exists(rutaFoto)) {
        query.bindValue(":foto", rutaFoto);
    } else {
        query.bindValue(":foto", QVariant(QVariant::String)); // NULL
    }

    query.bindValue(":rol", usuario.value("rol"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        qWarning() << "Error al insertar usuario:" << errorMsg;
        return false;
    }
    return true;
}

bool UsuarioDAO::actualizarUsuario(const QVariantMap &usuario, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("UPDATE usuarios SET nombre=:nombre, telefono=:telefono, email=:email, departamento=:departamento, "
                  "empresa=:empresa, estado=:estado, foto=:foto, rol=:rol WHERE dni=:dni");

    query.bindValue(":dni", usuario.value("dni"));
    query.bindValue(":nombre", usuario.value("nombre"));
    query.bindValue(":telefono", usuario.value("telefono"));
    query.bindValue(":email", usuario.value("email"));
    query.bindValue(":departamento", usuario.value("departamento"));
    query.bindValue(":empresa", usuario.value("empresa"));
    query.bindValue(":estado", usuario.value("estado"));

    QString rutaFoto = usuario.value("foto").toString();
    if (!rutaFoto.isEmpty() && QFile::exists(rutaFoto)) {
        query.bindValue(":foto", rutaFoto);
    } else {
        QString rutaActual = obtenerUsuario(usuario.value("dni").toString()).value("foto").toString();
        query.bindValue(":foto", rutaActual);
    }

    query.bindValue(":rol", usuario.value("rol"));

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        qWarning() << "Error al actualizar usuario:" << errorMsg;
        return false;
    }
    return true;
}

bool UsuarioDAO::eliminarUsuario(const QString &dni, QString &errorMsg)
{
    QSqlQuery query;
    query.prepare("DELETE FROM usuarios WHERE dni=:dni");
    query.bindValue(":dni", dni);

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        return false;
    }
    return true;
}

QVariantMap UsuarioDAO::obtenerUsuario(const QString &dni)
{
    QVariantMap usuario;
    QSqlQuery query;
    query.prepare("SELECT dni, nombre, telefono, email, departamento, empresa, estado, foto, rol FROM usuarios WHERE dni=:dni");
    query.bindValue(":dni", dni);

    if (query.exec() && query.next()) {
        usuario["dni"] = query.value("dni");
        usuario["nombre"] = query.value("nombre");
        usuario["telefono"] = query.value("telefono");
        usuario["email"] = query.value("email");
        usuario["departamento"] = query.value("departamento");
        usuario["empresa"] = query.value("empresa");
        usuario["estado"] = query.value("estado");
        usuario["foto"] = query.value("foto").toString();
        usuario["rol"] = query.value("rol");
    }
    return usuario;
}

QList<QVariantMap> UsuarioDAO::listarUsuarios(const QString &empresaFiltro, QString &errorMsg)
{
    QList<QVariantMap> lista;
    QSqlQuery query;

    QString sql = "SELECT dni, nombre, telefono, email, departamento, empresa, estado, foto, rol FROM usuarios";
    if (!empresaFiltro.isEmpty()) {
        sql += " WHERE empresa = :empresa";
    }

    query.prepare(sql);

    if (!empresaFiltro.isEmpty()) {
        query.bindValue(":empresa", empresaFiltro);
    }

    if (!query.exec()) {
        errorMsg = query.lastError().text();
        return lista;  // lista vacía en caso de error
    }

    while (query.next()) {
        QVariantMap usuario;
        usuario["dni"] = query.value("dni");
        usuario["nombre"] = query.value("nombre");
        usuario["telefono"] = query.value("telefono");
        usuario["email"] = query.value("email");
        usuario["departamento"] = query.value("departamento");
        usuario["empresa"] = query.value("empresa");
        usuario["estado"] = query.value("estado");
        usuario["foto"] = query.value("foto");
        usuario["rol"] = query.value("rol");
        lista.append(usuario);
    }

    errorMsg.clear();
    return lista;
}

QList<QVariantMap> UsuarioDAO::listarDepartamentos(QString &errorMsg)
{
    QList<QVariantMap> lista;
    QSqlQuery query;
    if (!query.exec("SELECT id, nombre FROM departamentos")) {
        errorMsg = query.lastError().text();
        return lista;
    }

    while (query.next()) {
        QVariantMap item;
        item["id"] = query.value("id");
        item["nombre"] = query.value("nombre");
        lista.append(item);
    }

    errorMsg.clear();
    return lista;
}

QList<QVariantMap> UsuarioDAO::listarEmpresas(QString &errorMsg)
{
    QList<QVariantMap> lista;
    QSqlQuery query;
    if (!query.exec("SELECT id, nombre FROM empresas")) {
        errorMsg = query.lastError().text();
        return lista;
    }

    while (query.next()) {
        QVariantMap item;
        item["id"] = query.value("id");
        item["nombre"] = query.value("nombre");
        lista.append(item);
    }

    errorMsg.clear();
    return lista;
}
