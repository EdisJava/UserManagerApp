#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QString>

class database {
public:
    static bool connect(const QString &dbPath);
    static QSqlDatabase& get();

private:
    static QSqlDatabase db;
};

#endif // DATABASE_H
