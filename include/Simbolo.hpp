#ifndef SIMBOLO_HPP
#define SIMBOLO_HPP

#include "Object.hpp"
#include <string>

using namespace std;

class Simbolo : public Object{
    public:
        Simbolo();
        Simbolo(string);
        ~Simbolo();
        string getNombre();
        bool equals(Object*);
        string toString();
    private:
        string nombre;
};
#endif