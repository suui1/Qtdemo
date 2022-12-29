#include "patienteditview.h"
#include "ui_patienteditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

PatientEditView::PatientEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbname,tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbidcard,tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbheight,tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->spinBox,tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbphone,tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dateEdit,tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->comboBox,tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->lineEdit,tabModel->fieldIndex("CREATEDTIMESTAMP"));

    dataMapper->setCurrentIndex(index);

    ui->dbID->setEnabled(false);
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_pushButton_clicked()
{

    IDatabase::getInstance().submitPatientEdit();
    emit goPreviousView();
}


void PatientEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}

