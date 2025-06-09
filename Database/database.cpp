// database.cpp
#include "database.h"
#include <QSqlError>
#include <QDebug>

QSqlDatabase database::db = QSqlDatabase();

QSqlDatabase& database::get()
{
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        // Ruta absoluta correcta y con barra normal para Windows
        db.setDatabaseName("C:/Users/AEPRACINFO-5/Documents/UserMannagmentApp/UserMannagmentApp/UserMannagmentApp.db");
    }
    return db;
}

bool database::open()
{
    QSqlDatabase &dbInstance = get();
    if (!dbInstance.isOpen()) {
        if (!dbInstance.open()) {
            qDebug() << "Error al abrir base de datos:" << dbInstance.lastError().text();
            return false;
        }
    }
    return true;
}

void database::close()
{
    if (db.isOpen()) {
        db.close();
    }
}
