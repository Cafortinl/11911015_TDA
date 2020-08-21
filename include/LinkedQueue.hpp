#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include "TDAQueue.hpp"
#include "Node.hpp"

class LinkedQueue : public TDAQueue{
    public:
        LinkedQueue();
        ~LinkedQueue();
        void clear();
        Object* peek();
        void queue(Object*);
        Object* dequeue();
        bool isEmpty();
        void print();
        bool equals(Object*);
        string toString();
    private:
        Node* front;
        Node* end;
};
#endif