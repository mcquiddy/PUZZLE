#include "image.h"

Image::Image()
{


}
QPixmap Image::getImagen()
{
    return this->imagen;
}

void Image::setImagen(QPixmap value)
{
    this->imagen = value;
}


void Image::setID(int value){
    cout<<endl;
    this->id=value;
     cout<<endl;

 }
int Image::getID(){
    return this->id;
}





 lista<lista<Image*>*>*  Image::cutImage(QSize size, int cuadros){


    //Corta una sección de una imagen más grande
    for(int i=0; i<cuadros;i++){//fila
        for(int j=0;j<cuadros;j++){//columna
            Image *info=new Image();
            //info.setPosX(i*size.width());
            //info.setPosY(j*size.height());
            QPixmap test = QPixmap((BACKGROUND_IMAGE));
            QPixmap chunk = test.copy(i*size.width(),j*size.height(),size.width(),size.height());
            info->setImagen(chunk);
            info->setID(len);
            len+=1;

            listaTotal->insert_tail(info);//imagen cortada y agregada en orden a la lista
        }
    }

        for(int i=0; i<cuadros;i++){//fila
            lista<Image*> *fila = new lista<Image*> ();

            for(int j=0;j<cuadros;j++){//columna
                rndm=  rand()%(listaTotal->length());

                while(rndm==0 & listaTotal->length()>1){
                    rndm=  rand() % (listaTotal->length());
                }

                cout<<"len>: "<<listaTotal->length()<<", "<<"rndm: "<<rndm << endl;
                fila->insert_tail(listaTotal->rove(rndm)->get_data());
                listaTotal->delete_Pos(rndm);
            }

             matriz->insert_tail(fila);
        }




    return matriz;

}




















