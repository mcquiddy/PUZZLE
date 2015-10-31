#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) {


    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);



    scene = new QGraphicsScene();
    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);
    scene->setSceneRect(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT);
    QPixmap pix(BACKGROUND_IMAGE);

  // scene->addPixmap(pix);
    setScene(scene);

    qPen.setColor(Qt::blue);//color de las lineas que dividen la imagen

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    while(datoValido){
        getProfundidad();
        if(profundidad>=1 & profundidad<=5){
            break;
        }
    }


    cuadros=pow(2,(profundidad));
    raiz=cuadros;
    cuadros=pow(cuadros,2);

    sizeX=WINDOWS_WIDTH/ raiz;
    sizeY=WINDOWS_HEIGHT/raiz;


    qSize.setWidth(sizeX);
    qSize.setHeight(sizeY);
    listaImagen =  matriz->cutImage(qSize,raiz);

    for(int i=1; i<=raiz;i++){//fila
        for(int j=1;j<=raiz;j++){//columna

       pm=scene->addPixmap(listaImagen->rove(i)->get_data()->rove(j)->get_data()->getImagen());
       pm->setPos( (i-1)*sizeX,(j-1)*sizeY);


        }
   }

  //  qRect = new QGraphicsRectItem(qRectAux);
     //setScene(scene);







  goloso();
  if(profundidad>=1){

      if(profundidad==1){
          qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
          scene->addLine(qLine);
          qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
          scene->addLine(qLine);
          cout<<"cantidad de cuadros: "<<cuadros<<endl;

      }
      else if(profundidad>1){
          qLine.setLine(WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);//
          scene->addLine(qLine);
          qLine.setLine(0,WINDOWS_HEIGHT/2,WINDOWS_WIDTH,WINDOWS_HEIGHT/2);//
          scene->addLine(qLine);
          splitImage(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT,profundidad-1);
          cout<<"cantidad de cuadros: "<<cuadros<<endl;

      }
   }


}


int MainWindow::splitImage(int x1, int y1,int x2, int y2, int profundidad){

      if (profundidad<=0){
          return 0;
      }

      if(profundidad>0){
        splitImage(x1,y1,x1+(x2-x1)/2,y1+(y2-y1)/2,profundidad-1);
        qLine.setLine(x1 +((x2-x1)/4),y1,x1+((x2-x1)/4),y1+(y2-y1)/2);//agrega linea primer cuadrante vertical
         scene->addLine(qLine);
         qLine.setLine(x1,y1 +((y2-y1)/4),x1+((x2-x1)/2),y1+(y2-y1)/4);//agrega linea primer cuadrante horizontal
        scene->addLine(qLine);

        splitImage(x1+(x2-x1)/2,y1,x2,y1+(y2-y1)/2,profundidad-1);
        qLine.setLine(((x2-x1)/2)+((x2-x1)/4)+x1,y1,((x2-x1)/2)+((x2-x1)/4)+x1,((y2-y1)/2)+y1);//agrega linea segundo cuadrante vertical
        scene->addLine(qLine);
        qLine.setLine(x1,((y2-y1)/2)+((y2-y1)/4)+y1,((x2-x1)/2)+x1,((y2-y1)/2)+((y2-y1)/4)+y1);//agrega linea segundo cuadrante horizontal
       scene->addLine(qLine);

        splitImage(x1,y1+(y2-y1)/2,x1+(x2-x1)/2,y2,profundidad-1);
        qLine.setLine(x1+((x2-x1)/4),y1,x1+((x2-x1)/4),y2);//agrega linea tercer cuadrante vertical
        scene->addLine(qLine);
         qLine.setLine(x1,y1+((y2-y1)/4),x2,y1+((y2-y1)/4));//agrega linea tercer cuadrante horizontal
        scene->addLine(qLine);

        splitImage(x1+(x2-x1)/2,y1+(y2-y1)/2,x2,y2,profundidad-1);
        qLine.setLine(x1+((x2-x1)/2)+((x2-x1)/4),y1,x1+((x2-x1)/2)+((x2-x1)/4),y2);//agrega linea cuarto cuadrante vertical
        scene->addLine(qLine);//agrega linea cuarto cuadrante horizontal
        qLine.setLine(x1,y1+((y2-y1)/2)+((y2-y1)/4),x2,y1+((y2-y1)/2)+((y2-y1)/4));
       scene->addLine(qLine);
    }





}

int MainWindow::getProfundidad(){
    bool value;

      profundidad = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),  tr("Profundidad(1-5):"), 1, 0, 100, 1, &value);

           return profundidad;
}

