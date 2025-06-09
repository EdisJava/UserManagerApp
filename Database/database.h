// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class database
{
public:
    static QSqlDatabase& get();
    static bool open();
    static void close();

private:
    database() = default;
    ~database() = default;
    database(const database&) = delete;
    database& operator=(const database&) = delete;

    static QSqlDatabase db;
};

#endif // DATABASE_H
