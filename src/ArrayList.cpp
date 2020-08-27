#include "ArrayList.hpp"
#include <iostream>

using namespace std;

ArrayList::ArrayList(){
    capacity = 1000;
    n = 0;
    array = new Object*[capacity];
}

ArrayList::~ArrayList(){
    for(int i = 0;i < n;i++){
        delete array[i];
    }
    delete[] array;
}

//Método que inserta el objeto x en la posición p si la posición es válida
bool ArrayList::insert(int p, Object* x){
    if(p - 1 >= 0 && p - 1 <= n){//validar si el rango es válido
        if(p-1 == n){
            array[p-1] = x;
            n++;
            return true;
        }else{//determinar los corrimientos necesarios y realizarlos
            for(int i = n;i > p - 1;i--){
                array[i] = array[i-1];
            }
            array[p-1] = x;
            n++;
            return true;
        }
    }else{//si el rango no es válido
        return false;
    }
}

//Método que elimina el objeto en la posición p si la posición es válida
Object* ArrayList::remove(int p){
    if(p-1 >= 0 && p-1 < n){//validar si el rango es válido
        Object* temp = array[p - 1];
        if(p-1 != n){
            for(int i = p-1;i < n;i++){
                array[i] = array[i+1];
            }
            array[n] = nullptr;
            n--;
            return temp;
        }else{
            array[p-1] = nullptr;
            n--;
            return temp;
        }
        delete temp;
    }else{
        return nullptr;
    }
}

//Método que vacía la lista
void ArrayList::clear(){
    for(int i = 0;i < n;i++){
        delete array[i];
    }
    n = 0;
}

//Método que retorna el objeto en la posición p si la posición es válida
Object* ArrayList::get(int p){
    if(p-1 >= 0 && p-1 <= n){//validar si el rango es válido
        return array[p-1];
    }else{
        return nullptr;
    }
}

//Método que retorna el objeto que le siguie a la posición p si la posición es válida
Object* ArrayList::getNext(int p){
    return get(p + 1);
}

//Método que retorna el objeto que está antes de la posición p si la posición es válida
Object* ArrayList::getPrevious(int p){
    return get(p - 1);
}

//Método que retorna verdadero si la lista está vacía, sino falso
bool ArrayList::isEmpty(){
    return n == 0;
}

//Método que imprime los elementos de la lista en el orden en el que aparecen
void ArrayList::print(){
    if(!isEmpty()){
        for(int i = 0;i < n;i++){
            cout << i+1 << ". [" << array[i]->toString() << ']' << endl;
        }
    }else
        cout << "La lista está vacía" << endl;
}

//Método que retorna el primer elemento de la lista
Object* ArrayList::first(){
    if(!isEmpty())
        return array[0];
    else
        return nullptr;
}

//Método retorna la posición de un objeto si está en la lista
int ArrayList::find(Object* x){
    for(int i = 0;i < n;i++){
        if(array[i]->equals(x)){
            return i+1;
        }
    }
    return -1;
}

//Método que retorna el tamaño de la lista
int ArrayList::size(){
    return n;
}

//Método que compara 2 objetos
bool ArrayList::equals(Object* ptr){
    return false;
}

//Método que representa la lista
string ArrayList::toString(){
    print();
    return "";
}
