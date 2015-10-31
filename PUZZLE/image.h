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
    QPixmap imagen;//guarda la imagen cortada
    lista<Image*> *listaTotal = new lista<Image*>();//guarda en orden la imagen cortada, corta toda la primera columna en orden arriba hacia abajo y pasa a la siguiente
    int id;//guarda el id de la imagen, se asigna en el orden en que se corten
    lista<lista<Image*>*> *matriz = new lista<lista<Image*>*> ();//matriz que guarda la imagen desordenada, y la imprime en pantalla
    int rndm=1;//numero random que sirve para crear la matriz con la imagen desordenada
    int len=1;//asigna el id


    void setID(int value);
    int getID();
    lista<lista<Image *> *> *cutImage(QSize size, int cuadros);
    QPixmap getImagen();
    void setImagen(QPixmap value);

};

#endif // IMAGE_H
