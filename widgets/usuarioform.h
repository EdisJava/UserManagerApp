#ifndef USUARIOFORM_H
#define USUARIOFORM_H

#include <QWidget>

namespace Ui {
class usuarioForm;
}

class usuarioForm : public QWidget
{
    Q_OBJECT

public:
    explicit usuarioForm(QWidget *parent = nullptr);
    ~usuarioForm();

private:
    Ui::usuarioForm *ui;
};

#endif // USUARIOFORM_H