void MainWindow::adyacentes(){
    while(identificadores->length()>=1){
        identificadores->delete_Pos(1);
    }
    int rndm;

    for(int i=1; i<=raiz;i++){//fila

        for(int j=1;j<=raiz;j++){//columna

        identificadores->insert_tail(listaImagen->rove(i)->get_data()->rove(j)->get_data()->getID());
        //vecino izquierdo
        if((i-1)>0){

            identificadores->get_tail()->getAdyacentes()->insert_tail(listaImagen->rove(i-1)->get_data()->rove(j)->get_data()->getID());
            rndm= rand() % (cuadros*2)+1;
            identificadores->get_tail()->getAdyacentes()->get_tail()->setPeso(rndm);
        }
        //vecino derecho
        if((i+1)<=raiz){
            identificadores->get_tail()->getAdyacentes()->insert_tail(listaImagen->rove(i+1)->get_data()->rove(j)->get_data()->getID());
            rndm= rand() % (cuadros*2)+1;
            identificadores->get_tail()->getAdyacentes()->get_tail()->setPeso(rndm);
        }
        //vecino arriba
        if((j-1)>0){
            identificadores->get_tail()->getAdyacentes()->insert_tail(listaImagen->rove(i)->get_data()->rove(j-1)->get_data()->getID());
            rndm= rand() % (cuadros*2)+1;
            identificadores->get_tail()->getAdyacentes()->get_tail()->setPeso(rndm);
        }
        //vecino de abajo
        if((j+1)<=raiz){
            identificadores->get_tail()->getAdyacentes()->insert_tail(listaImagen->rove(i)->get_data()->rove(j+1)->get_data()->getID());
            rndm= rand() % (cuadros*2)+1;
            identificadores->get_tail()->getAdyacentes()->get_tail()->setPeso(rndm);
        }


        }
    }
    for(int i=1; i<= identificadores->length();i++){
        cout<<"ID :"<<identificadores->rove(i)->get_data()<<"lista adyacencia: "<<endl;
        identificadores->rove(i)->getAdyacentes()->print_list();
        cout<<" fin"<<endl;

    }


}
void MainWindow::goloso(){

   for(int len=1;len<=cuadros;len++){
       adyacentes();
       listADY=  new listAdyacent<int>();//Limpiar lista de adyacencia
       listCamino=  new listAdyacent<int>();//Limpiar lista de Camino que tiene que recorrer

       cout<<"------------"<<endl;
    int lenAux;
      int meta;

        cout<<"despues de diskctra"<<endl;
        this->dikstra(len);//Lista de todos los caminos mas cortos

        lenAux=len;

            for(int i=1;i<=raiz;i++){
                for (int j=1; j<=raiz;j++){

                    if(lenAux==1){
                        meta= listaImagen->rove(i)->get_data()->rove(j)->get_data()->getID() ;
                    }
                    lenAux-=1;
                }
            }


        cout<<"prueba: "<<meta<<endl;
        if(len!=meta){
            this->rotaciones(len,meta);//Lista ordenada de los caminos que tiene que rotar el cuadro
            if(listCamino->get_tail()->get_data()!=len){
                    listCamino->insert_tail(len);

            }
            cout<<"id1: "<<len<<",meta: "<<meta <<endl;
            listCamino->print_list();

            while(listCamino->length()>1){

                changePos(len,listCamino->rove(1)->get_data());
                listCamino->delete_data(listCamino->rove(1)->get_data());
                listCamino->print_list();

            }
            cout<<"fin cambio para un identificador"<<endl;

            for(int i=1; i<=raiz;i++){//fila
                for(int j=1;j<=raiz;j++){//columna

               pm=scene->addPixmap(listaImagen->rove(i)->get_data()->rove(j)->get_data()->getImagen());
               pm->setPos( (i-1)*sizeX,(j-1)*sizeY);
                }
             }
       }


         cout<<"------------"<<endl;




    }




}






/**
 * @brief MainWindow::dikstra
 * @param pIni
 * Cuadro que quiere mover
 */


