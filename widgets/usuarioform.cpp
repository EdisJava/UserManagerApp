#include "usuarioform.h"
#include "ui_usuarioform.h"

usuarioForm::usuarioForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usuarioForm)
{
    ui->setupUi(this);
}

usuarioForm::~usuarioForm()
{
    delete ui;
}
