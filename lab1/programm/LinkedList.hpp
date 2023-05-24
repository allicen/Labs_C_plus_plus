#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"

#include <iostream>

class LinkedList {
    public:
        Node* head, * tail;
    
    public:
        LinkedList();
        ~LinkedList();
        Node* pushFront(double);
        Node* pushBack(double);
        void popFront();
        void popBack();
        Node* getAt(int);
        void print();
        
        Node* operator[](int);
};

#endif