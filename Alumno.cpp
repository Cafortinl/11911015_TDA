#include "Alumno.hpp"
#include <string>

using namespace std;

Alumno::Alumno(){
}

Alumno::Alumno(string n, string c){
    nombre = n;
    cuenta = c;
}

void Alumno::setNombre(string n){
    nombre = n;
}

string Alumno::getNombre(){
    return nombre;
}

void Alumno::setCuenta(string c){
    cuenta = c;
}

string Alumno::getCuenta(){
    return cuenta;
}

string Alumno::toString(){
    return "Nombre: " + nombre + " Cuenta: " + cuenta;
}

Alumno::~Alumno(){
}

bool Alumno::equals(Object* x){
    Alumno* temp = dynamic_cast<Alumno*>(x);
    return temp->getCuenta() == cuenta;
    delete temp;
}