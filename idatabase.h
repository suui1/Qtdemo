#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDataWidgetMapper>

class IDatabase : public QObject
{
    Q_OBJECT
public:


    static IDatabase &getInstance()
    {
         static IDatabase  instance; // Guaranteed to be destroyed.
                                      // Instantiated on first use.
         return  instance;
     }

    QString userLogin(QString userName,QString password);


private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const&)               = delete;
    void operator=(IDatabase const&)  = delete;

    QSqlDatabase database;



      void ininDatabase();



signals:

public:
      QSqlTableModel *patientTabModel;

      QItemSelectionModel *thePatientSelection;
      bool initPatientModel();


      bool searchPatient(QString filter);
      bool deleteCurrentPatient();
      bool submitPatientEdit();
      void revertPatientEdit();

      int addNewPatient();






};

#endif // IDATABASE_H
