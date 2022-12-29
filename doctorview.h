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

<<<<<<< HEAD
private slots:
    void on_findDoctor_button_clicked();

    void on_editDoctor_button_clicked();

    void on_addDoctor_button_clicked();

    void on_delDoctor_button_clicked();

signals:
    void goDoctorEditView(int index);

=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
