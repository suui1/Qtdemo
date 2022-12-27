#include "idatabase.h"
#include <QUuid>
void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE"); //添加 SQL LITE数据库驱动
    QString aFile = "G:/project/LAB4A.db";
    database.setDatabaseName(aFile); //设置数据库名称

    if(!database.open()){
        qDebug() << "failed to open database";

    }else
        qDebug() << "open database is ok" << database.connectionName();
}

QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query; //查询出当前记录的所有字段
    query.prepare("select * from user where EmpNo = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password){
            qDebug() << "login ok";
            return "loginOK";
        }else{
            qDebug() << "wrong password";
            return "wrongPassword";
        }
    }else{
        qDebug() << "no such user";
        return "wrongUsername";
    }
}
bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(
                QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patientTabModel->select()))
        return false;
    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();

}
void IDatabase::revertPatientEdit()
{
    patientTabModel->revertAll();
}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),
                               QModelIndex());
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1);


    int curRecNo = curIndex.row();
    QSqlRecord curRec = patientTabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);


    return curIndex.row();
}





IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}
