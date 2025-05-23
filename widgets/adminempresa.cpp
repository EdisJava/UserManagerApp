#include "adminempresa.h"
#include "ui_adminempresa.h"

AdminEmpresa::AdminEmpresa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminEmpresa)
{
    ui->setupUi(this);
}

AdminEmpresa::~AdminEmpresa()
{
    delete ui;
}
