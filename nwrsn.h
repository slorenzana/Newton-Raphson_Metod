#ifndef NWRSN_H
#define NWRSN_H

#include <QMainWindow>

namespace Ui {
class NWRSN;
}

class NWRSN : public QMainWindow
{
    Q_OBJECT

public:
    explicit NWRSN(QWidget *parent = 0);
    ~NWRSN();
    double xi;//This variable´ll keep the value of the initial X
    double ea;//This is the accepted error, that the program´ll tolerate
    double error;//The error of each interaction
    double errort;//The total error of the value of the square root
    double xr;//This is the resulting X of each operation, in other words the value of the square root
    double fx;//value of the function
    double sqrt;//The value of the square root

    /*With this value the program will stop the program in case that the slope of the
     * function became 0 and continues in that way*/
    int ls;


public slots:
    void valor_raiz();//On this Slot, the program´ll find the square root of the function
    void limpiar();//On this Slot, the memory dump the old data

private:
    Ui::NWRSN *ui;
};

#endif // NWRSN_H
