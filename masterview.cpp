#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include "idatabase.h"

Masterview::Masterview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Masterview)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();

    IDatabase::getInstance();

}

Masterview::~Masterview()
{
    delete ui;
}

void Masterview::goLoginView()
{
    qDebug() << "goLoginView";
    loginView = new LoginView(this);

    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomView()));


}

void Masterview::goWelcomView()
{
    qDebug() << "gowelcomView";
    welcomeView = new WelcomeView(this);
    pushWidgetToStackView(welcomeView);

    connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));;
    connect(welcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));

}

void Masterview::goDoctorView()
{
    qDebug() << "godoctorView";
    doctorView = new DoctorView(this);
    pushWidgetToStackView(doctorView);

}

void Masterview::goDepartmentView()
{
    qDebug() << "goDepartmentView";
    departmentView = new DepartmentView(this);
    pushWidgetToStackView(departmentView);
}

void Masterview::goPatientEditView(int rowNo)
{
    qDebug() << "goPatientEditView";
    patientEditView = new PatientEditView(this,rowNo);
    pushWidgetToStackView(patientEditView);


    connect(patientEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void Masterview::goPatientView()
{
    qDebug() << "goPatientView";
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
}

void Masterview::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if(count > 1){
        ui->stackedWidget->setCurrentIndex(count-2);
        ui->label->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget = ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;

    }
}

void Masterview::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);

    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->label->setText(widget->windowTitle());
}


void Masterview::on_btlog_clicked()
{
    goPreviousView();
}


void Masterview::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();
    if(count > 1)
        ui->btback->setEnabled(true);
    else
        ui->btback->setEnabled(false);

    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if(title == "欢迎"){
        ui->btlogout->setEnabled(true);
        ui->btback->setEnabled(false);
    }else
        ui->btlogout->setEnabled(false);


}

void Masterview::on_btlogout_clicked()
{
    goPreviousView();
    ui->btback->setEnabled(false);

}





void Masterview::on_btback_clicked()
{
    goPreviousView();
}

