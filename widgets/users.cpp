#include "users.h"
#include "ui_users.h"

users::users(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::users)
{
    ui->setupUi(this);
}

users::~users()
{
    delete ui;
}
