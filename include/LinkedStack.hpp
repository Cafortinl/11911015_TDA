#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

#include "TDAStack.hpp"
#include "Node.hpp"

class LinkedStack : public TDAStack{
    public:
        LinkedStack();
        ~LinkedStack();
        void push(Object*);
        Object* pop();
        Object* top();
        bool isEmpty();
        void print();
        void clear();
    private:
        Node* topNode;
};
#endif