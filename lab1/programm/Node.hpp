#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
	public:
		double data;
		Node* prev, * next;
	
	public:
		Node(double);
};

#endif