#include "empresaform.h"
#include "ui_empresaform.h"

empresaForm::empresaForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::empresaForm)
{
    ui->setupUi(this);
}

empresaForm::~empresaForm()
{
    delete ui;
}
