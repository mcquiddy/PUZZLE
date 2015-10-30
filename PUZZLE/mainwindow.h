#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <list>
#include <linked_list.h>
#include <Constants.h>
#include <QInputDialog>
#include <QMessageBox>
#include <math.h>
#include <image.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRgb>
#include <listaSimple.h>
#include <listaAdyacente.h>

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    //~MainWindow();

    QGraphicsScene* scene;
    QWidget *parent;
    int getProfundidad();

    QLine qLine;
    QGraphicsRectItem* qRect;
    QGraphicsRectItem* item1 ;
    QRect qRectAux;

    QGraphicsPixmapItem *pm ;
    int changePos();
    int id1;//cambio de id
    int id2;//cambio de id
    int adyacentes();
    void dikstra(int pIni);
    void rotaciones(int pIni,int pMeta);
    lista<lista<Image>*> *listaImagen = new lista<lista<Image>*> ();
    listaSimple<int> *identificadores = new listaSimple<int> ();
    listAdyacent<int> * listADY=  new listAdyacent<int>();
    listAdyacent<int> * listCamino=  new listAdyacent<int>();


    QPen qPen;
    QSize qSize;
    Image *matriz= new Image();

    double sizeX;
    double sizeY;

    int raiz;
    bool datoValido=true;
     int profundidad=6;


   lista<QColor*> *colores= new lista<QColor*>;


    int  cuadros;
    int splitImage(int x1, int y1,int x2, int y2, int profundidad);
    void PaintImage();


};

#endif // MAINWINDOW_H
