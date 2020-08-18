#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "TDAList.hpp"
#include "Node.hpp"

class LinkedList : public TDAList{
    public:
        LinkedList();
        ~LinkedList();
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
    private:
        Node* start;
        int n;
};
#endif