#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btsignin_clicked()
{
    IDatabase::getInstance().userLogin(ui->inputUserName->text(),
                                       ui->inputUserPassword->text());
    emit loginSuccess();

}

