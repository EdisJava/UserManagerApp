#ifndef ADMICONPANY_H
#define ADMICONPANY_H

#include <QWidget>

namespace Ui {
class admicompany;
}

class admicompany : public QWidget
{
    Q_OBJECT

public:
    explicit admicompany(const QString& empresa, QWidget *parent = nullptr);
    ~admicompany();

private slots:
    void on_btnCrear_clicked();
    void on_btnEditar_clicked();
    void on_btnBorrar_clicked();

private:
    void loadUsers();

    Ui::admicompany *ui;
    QString empresaAdmin;
};

#endif // ADMICONPANY_H
