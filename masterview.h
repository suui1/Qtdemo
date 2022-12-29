#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "departmentview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "welcomeview.h"
<<<<<<< HEAD
#include "doctoreditview.h"
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Masterview; }
QT_END_NAMESPACE

class Masterview : public QWidget
{
    Q_OBJECT

public:
    Masterview(QWidget *parent = nullptr);
    ~Masterview();


public slots:
    void goLoginView();
    void goWelcomView();
    void goDoctorView();
<<<<<<< HEAD
    void goDoctorEditView(int rowNo);
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPatientView();
    void goPreviousView();


<<<<<<< HEAD

=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
private slots:

    void on_btlog_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btlogout_clicked();

    void on_btback_clicked();

private:

    void pushWidgetToStackView(QWidget *widget);
    Ui::Masterview *ui;

    WelcomeView *welcomeView;
    DoctorView *doctorView;
    PatientView *patientView;
    DepartmentView *departmentView;
    LoginView *loginView;
    PatientEditView *patientEditView;
<<<<<<< HEAD
    DoctorEditView *doctorEditView;
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6

};
#endif // MASTERVIEW_H
