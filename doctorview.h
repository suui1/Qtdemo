#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>

namespace Ui {
class DoctorView;
}

class DoctorView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

private slots:
    void on_findDoctor_button_clicked();

    void on_editDoctor_button_clicked();

    void on_addDoctor_button_clicked();

    void on_delDoctor_button_clicked();

signals:
    void goDoctorEditView(int index);

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
