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
    private:
        Node* front;
        Node* end;
};
#endif