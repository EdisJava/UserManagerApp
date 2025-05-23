#ifndef USERS_H
#define USERS_H

#include <QWidget>

namespace Ui {
class users;
}

class users : public QWidget
{
    Q_OBJECT

public:
    explicit users(QWidget *parent = nullptr);
    ~users();

private:
    Ui::users *ui;
};

#endif // USERS_H
