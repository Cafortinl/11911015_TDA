#ifndef NODE_HPP
#define NODE_HPP

#include "Object.hpp"

class Node{
    public:
        Node();
        void setNext(Node*);
        Node* getNext();
        void setPrevious(Node*);
        Node* getPrevious();
        void setData(Object*);
        Object* getData();
        ~Node();
    private:
        Node* next;
        Node* previous;
        Object* data;
};
#endif