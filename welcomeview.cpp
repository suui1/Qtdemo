#include "welcomeview.h"
#include "ui_welcomeview.h"
#include <QDebug>

WelcomeView::WelcomeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeView)
{
    qDebug() << "create WelcomeView";
    ui->setupUi(this);
}

WelcomeView::~WelcomeView()
{
    qDebug() << "destory WelcomeView";
    delete ui;
}

void WelcomeView::on_department_clicked()
{
    emit goDepartmentView();
}


void WelcomeView::on_doctor_clicked()
{
    emit goDoctorView();
}


void WelcomeView::on_patient_clicked()
{
    emit goPatientView();
}

