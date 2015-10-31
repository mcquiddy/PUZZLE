#include "mainwindow.h"
#include <QApplication>
#include "ordenar.h"
using namespace std;

//MainWindow* w;
ordenar * algoritmo;
int main(int argc, char *argv[])

{


    QApplication a(argc, argv);


//    w= new MainWindow();

//    w->show();
//    w->goloso();
//    w->splitImageAux();
    algoritmo=new ordenar();
    algoritmo->split();
    //algoritmo->golososo();


    return a.exec();

}
