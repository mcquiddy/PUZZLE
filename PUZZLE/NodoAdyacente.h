#ifndef NODOADYACENTE_H
#define NODOADYACENTE_H

template <typename T>
class NodeAdyacent {
private:
    NodeAdyacent<T>* next_node;
    NodeAdyacent<T>* prev_node;
    T padre;
    T data;
    bool editable;
    int peso;

public:
     T get_padre();
    NodeAdyacent(T dato) ;
    T get_data();
    void set_next(NodeAdyacent* next_node);
    void set_prev(NodeAdyacent* prev_node);
    void set_padre(T new_padre);
    void setPeso(int pPeso);
    void setEdicion(bool pEdit);
    int getPeso();
    bool isEditable();
    NodeAdyacent* get_next();
    NodeAdyacent* get_prev();

};
/**
 * Constructor of a Node
 * Setting nex_node and prev_node as 0 or NULL
 */
template<typename T>
NodeAdyacent<T>::NodeAdyacent(T dato){
    this->data=dato;
    this->next_node=0;
    this->prev_node=0;
    editable=true;
    peso=0;

}
/**
 * Getters and setters
 */
template<typename T>
/**
 * @brief Node<T>::get_next
 * @return
 */
NodeAdyacent<T>* NodeAdyacent<T>::get_next(){
    return this->next_node;
}
template<typename T>
/**
 * @brief Node<T>::get_prev
 * @return
 */
NodeAdyacent<T>* NodeAdyacent<T>::get_prev(){
    return this->prev_node;
}
template<typename T>
void NodeAdyacent<T>::set_next(NodeAdyacent<T>* new_next_node){
    this->next_node=new_next_node;
}
template<typename T>
void NodeAdyacent<T>::set_prev(NodeAdyacent<T>* new_prev_node){
    this->prev_node=new_prev_node;
}
template<typename T>
T NodeAdyacent<T>::get_data(){
    return this->data;
}
template<typename T>
void NodeAdyacent<T>::set_padre(T new_padre)
{
   this->padre=new_padre;
}
template<typename T>
void NodeAdyacent<T>::setPeso(int pPeso)
{
    this->peso=pPeso;
}
template<typename T>
void NodeAdyacent<T>::setEdicion(bool pEdit)
{
    this->editable=pEdit;
}
template<typename T>
int NodeAdyacent<T>::getPeso()
{
    return this->peso;
}
template<typename T>
bool NodeAdyacent<T>::isEditable()
{
    return this->editable;
}
template<typename T>
T NodeAdyacent<T>::get_padre()
{
  return this->padre;
}


#endif // NODOADYACENTE_H
