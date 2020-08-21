#ifndef TDALIST_HPP
#define TDALIST_HPP

#include "Object.hpp"

using namespace std;

class TDAList : public Object{
    public:
        virtual bool insert(int, Object*) = 0;
        virtual Object* remove(int) = 0;
        virtual void clear() = 0;
        virtual Object* get(int) = 0;
        virtual Object* getNext(int) = 0;
        virtual Object* getPrevious(int) = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        virtual Object* first() = 0;
        virtual int find(Object*) = 0;
        virtual ~TDAList(){};
        virtual int size() = 0;
        virtual bool equals(Object*) = 0;
        virtual string toString() = 0;
};
#endif