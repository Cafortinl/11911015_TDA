#ifndef TDASTACK_HPP
#define TDASTACK_HPP

#include "Object.hpp"

class TDAStack : public Object{
    public:
        virtual void push(Object*) = 0;
        virtual Object* pop() = 0;
        virtual Object* top() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        virtual void clear() = 0;
        virtual ~TDAStack(){};
        virtual bool equals(Object*) = 0;
        virtual string toString() = 0;
};
#endif