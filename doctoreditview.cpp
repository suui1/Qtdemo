#include "doctoreditview.h"
#include "ui_doctoreditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

DoctorEditView::DoctorEditView(QWidget *parent ,int index) :
    QWidget(parent),
    ui(new Ui::DoctorEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbname,tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEmployeeID,tabModel->fieldIndex("EMPLOYEENO"));
    dataMapper->addMapping(ui->dbdepartmentID,tabModel->fieldIndex("DEPARTMENT_ID"));


    dataMapper->setCurrentIndex(index);

    ui->dbID->setEnabled(false);

}


DoctorEditView::~DoctorEditView()
{
    delete ui;
}

void DoctorEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitPatientEdit();
    emit goPreviousView();
}


void DoctorEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}