void MainWindow::dikstra(int pIni)
{
    ///Lista para el control de caminos
    while(listADY->length()>=1){
        listADY->delete_Pos(1);
    }
    for(int i=1; i<= identificadores->length();i++){
        listADY->insert_tail(identificadores->rove(i)->get_data());


    }


    ////Aplicar Disktra///

   int Inicio=pIni;// Posicion inicial donde se empezara a buscar

   ////Fomar la primera lista de camino del punto de inicio
   for(int i=1; i<=listADY->length();i++){

       if(identificadores->rove(i)->get_data()==Inicio){
           listADY->buscar(Inicio)->setEdicion(false);
            listADY->buscar(Inicio)->set_padre(Inicio);
       }
       else{
           NodeAdyacent<int> *temp=identificadores->buscar(Inicio)->getAdyacentes()->buscar(listADY->rove(i)->get_data());
           if(temp!=NULL){
                 listADY->rove(i)->setPeso(temp->getPeso());
                 listADY->rove(i)->set_padre(identificadores->buscar(Inicio)->get_data());

           }

       }
   }



   //Encontrar el peso mas optimo
   int optimo=0;
   for(int i=1; i<=listADY->length();i++){
       if(identificadores->rove(i)->get_data()!=Inicio){
           if(optimo==0){
               if(listADY->rove(i)->getPeso()!=0){
                optimo= i;

           }

           }
           else{
               if(listADY->rove(optimo)->getPeso() > listADY->rove(i)->getPeso()){
                   if(listADY->rove(i)->getPeso()!=0){
                    optimo= i;

               }
           }
       }

   }
   }
   listADY->rove(optimo)->setEdicion(false);


   cout<<"llllllllllllllllll"<<endl;
   ///Empezar a econtrar el camino mas corto dependiendo del mas optmimo
   for(int j=1; j<identificadores->length();j++){
   for(int i=1; i<=identificadores->length();i++){
       if(listADY->rove(i)->isEditable()){
           //Cambiar peso
           NodeAdyacent<int> *temp=identificadores->rove(optimo)->getAdyacentes()->buscar(listADY->rove(i)->get_data());

           if(temp!=NULL){
                int Newpeso=temp->getPeso()+listADY->rove(optimo)->getPeso();
               if(listADY->rove(i)->getPeso()!=0){

                if(Newpeso<listADY->rove(i)->getPeso()){

                    listADY->rove(i)->setPeso(Newpeso);
                    listADY->rove(i)->set_padre(identificadores->rove(optimo)->get_data());

                }

           }
               else{
                   listADY->rove(i)->setPeso(Newpeso);
                    listADY->rove(i)->set_padre(identificadores->rove(optimo)->get_data());
               }
           }


       }
   }
   //obtener optimo
   optimo=0;
   for(int i=1; i<=listADY->length();i++){
       if(identificadores->rove(i)->get_data()!=Inicio){
           if(optimo==0){
               if(listADY->rove(i)->getPeso()!=0 &&  listADY->rove(i)->isEditable()){
                optimo= i;


           }
           }
           else{
               if(listADY->rove(optimo)->getPeso() > listADY->rove(i)->getPeso()){
                   if(listADY->rove(i)->getPeso()!=0 &&  listADY->rove(i)->isEditable()){
                    optimo= i;

               }
           }
       }

   }
   }
   listADY->rove(optimo)->setEdicion(false);

   //Final optimo

   }
   for(int i=1;i<=listADY->length();i++){
       cout<<" id "<<listADY->rove(i)->get_data()<<" peso "<<listADY->rove(i)->getPeso()<<" padre "<<listADY->rove(i)->get_padre()<<endl;
   }
}
/**
 * @brief MainWindow::rotaciones
 * @param pIni
 * Cuadro que quiere mover
 * @param pMeta
 * Cuadro de meta a donde el cuadro a mover o inicial quiere llegar
 */
void MainWindow::rotaciones(int pIni, int pMeta)
{
    NodeAdyacent<int> * temp=listADY->buscar(pMeta);
 //cout<<"}}}}}}}}}}}}}}}}"<<endl;
    while(temp->get_data()!=pIni){
             listCamino->insert_head(temp->get_data());
             temp=listADY->buscar(temp->get_padre());
    }

    for(int i=1;i<=listCamino->length();i++){
        cout<<" id "<<listCamino->rove(i)->get_data()<<endl;
    }

}

int MainWindow::changePos(int id1, int id2){

    int a=1;
    int b=1;
    QPixmap imagenID1;
    QPixmap imagenID2;



    for(int i=1;i<=raiz;i++){
        for(int j=1;j<=raiz;j++){
            if(listaImagen->rove(i)->get_data()->rove(j)->get_data()->getID()==id1){
               a=i;
               b=j;
            imagenID1=listaImagen->rove(i)->get_data()->rove(j)->get_data()->getImagen();


            }

        }

    }


    for(int i=1;i<=raiz;i++){
        for(int j=1;j<=raiz;j++){
            if(listaImagen->rove(i)->get_data()->rove(j)->get_data()->getID()==id2){
                 imagenID2=listaImagen->rove(i)->get_data()->rove(j)->get_data()->getImagen();
                 listaImagen->rove(i)->get_data()->rove(j)->get_data()->setImagen(imagenID1);
                 listaImagen->rove(i)->get_data()->rove(j)->get_data()->setID(id1);
            }
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){

            if(i==a & j==b){
               listaImagen->rove(i)->get_data()->rove(j)->get_data()->setID(id2) ;
               listaImagen->rove(i)->get_data()->rove(j)->get_data()->setImagen(imagenID2);
            }
        }
    }
    cout<<"fin changePos, id1:"<<id1<<", id2: "<<id2<<endl;

    }








