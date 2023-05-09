/*
win
-fexec-charset=CP866
-O2
-Wall
-Wextra
-pedantic
-s
UNIX
c++ main.cpp -o main -O2 -Wall -Wextra -pedantic -s
*/


#include <iostream>

#include "Shape.hpp"
#include "Point_2.hpp"
#include "Pixel_2.hpp"

using namespace std;

void Print(Shape *p[], size_t n) {
	for(size_t i = 0; i < n; ++i) {
		p[i] -> Print();
		cout << endl;
	}
}

void ScrollUp(Shape *p[], size_t n, double h) {
	
	for(size_t i = 0; i < n; ++i) {
		p[i] -> Move(0, h);
	}
}

void Delete(Shape **p, size_t n) {
	for(size_t i = 0; i < n; ++i) {
		delete p[i];
	}
}


int main(int argc, char** argv) {
	Shape *a[] = {new Point(10, 20), new Pixel(30, 40, Pixel::red)};
	constexpr size_t n = sizeof a / sizeof *a;
	Print(a, n);
	ScrollUp(a, n, 100);
	cout << endl;
	Print(a, n);
	Delete(a, n);
	return 0;
}