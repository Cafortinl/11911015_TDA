#include "LinkedStack.hpp"
#include <iostream>

using namespace std;

LinkedStack::LinkedStack(){
    topNode = nullptr;
}

LinkedStack::~LinkedStack(){
    if(topNode)
        delete topNode;
}

//Método que agrega un elemento x a la pila
void LinkedStack::push(Object* x){
    if(isEmpty())//Instanciando topNode en el caso de que la pila esté vacía
        topNode = new Node;
    Node* nNode = new Node;
    Node* temp = topNode;
    nNode->setData(x);
    nNode->setPrevious(temp->getPrevious());
    nNode->setNext(temp);
    temp->setPrevious(nNode);
    topNode = nNode;
}

//Método que saca el elemento en el tope de la pila y retorna su valor, retorna nullptr en caso de que la pila esté vacía
Object* LinkedStack::pop(){
    if(!isEmpty()){//Validando que la pila no esté vacía
        Node* temp = topNode;
        if(temp->getNext()){
            temp->getNext()->setPrevious(temp->getPrevious());
            topNode = temp->getNext();
        }
        temp->setNext(nullptr);
        temp->setPrevious(nullptr);
        Object* returnValue = temp->getData();
        temp->setData(nullptr);
        delete temp;
        if(!topNode->getNext())//Validando si al sacar el elemento la pila queda vacía
            clear();
        return returnValue;
    }else
        return nullptr;
}

//Método que retorna el valor del elemento que está en el tope de la pila sin eliminarlo, retornando nullptr si la pila está vacía 
Object* LinkedStack::top(){
    if(!isEmpty())
        return topNode->getData();
    else
        return nullptr;
}

//Método que retorna true si la pila está vacía, sino false
bool LinkedStack::isEmpty(){
    return topNode == nullptr;
}

//Método que imprime los elementos de la pila en orden de salida
void LinkedStack::print(){
    if(!isEmpty()){
        Node* temp = topNode;
        int i = 1;
        while(temp->getNext()){
            cout << i << ". [" << temp->getData()->toString() << ']' << endl;
            temp = temp->getNext();
            i++;
        }
        temp = nullptr;
        delete temp;
    }else
        cout << "La lista está vacía" << endl;
}

//Método que vacía la pila
void LinkedStack::clear(){
    if(!isEmpty()){
        delete topNode;
        topNode = nullptr;
    }else{
        cout << "La lista ya está vacía" << endl;
    }
}

//Método que compara 2 objetos
bool LinkedStack::equals(Object* ptr){
    return false;
}

//Método que representa la lista
string LinkedStack::toString(){
    print();
    return "";
}