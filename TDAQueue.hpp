#ifndef TDAQUEUE_HPP
#define TDAQUEUE_HPP

#include "Object.hpp"

class TDAQueue{
    public:
        virtual void clear() = 0;
        virtual Object* peek() = 0;
        virtual void queue(Object*) = 0;
        virtual Object* dequeue() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        virtual ~TDAQueue(){};
};
#endif