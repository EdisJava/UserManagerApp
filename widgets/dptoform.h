#ifndef DPTOFORM_H
#define DPTOFORM_H

#include <QWidget>

namespace Ui {
class dptoForm;
}

class dptoForm : public QWidget
{
    Q_OBJECT

public:
    explicit dptoForm(QWidget *parent = nullptr);
    ~dptoForm();

private:
    Ui::dptoForm *ui;
};

#endif // DPTOFORM_H
