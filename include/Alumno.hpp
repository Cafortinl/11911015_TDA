#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>
#include "Object.hpp"

using namespace std;

class Alumno : public Object{
    private:
        string nombre, cuenta;
    public:
        Alumno();
        Alumno(string n, string c);
        ~Alumno();
        void setNombre(string n);
        string getNombre();
        void setCuenta(string c);
        string getCuenta();
        bool equals(Object*);
        string toString();
};
#endif