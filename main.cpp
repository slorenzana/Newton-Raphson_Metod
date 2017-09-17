#include "nwrsn.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NWRSN w;
    w.show();

    return a.exec();
}
