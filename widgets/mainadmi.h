#ifndef MAINADMI_H
#define MAINADMI_H

#include <QWidget>

namespace Ui {
class MainAdmi;
}

class MainAdmi : public QWidget
{
    Q_OBJECT

public:
    explicit MainAdmi(QWidget *parent = nullptr);
    ~MainAdmi();

private:
    Ui::MainAdmi *ui;
};

#endif // MAINADMI_H
