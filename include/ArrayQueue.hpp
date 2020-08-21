#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

#include "TDAQueue.hpp"

class ArrayQueue : public TDAQueue{
    public:
        ArrayQueue();
        ~ArrayQueue();
        void clear();
        Object* peek();
        void queue(Object*);
        Object* dequeue();
        bool isEmpty();
        void print();
        int calcLength();
        bool equals(Object*);
        string toString();
    private:
        Object** array;
        int capacity;
        int front, end;
};
#endif