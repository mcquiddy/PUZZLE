#ifndef LISTAADYACENTE_H
#define LISTAADYACENTE_H

#include <iostream>
#include "NodoAdyacente.h"

using namespace std;

template<typename T>
class listAdyacent {
private:
    NodeAdyacent<T>* head;
    NodeAdyacent<T>* tail;
    int Length;

public:
    void insert_head(T new_data);
    void insert_tail(T new_data);
    void delete_data(T data);
    bool isInList(T data);
    NodeAdyacent<T>* rove(int x);
    NodeAdyacent<T>* get_head();
    NodeAdyacent<T>* get_tail();
    NodeAdyacent<T>*  buscar(T data);
    int length();
    T* serch(T data);
    void print_list();
    listAdyacent();
    virtual ~listAdyacent();

    void delete_Pos(int x);



};

template<typename T>
/**
 * @brief list<T>::list
 */
listAdyacent<T>::listAdyacent(){
    head=NULL;
    tail=NULL;
    Length=0;
}
template<typename T>
/**
 * @brief list<T>::insert_head
 * @param new_data
 */
void listAdyacent<T>::insert_head(T new_data){
    NodeAdyacent<T> *newNode=new NodeAdyacent<T>(new_data);
    if(this->head==NULL){
        head=newNode;
        tail=head;
    }
    else{
        NodeAdyacent<T>* temp=this->head;
        newNode->set_next(temp);
        temp->set_prev(newNode);
        this->head=newNode;
    }
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::insert_tail
 * @param new_data
 */
void listAdyacent<T>::insert_tail(T new_data){
    NodeAdyacent<T> *newNode=new NodeAdyacent<T>(new_data);
    if(this->tail==NULL){
        head=newNode;
        tail=head;
    }
    else{
        NodeAdyacent<T>* temp=this->tail;
        temp->set_next(newNode);
        newNode->set_prev(temp);
        tail=newNode;
    }
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::delete_data
 * @param data
 */
void listAdyacent<T>::delete_data(T data){
    if(this->Length!=0){//se cumple en caso que  solo existe un nodo(head)
            NodeAdyacent<T>* temp=head->get_next();
            if((temp==NULL) & ((this->head->get_data())==data)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;

            }
            else{
                NodeAdyacent<T>* NextTemp=temp->get_next();
                if(this->head->get_data()==data){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                 if(this->tail->get_data()==data){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                while(temp->get_next()!=NULL){
                    //cout<<temp->get_data()<<" es igual a "<<data<<"?"<<endl;
                    if(temp->get_data()==data){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        temp=NextTemp;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }
                    NextTemp=temp->get_next();
                }
            }

    }
}

template<typename T>
/**
 * @brief list<T>::isInList
 * @param data
 * @return
 */
 NodeAdyacent<T>* listAdyacent<T>::rove(int x){
    NodeAdyacent<T>* temp=this->head;
    if(this->Length>=0 && x<=this->length()){

        for(int i=1;i<x;i++){

            temp=temp->get_next();

        }
    }
    else{
       temp=NULL;

    }

    return temp;
}
template<typename T>
 bool listAdyacent<T>::isInList(T data){
     bool save=false;
     if(this->Length>0){
         NodeAdyacent<T>* temp=this->head;
         while(temp!=NULL){
             if(temp->get_data()==data){
                 save=true;
                 break;
             }
             temp=temp->get_next();
         }
     }

     return save;
 }

template<typename T>
/**
 * @brief list<T>::serch
 * @param data
 * @return
 */
T* listAdyacent<T>::serch(T data){
    if(this->isInList(data)){
        NodeAdyacent<T>* temp=head;
        NodeAdyacent<T>* result=NULL;
        while(temp->get_next()!=NULL){
            if(temp->get_data()==data){
                result=data;
            }
        }
        return result;
    }
    else{
        return NULL;
    }
}

template<typename T>
/**
 * @brief list<T>::buscar
 * @param data
 * @return
 */
NodeAdyacent<T>*  listAdyacent<T>::buscar(T data){
    if(this->isInList(data)){
        NodeAdyacent<T>* temp=this->head;

        while(temp->get_next()!=NULL){
            if(temp->get_data()==data){
                break;
            }
            temp=temp->get_next();
        }
        return temp;
    }
    else{
        return NULL;
    }
}

template<typename T>
/**
 * @brief list<T>::delete_Pos
 * @param x
 */
void listAdyacent<T>::delete_Pos(int x){
    if(this->Length!=0 && x<=this->length()){//se cumple en caso que  solo existe un nodo(head)
            NodeAdyacent<T>* temp=head->get_next();
            if((temp==NULL) & (x==1)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;
            }
            else{

                if(x==1){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;

                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                else if(x==this->length()){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                else{
                    temp=head;
                 for(int i=1; i<=x;i++){
                    if(i==x){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        this->Length--;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }

                }
                }
            }
    }
}


template<typename T>
/**
 * @brief list<T>::get_head
 * @return
 */
NodeAdyacent<T>* listAdyacent<T>::get_head(){
    return this->head;
}

template<typename T>
/**
 * @brief list<T>::get_tail
 * @return
 */
NodeAdyacent<T>* listAdyacent<T>::get_tail(){
    return this->tail;
}


template<typename T>
/**
 * @brief list<T>::length
 * @return
 */
int listAdyacent<T>::length(){
    return Length;
}

template<typename T>
/**
 * @brief list<T>::print_list
 */
void listAdyacent<T>::print_list(){
    NodeAdyacent<T>* temp=this->head;
    cout<<"Cantidad de nodos: "<<this->Length<<endl;
    while(temp!=NULL){
        cout<<temp->get_data()<<" ";
        temp=temp->get_next();
    }
    cout<<endl;
}
template<typename T>
/**
 * @brief list<T>::~list
 */
listAdyacent<T>::~listAdyacent(){
    delete this;
}


#endif // LISTAADYACENTE_H
