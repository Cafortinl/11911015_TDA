#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include "TDAList.hpp"

using namespace std;

class ArrayList : public TDAList{
    public:
        ArrayList();
        ~ArrayList();
        bool insert(int, Object*);
        Object* remove(int);
        void clear();
        Object* get(int);
        Object* getNext(int);
        Object* getPrevious(int);
        bool isEmpty();
        void print();
        Object* first();
        int find(Object*);
        int size();
    protected:
        Object** array;
        int capacity;
        int n;
};
#endif