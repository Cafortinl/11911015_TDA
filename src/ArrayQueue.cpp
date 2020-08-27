#include "ArrayQueue.hpp"
#include <iostream>

using namespace std;

ArrayQueue::ArrayQueue(){
    capacity = 1000;
    front = end = 0;
    array = new Object*[capacity];
}

ArrayQueue::~ArrayQueue(){
    int length = calcLength();
    for(int i = front;i < length;i++){
        if(i < capacity)
            delete array[i];
        else
            delete array[(i + front) - length];
    }
    delete[] array;
}

//Método que vacía la cola
void ArrayQueue::clear(){
    int length = calcLength();
    for(int i = front;i <= length;i++){
        if(i < capacity)
            delete array[i];
        else
            delete array[(i + front) - length];
    }
    front = end = 0;
}

//Método que retorna el elemento que sigue en la cola sin quitarlo
Object* ArrayQueue::peek(){
    if(!isEmpty()){
        Object* temp = array[front];
        return temp;
    }else
        return nullptr;
}

//Método que pone en cola un elemento
void ArrayQueue::queue(Object* x){
    if(!(end == front && sizeof(array[front]) != sizeof(Object*))){//revisando si la cola no está llena
        array[end] = x;
        if(end == capacity - 1)
            end = 0;
        else
            end++;
    }else{
        cout << "La cola está llena. Quite un elemento para poder poner otro" << endl;
    }
}

//Método que quita el siguiente elemento de la cola
Object* ArrayQueue::dequeue(){
    if(!isEmpty()){
        Object* temp = array[front];
        array[front] = nullptr;
        if(front + 1 ==  capacity)
            front = 0;
        else
            front++;
        return temp;
    }else
        return nullptr;
}

//Método que retorna verdadero si la cola está vacia, sino falso
bool ArrayQueue::isEmpty(){
    return front == end;
}

//Método que imprime los elementos de la cola en orden de "dequeue"
void ArrayQueue::print(){
    int length = calcLength(), index = 1;
    
    if(!isEmpty()){
        for(int i = front;i < length;i++){
            if(i < capacity)
                cout << index << ". [" << array[i]->toString() << ']' << endl;
            else
                cout << index << ". [" << array[(i + front) - length]->toString() << ']' << endl;
            index++;
        }
    }else
        cout << "La cola está vacía" << endl;
}

//Método que calcula la distancia entre el frente y el final de la cola
int ArrayQueue::calcLength(){
    int length;
    if(end > front)//revisando si el final está antes o después del principio
        length = end;
    else
        length = capacity + end;

    return length;
}

//Método que compara dos objetos
bool ArrayQueue::equals(Object* ptr){
    return false;
}

//Método que representa la lista
string ArrayQueue::toString(){
    print();
    return "";
}