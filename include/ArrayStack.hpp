#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include "TDAStack.hpp"
#include "Object.hpp"

class ArrayStack : public TDAStack{
    public:
        ArrayStack();
        ~ArrayStack();
        void push(Object*);
        Object* pop();
        Object* top();
        bool isEmpty();
        void print();
        void clear();
        bool equals(Object*);
        string toString();
    private:
        Object** array;
        int tope;
        int capacity;
};
#endif