#ifndef NODESIMPLE_H
#define NODESIMPLE_H
#include "listaAdyacente.h"
template <typename T>
class NodeSimple {
private:
    NodeSimple<T>* next_node;
    NodeSimple<T>* prev_node;
    T data;
    listAdyacent<int> * listAdyacentes;

public:
    NodeSimple(T dato) ;
    T get_data();
    void set_next(NodeSimple* next_node);
    void set_prev(NodeSimple* prev_node);
    listAdyacent<int> * getAdyacentes();

    NodeSimple* get_next();
    NodeSimple* get_prev();
};
/**
 * Constructor of a Node
 * Setting nex_node and prev_node as 0 or NULL
 */
template<typename T>
NodeSimple<T>::NodeSimple(T dato){
    this->data=dato;
    this->next_node=0;
    this->prev_node=0;
    this->listAdyacentes= new  listAdyacent<int>();
}
/**
 * Getters and setters
 */
template<typename T>
/**
 * @brief Node<T>::get_next
 * @return
 */
NodeSimple<T>* NodeSimple<T>::get_next(){
    return this->next_node;
}
template<typename T>
/**
 * @brief Node<T>::get_prev
 * @return
 */
NodeSimple<T>* NodeSimple<T>::get_prev(){
    return this->prev_node;
}
template<typename T>
void NodeSimple<T>::set_next(NodeSimple<T>* new_next_node){
    this->next_node=new_next_node;
}
template<typename T>
void NodeSimple<T>::set_prev(NodeSimple<T>* new_prev_node){
    this->prev_node=new_prev_node;
}
template<typename T>
T NodeSimple<T>::get_data(){
    return this->data;
}
template<typename T>
listAdyacent<int> *NodeSimple<T>::getAdyacentes()
{
    return this->listAdyacentes;
}



#endif // NODESIMPLE_H
