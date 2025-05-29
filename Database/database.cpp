#include "database.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

QSqlDatabase database::db = QSqlDatabase();

bool database::connect(const QString &dbPath){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database successfully connected.";
    return true;
}

QSqlDatabase& database::get() {
    return db;
}
