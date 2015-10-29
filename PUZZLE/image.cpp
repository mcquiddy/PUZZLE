#include "image.h"

Image::Image()
{


}
QPixmap Image::getImagen() const
{
    return this->imagen;
}

void Image::setImagen(const QPixmap &value)
{
    imagen = value;
}

int Image::getId() const
{
    return this->id;
}

void Image::setId(int value)
{
    id = value;
}

int Image::getPosY() const
{
    return this->posY;
}

void Image::setPosY(int value)
{
    posY = value;
}

int Image::getPosX() const
{
    return this->posX;
}

void Image::setPosX(int value)
{
    posX = value;
}


 lista<lista<Image>*>*  Image::cutImage(QSize size, int cuadros){

len=cuadros*cuadros;
    //Corta una sección de una imagen más grande
    for(int i=0; i<cuadros;i++){//fila
        for(int j=0;j<cuadros;j++){//columna
            Image info;
            info.setPosX(i*size.width());
            info.setPosY(j*size.height());
            QPixmap test = QPixmap((BACKGROUND_IMAGE));
            QPixmap chunk = test.copy(info.getPosX(),info.getPosY(),size.width(),size.height());
            info.setImagen(chunk);
            info.setId(len);
            len+=1;

            listaTotal->insert_tail(info);//imagen cortada y agregada en orden a la lista
        }
    }

        for(int i=0; i<cuadros;i++){//fila
            lista<Image> *fila = new lista<Image> ();

            for(int j=0;j<cuadros;j++){//columna

                rndm=  rand()%(listaTotal->length());
                cout<<"bbbbbbbbbb len>: "<<listaTotal->length()<<endl;
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




















