#include "doctorview.h"
#include "ui_doctorview.h"
<<<<<<< HEAD
#include "idatabase.h"
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6

DoctorView::DoctorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
<<<<<<< HEAD


    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if(iDatabase.initDoctorModel()){
        ui->tableView->setModel(iDatabase.DoctorTabModel);
        ui->tableView->setSelectionModel(iDatabase.theDoctorSelection);
    }

}

DoctorView::~DoctorView()
{
    delete ui;
}
<<<<<<< HEAD

void DoctorView::on_findDoctor_button_clicked()
{
    QString filter = QString("name like '%%1%' ").arg(ui->lineEdit->text());
    IDatabase::getInstance().searchDoctor(filter);
}


void DoctorView::on_editDoctor_button_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().theDoctorSelection->currentIndex();
    emit goDoctorEditView(curIndex.row());
}


void DoctorView::on_addDoctor_button_clicked()
{
    int currow = IDatabase::getInstance().addNewDoctor();
    emit goDoctorEditView(currow);
}


void DoctorView::on_delDoctor_button_clicked()
{
    IDatabase::getInstance().deleteCurrentDoctor();
}

=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
