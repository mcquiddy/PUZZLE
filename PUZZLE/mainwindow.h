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
#include <QTimer>
#include  <QThread>

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    //~MainWindow();

    QGraphicsScene* scene;
    QWidget *parent;


    QLine qLine;//lineas que divide los recuadros en los que se recorta la imagen


    QGraphicsPixmapItem *pm ;
    lista<lista<Image*>*> *listaImagen = new lista<lista<Image*>*> ();
    listaSimple<int> *identificadores = new listaSimple<int> ();
    listAdyacent<int> * listADY=  new listAdyacent<int>();
    listAdyacent<int> * listCamino=  new listAdyacent<int>();
    QPen qPen;
    QSize qSize;
    Image *matriz= new Image();
    double sizeX;//tamano en pixeles en x de cada cuadro
    double sizeY;//tamano en pixeles en  y de cada cuadro
    int raiz;//cantidad de divisiones en x(mismas que en y)
    bool datoValido=true;//controla que la profundidad introducida por el usuario sea valida
    int profundidad=6;//obtine el valor ingresado por el usuario
    int  cuadros;//cantidad de cuadros en los que se recorta la imagen
    int id1;//cambio de id
    int id2;//cambio de id
    int splitImageAux();

    int changePos(int id1, int id2);
    void adyacentes();
    void dikstra(int pIni);
    void rotaciones(int pIni,int pMeta);
     int getProfundidad();
    int splitImage(int x1, int y1,int x2, int y2, int profundidad);
    void PaintImage();
    void goloso();
    static MainWindow* getInstance();
private:
    static MainWindow* unicMain;

};

#endif // MAINWINDOW_H
