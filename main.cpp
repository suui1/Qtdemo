#include "masterview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Masterview w;
    w.show();
    return a.exec();
}
