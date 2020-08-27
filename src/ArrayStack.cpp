#include "ArrayStack.hpp"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack(){
    capacity = 1000;
    tope = 0;
    array = new Object*[capacity];
}

ArrayStack::~ArrayStack(){
    for(int i = 0;i < tope;i++){
        delete array[i];
    }
    delete[] array;
}

//Método que agrega un elemento a la pila
void ArrayStack::push(Object* x){
    array[tope] = x;
    tope++;
}

//Método que quita el último elemento en la pila
Object* ArrayStack::pop(){
    if(!isEmpty()){
        Object* temp = array[tope - 1];
        array[tope - 1] = nullptr;
        tope--;
        return temp;
    }else
        return nullptr;
}

//Método que muestra el último elemento de la pila sin quitarlo
Object* ArrayStack::top(){
    if(!isEmpty()){
        Object* temp = array[tope - 1];
        return temp;
    }else
        return nullptr;
}

//Método que retorna verdadero si la pila está vacía, sino falso
bool ArrayStack::isEmpty(){
    return tope == 0;
}

//Método que imprime los elementos de la pila en orden de salida
void ArrayStack::print(){
    int index = 1;
    if(!isEmpty()){
        for(int i = tope -1;i >= 0;i--){
            cout << index << ". [" << array[i]->toString() << ']' << endl;
            index++;
        }
    }else
        cout << "La pila está vacía" << endl;
}

//Método que vacía la lista
void ArrayStack::clear(){
    for(int i = 0;i < tope;i++){
        delete array[i];
    }
    tope = 0;
}

//Método que compara dos objetos
bool ArrayStack::equals(Object* ptr){
    return false;
}

//Método que representa la lista
string ArrayStack::toString(){
    print();
    return "";
}