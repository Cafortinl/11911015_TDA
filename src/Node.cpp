#include "Node.hpp"
#include <iostream>

Node::Node(){
    previous = nullptr;
    next = nullptr;
    data = nullptr;
}

Node::~Node(){
    if(next){
        delete next;
    }
    if(data){
        delete data;
    }
}

void Node::setNext(Node* x){
    next = x;
}

Node* Node::getNext(){
    return next;
}

void Node::setPrevious(Node* x){
    previous = x;
}

Node* Node::getPrevious(){
    return previous;
}

void Node::setData(Object* x){
    data = x;
}

Object* Node::getData(){
    return data;
}
