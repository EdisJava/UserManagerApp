#include "dptoform.h"
#include "ui_dptoform.h"

dptoForm::dptoForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dptoForm)
{
    ui->setupUi(this);
}

dptoForm::~dptoForm()
{
    delete ui;
}
