#ifndef IMAGE_H
#define IMAGE_H
#include <linked_list.h>
#include <QPixmap>
#include <Constants.h>
#include <QSize>
#include <qlabel.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Image
{
public:
    Image();
    int posX;
    int posY;
    int id;
    QPixmap imagen;
    lista<Image> *listaTotal = new lista<Image> ();

   // QLabel label;



  lista<lista<Image> *> *cutImage(QSize size, int cuadros);
    int getPosX() const;
    void setPosX(int value);
    int getPosY() const;
    void setPosY(int value);
    int getId() const;
    void setId(int value);
    lista<lista<Image>*> *matriz = new lista<lista<Image>*> ();
    QPixmap getImagen() const;
    void setImagen(const QPixmap &value);
    int rndm;
    int len=1;
};

#endif // IMAGE_H
