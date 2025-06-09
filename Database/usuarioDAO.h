#ifndef USUARIODAO_H
#define USUARIODAO_H

#include <QVariantMap>
#include <QList>
#include <QPixmap>

class UsuarioDAO
{
public:
    UsuarioDAO();

    bool insertarUsuario(const QVariantMap &usuario, QString &errorMsg);
    bool actualizarUsuario(const QVariantMap &usuario, QString &errorMsg);
    bool eliminarUsuario(const QString &dni, QString &errorMsg);

    QVariantMap obtenerUsuario(const QString &dni);
    QList<QVariantMap> listarUsuarios(const QString &empresaFiltro, QString &errorMsg);

    QList<QVariantMap> listarDepartamentos(QString &errorMsg);
    QList<QVariantMap> listarEmpresas(QString &errorMsg);

    QPixmap cargarFoto(const QVariant &fotoVar) const;
};

#endif // USUARIODAO_H
