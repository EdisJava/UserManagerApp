#ifndef GUESS_H
#define GUESS_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class Guess;
}

class Guess : public QWidget
{
    Q_OBJECT

public:
    explicit Guess(QWidget *parent = nullptr);
    ~Guess();

    void mostrarDatos(const QString &dni,
                      const QString &nombre,
                      const QString &telefono,
                      const QString &email,
                      const QString &departamento,
                      const QString &empresa,
                      const QString &estado,
                      const QString &rol,
                      const QPixmap &foto);

private:
    Ui::Guess *ui;
};

#endif // GUESS_H
