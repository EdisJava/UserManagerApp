#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Ruta a la base de datos, barra normal para Windows
    QString dbPath = "C:/Users/AEPRACINFO-5/Documents/UserMannagmentApp/UserMannagmentApp/UserMannagmentApp.db";

    // Crear conexión única a base de datos SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error de conexión",
                              "No se pudo conectar a la base de datos:\n" + db.lastError().text());
        return -1;
    }

    MainWindow w;
    w.show();

    return app.exec();
}
