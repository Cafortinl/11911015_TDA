#include "Simbolo.hpp"

Simbolo::Simbolo(){
}

Simbolo::Simbolo(string n){
    nombre = n;
}

Simbolo::~Simbolo(){
}

string Simbolo::getNombre(){
    return nombre;
}

bool Simbolo::equals(Object* x){
    Simbolo* temp = dynamic_cast<Simbolo*>(x);
    return temp->getNombre() == nombre;
    delete temp;
}

string Simbolo::toString(){
    return "Simbolo: " + nombre;
}