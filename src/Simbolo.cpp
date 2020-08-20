#include "Simbolo.hpp"

Simbolo::Simbolo(){
}

Simbolo::Simbolo(char simb){
    simbolo = simb;
}

Simbolo::~Simbolo(){
}

char Simbolo::getSimbolo(){
    return simbolo;
}

bool Simbolo::equals(Object* x){
    Simbolo* temp = dynamic_cast<Simbolo*>(x);
    bool isEqual = temp->getSimbolo() == simbolo;
    return isEqual;
    delete temp;
}

string Simbolo::toString(){
    return "Simbolo: " + simbolo;
}