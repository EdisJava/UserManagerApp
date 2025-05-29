#ifndef GUESS_H
#define GUESS_H

#include <QWidget>

namespace Ui {
class Guess;
}

class Guess : public QWidget
{
    Q_OBJECT

public:
    explicit Guess(QWidget *parent = nullptr);
    ~Guess();
    void cargarDatosUsuario(const QString &nombre);


    void setDatosUsuario(const QString &dni,
                         const QString &nombre,
                         const QString &telefono,
                         const QString &email,
                         const QString &departamento,
                         const QString &empresa,
                         const QString &estado,
                         const QString &foto,
                         const QString &rol);

signals:
 // para abrir UserForm desde MainWindow u otro

private slots:

private:
    Ui::Guess *ui;
};

#endif // GUESS_H
