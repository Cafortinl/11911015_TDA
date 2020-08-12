#include "LinkedStack.hpp"
#include <iostream>

using namespace std;

LinkedStack::LinkedStack(){
    topNode = nullptr;
    n = 0;
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
    n++;
}

//Método que saca el elemento en el tope de la pila y retorna su valor, retorna nullptr en caso de que la pila esté vacía
Object* LinkedStack::pop(){
    if(!isEmpty()){//Validando que la pila no esté vacía
        Node* temp = topNode;
        temp->getNext()->setPrevious(temp->getPrevious());
        topNode = temp->getNext();
        temp->setNext(nullptr);
        temp->setPrevious(nullptr);
        Object* returnValue = temp->getData();
        temp->setData(nullptr);
        delete temp;
        if(n - 1 == 0){//Validando si al sacar el elemento la pila queda vacía
            clear();
        }else
            n--;
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
        for(int i = 0;i < n;i++){
            cout << to_string(i + 1) + '[' + temp->getData()->toString() + ']' << endl;
            temp = temp->getNext();
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
        n = 0;
    }else{
        cout << "La lista ya está vacía" << endl;
    }
}
