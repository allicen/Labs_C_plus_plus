#include "LinkedList.hpp"
#include "Node.hpp"

LinkedList::LinkedList() {
    this->head = this->tail = NULL;
}

LinkedList::~LinkedList() {
    while (head != NULL) {
        popFront();
    }
}

Node* LinkedList::pushFront(double data) {
    Node* ptr = new Node(data);
    
    ptr->next = this->head;
    if (head != NULL)
    head->prev = ptr;
    if (tail == NULL)
    tail = ptr;
    head = ptr;
    
    return ptr;
}


Node* LinkedList::pushBack(double data) {
    Node* ptr = new Node(data);
    
    ptr->prev = tail;
    if (tail != NULL)
    tail->next = ptr;
    if (head == NULL)
    head = ptr;
    tail = ptr;
    
    return ptr;
}

void LinkedList::popFront() {
    if (head == NULL) {
        return;
    }
    
    Node* ptr = head->next;
    if (ptr != NULL) {
        ptr->prev = NULL;
    } else {
        tail = NULL;
    }
    
    delete head;
    head = ptr;
}


void LinkedList::popBack() {
    if (tail == NULL) {
        return;    
    } 
    
    Node* ptr = tail->prev;
    if (ptr != NULL) {
        ptr->next = NULL;
    } else {
        head = NULL;
    }
    
    delete tail;
    tail = ptr;
}

Node* LinkedList::getAt(int index) {
    Node* ptr = head;
    int n = 0;
    
    while (n != index) {
        if (ptr == NULL)
        return ptr;
        ptr = ptr->next;
        n++;
    }
    
    return ptr;
}
    
    
Node* LinkedList::operator[] (int index) {
    return getAt(index);
}

void LinkedList::print() {
    for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
         std::cout << ptr->data << " ";
    }
}