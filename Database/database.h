#ifndef DATABASE_H
#define DATABASE_H

//hay que incluir la siguiente clase para manejar conexiones a base de datos
#include <QtSql/QSqlDatabase>

//se incluye la siguiente clase para manejar cadenas de texto
#include <QString>

//definimos la clase para manejar la base de datos
class database {
public:

// hacemos un metodo estático para establecer la conexión a la base de datos utilizando la ruta proporcionada
    static bool connect(const QString &dbPath);
    static QSqlDatabase& get();

private:

    //lo siguiente representa la conexión a la base de datos
    static QSqlDatabase db;
};

#endif // DATABASE_H
