#include "mainadmi.h"
#include "ui_mainadmi.h"

MainAdmi::MainAdmi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainAdmi)
{
    ui->setupUi(this);
}

MainAdmi::~MainAdmi()
{
    delete ui;
}
