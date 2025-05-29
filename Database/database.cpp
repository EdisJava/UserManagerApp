#include "database.h" //incluimos el archivo header de la clase "database"
#include <QtSql/QSqlDatabase> //clase para manejar la base de datos
#include <QtSql/QSqlError> // clase para manejar los errores de la base de datos
#include <QDebug> //esto lo necesitamos para imprimir mensaje de depuración en la consola

//inicializamos el miembro estático "db" como una instancia vacía de QSqlDatabase
QSqlDatabase database::db = QSqlDatabase();

//implementamos el método estático "connect" para abrir una conexión con la base de datos SQLite
bool database::connect(const QString &dbPath){

    // Agregamos una base de datos del tipo SQLite al conjunto de conexiones disponibles
    db = QSqlDatabase::addDatabase("QSQLITE");
    // Establecemos la ruta al archivo de la base de datos
    db.setDatabaseName(dbPath);

    //control de errores por si da error al intentar abrir la base de datos
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database successfully connected.";
    return true;
}

//implementamos el método estático "get" para poder acceder a la instancia de la base de datos
QSqlDatabase& database::get() {
    return db;
}
