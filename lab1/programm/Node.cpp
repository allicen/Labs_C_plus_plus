#include "Node.hpp"


Node::Node(double data) {
    this->data = data;
    this->prev = this->next = NULL;
}