#ifndef TDAQUEUE_HPP
#define TDAQUEUE_HPP

#include "Object.hpp"

class TDAQueue : public Object{
    public:
        virtual void clear() = 0;
        virtual Object* peek() = 0;
        virtual void queue(Object*) = 0;
        virtual Object* dequeue() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        virtual ~TDAQueue(){};
        virtual bool equals(Object*) = 0;
        virtual string toString() = 0;
};
#endif