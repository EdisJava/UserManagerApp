#ifndef EMPRESAFORM_H
#define EMPRESAFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class empresaForm;
}
QT_END_NAMESPACE

class empresaForm : public QMainWindow
{
    Q_OBJECT

public:
    empresaForm(QWidget *parent = nullptr);
    ~empresaForm();

private:
    Ui::empresaForm *ui;
};
#endif // EMPRESAFORM_H
