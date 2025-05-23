#ifndef ADMINEMPRESA_H
#define ADMINEMPRESA_H

#include <QWidget>

namespace Ui {
class AdminEmpresa;
}

class AdminEmpresa : public QWidget
{
    Q_OBJECT

public:
    explicit AdminEmpresa(QWidget *parent = nullptr);
    ~AdminEmpresa();

private:
    Ui::AdminEmpresa *ui;
};

#endif // ADMINEMPRESA_H
