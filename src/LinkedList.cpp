#include "LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    start = nullptr;
    n = 0;
}

LinkedList::~LinkedList(){
    delete start;
}

//Método que inserta el elemento x en la posición p si esta es válida
bool LinkedList::insert(int p, Object* x){
    if(p - 1 >= 0 && p - 1 <= n){//Validando que p esté dentro del rango válido
        if(isEmpty())//Validando si la lista está vacía
            start = new Node;
        int hops = p - 1;//Calculando el numero de "saltos" que deben darse para llegar a p
        Node* temp = start;
        for(int i = 0;i < hops;i++){
            if(temp->getNext())//Validando que el nodo que le sigue al actual no sea nullptr
                temp = temp->getNext();
        }
        Node* nNode = new Node;
        nNode->setData(x);
        nNode->setPrevious(temp->getPrevious());//Haciendo el cambio de nodos
        if(start != temp)
            temp->getPrevious()->setNext(nNode);
        nNode->setNext(temp);
        temp->setPrevious(nNode);
        if(start == temp)//Validando el caso en el que el nodo que se agregó está en la primera posición de la lista
            start = nNode;
        n++;
        return true;
    }else
        return false;
}

//Método que desenlaza el elemento en la posición p de la lista y lo retorna si la posición es válida, sino returna nullptr
Object* LinkedList::remove(int p){
    if(p - 1 >= 0 && p - 1 < n){//Válidando el rango de p
        int hops = p - 1;
        Node* temp = start;
        for(int i = 0;i < hops;i++){
            if(temp->getNext())
                temp = temp->getNext();
        }
        if(temp->getPrevious())//Validando si temp tiene un nodo anterior
            temp->getPrevious()->setNext(temp->getNext());
        if(temp->getNext())//Validando si temp tiene un nodo siguiente
            temp->getNext()->setPrevious(temp->getPrevious());
        if(temp == start)
            start = temp->getNext();
        temp->setNext(nullptr);
        temp->setPrevious(nullptr);
        Object* returnValue = temp->getData();
        temp->setData(nullptr);
        delete temp;
        n--;
        return returnValue;
    }else
        return nullptr;
}

//Método que limpia la lista dejándola sin elementos
void LinkedList::clear(){
    if(start){
        delete start;
        n = 0;
        start = nullptr;
    }
}

//Método que retorna el valor del elemento en la posición p si es válida, sino retorna nullptr
Object* LinkedList::get(int p){
    if(p - 1 >= 0 && p - 1 < n){//Validando el rango de p
        int hops = p - 1;
        Node* temp = start;
        for(int i = 0;i < hops;i++){
            if(temp->getNext())
                temp = temp->getNext();
        }
        return temp->getData();
    }else
        return nullptr;
}

//Método que retorna el valor del elemento en la posición que le sigue a p si es válida, sino retorna nullptr
Object* LinkedList::getNext(int p){
    return get(p + 1);
}

//Método que retorna el valor del elemento en la posición que antecede p si es válida, sino retorna nullptr
Object* LinkedList::getPrevious(int p){
    return get(p - 1);
}

//Método que retorna true si la lista está vacía, sino false
bool LinkedList::isEmpty(){
    return start == nullptr;
}

//Método que imprime los elementos de la lista en el orden en el que aparecen
void LinkedList::print(){
    if(!isEmpty()){
        Node* temp = start;
        for(int i = 0;i < n;i++){
            cout << to_string(i + 1) + ". [" + temp->getData()->toString() + ']' << endl;
            if(temp->getNext())
                temp = temp->getNext();
        }
        temp = nullptr;
        delete temp;
    }else
        cout << "La lista está vacía" << endl;
}

//Método que retorna el elemento que está al principio de la lista
Object* LinkedList::first(){
    if(!isEmpty())
        return start->getData();
    else
        return nullptr;
}

//Método que recibe un objeto y busca la posición en la que está regresando esta misma si existe el elemento, sino retorna -1
int LinkedList::find(Object* x){
    Node* temp = start;
    for(int i = 0;i < n;i++){
        if(temp->getData()->equals(x))
            return i + 1;
        temp = temp->getNext();
    }
    return -1;
}

//Método que retorna el número de elementos que hay en la lista
int LinkedList::size(){
    return n;
}

//Método que compara 2 objetos
bool LinkedList::equals(Object* ptr){
    return false;
}

//Método que representa la lista
string LinkedList::toString(){
    print();
    return "";
}