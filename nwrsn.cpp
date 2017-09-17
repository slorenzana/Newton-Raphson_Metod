#include "nwrsn.h"
#include "ui_nwrsn.h"


NWRSN::NWRSN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NWRSN)
{
    ui->setupUi(this);
    connect(ui->pushButton_entrar,SIGNAL(clicked()),this,SLOT(valor_raiz()));//conecting the button to start the interation
    connect(ui->pushButton_limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));//This´ll conect the cleaning button
}

NWRSN::~NWRSN()
{
    delete ui;
}

void NWRSN::valor_raiz(){
    error=100;
    /*Every time that the program runs, the error´ll be set to 100%*/
    xi=ui->doubleSpinBox_xi->value();
    ea=ui->doubleSpinBox_ea->value();

        do{
                /*On this section we calculate the value of the square root base on the metod of Newton-Raphson*/
            xr=(exp(-xi)-xi)/(-exp(-xi)-1);
                /*Then we calculate the total error of the operation*/
            errort=(exp(-xi))/(-exp(-xi)-1);
                /*Finally for test that the metod found the Sqrt Root we calculate the error of the interation*/
            error=100*abs((xr-xi)/xr);
                /*Disclaimer: this way of finding the square root work only with linear fuctions or in this case
                              with the function: "(e^-x)-x" */
                if(xr>0){
                      xi=xi-1;
                }
                if(xr<=0){
                    /*If the value of the slope is 0, the function is paralel*/
                    xi=xi+1;
                    if(xr<=0);{/* if we continue to get 0, the program´ll end the interations, by making the error
                                extreamly negative, to end the loop*/
                        ls=ls+1;/* this´s a timer to check the number of times that the slope has become paralel*/
                        if(ls==15){
                             error=-10000;
                        }
                    }
                }
            sqrt=xi;
            fx=exp((-xi))-xi;

            }while(fx==0);

    ui->lcdNumber->display(xi);
    ui->lcdNumber_2->display(errort);
    ui->lcdNumber_error->display(error);
}
void NWRSN::limpiar(){
    xi=0;
    xr=0;
    ea=0;
    errort=0;
    error=0;
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    ui->lcdNumber_error->display(0);
}
