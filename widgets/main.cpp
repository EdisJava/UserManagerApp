#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>

#include "mainwindow.h"
#include "qsqlerror.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Ruta a la base de datos (usa barras normales o dobles invertidas)
    QString dbPath = "C:/projectsqt/UserMannagmentApp/UserMannagmentApp.db";

    // Crear conexión única a base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error de conexión", "No se pudo conectar a la base de datos:\n" + db.lastError().text());
        return -1;
    }

    MainWindow w;
    w.show();

    return app.exec();
}
