#ifndef ORDENAR_H
#define ORDENAR_H
#include <mainwindow.h>
class ordenar
{
protected:
    MainWindow* sort=MainWindow::getInstance();
public:
    ordenar();
    void golososo();
    void split();
};

#endif // ORDENAR_H
