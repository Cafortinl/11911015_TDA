#include "LinkedQueue.hpp"
#include <iostream>

using namespace std;

LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
    n = 0;
}

LinkedQueue::~LinkedQueue(){
    if(front)
        delete front;
}

//Método que vacía la cola
void LinkedQueue::clear(){
    if(front)
        delete front;
    front = nullptr;
    end = nullptr;
    n = 0;
}

//Método que retorna el elemento que sigue en la cola sin quitarlo de la cola. Si la cola está vacía retorna nullptr
Object* LinkedQueue::peek(){
    if(!isEmpty())
        return front->getData();
    else
        return nullptr;
}

//Método que pone en cola el elemento x
void LinkedQueue::queue(Object* x){
    if(isEmpty()){//Validando el caso en el que la lista esté vacía
        front = new Node;
        end = front;
        front->setData(x);
        n++;
    }else{
        Node* temp = end;
        Node* nNode = new Node;
        nNode->setData(x);
        nNode->setPrevious(temp);
        temp->setNext(nNode);
        end = nNode;
        n++;
    }
}

//Método que quita el elemento que sigue en la lista retornando su valor. Retorna nullptr si la cola está vacía
Object* LinkedQueue::dequeue(){
    if(!isEmpty()){
        Node* temp = front;
        Object* returnValue = temp->getData();
        if(temp->getNext()){//Validando que no sea el último nodo
            temp->getNext()->setPrevious(nullptr);
            front = temp->getNext();
        }
        temp->setNext(nullptr);
        temp->setData(nullptr);
        if(n - 1 == 0)//Validando en caso que la cola quede vacía
            clear();
        else{
            delete temp;
            n--;
        }
        return returnValue;
    }else
        return nullptr;
}

//Método que retorna true si la cola está vacía, sino false
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}

//Método que imprime los elementos de la cola en orden de salida. Si la cola está vacía lo indica
void LinkedQueue::print(){
    if(!isEmpty()){
        Node* temp = front;
        for(int i = 0;i < n;i++){
            cout << to_string(i + 1) + '[' + temp->getData()->toString() + ']' << endl;
            temp = temp->getNext();
        }
        temp = nullptr;
        delete temp;
    }else
        cout << "La cola está vacía" << endl;
}
