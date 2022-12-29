#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>

namespace Ui {
class PatientView;
}

class PatientView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr);
    ~PatientView();

private slots:
    void on_add_clicked();

    void on_search_clicked();

    void on_del_clicked();

    void on_modify_clicked();

signals:
    void goPatientEditView(int index);

private:
    Ui::PatientView *ui;
};

#endif // PATIENTVIEW_H
