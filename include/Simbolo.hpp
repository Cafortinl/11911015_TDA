#ifndef SIMBOLO_HPP
#define SIMBOLO_HPP

#include "Object.hpp"
#include <string>

using namespace std;

class Simbolo : public Object{
    public:
        Simbolo();
        Simbolo(char);
        ~Simbolo();
        char getSimbolo();
        bool equals(Object*);
        string toString();
    private:
        char simbolo;
};
#endif