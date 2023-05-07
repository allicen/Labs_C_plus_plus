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

#include "Pixel.hpp"
#include "Point.hpp"
#include "Color.hpp"

int main(int argc, char** argv) {
	
	Color color(0, 1, 0, 1);
	Point point;
	point.SetX(1.0);
	point.SetY(2.0);
	Pixel pixel(point, color);
	
	Color color_another(1, 0, 0, 1);
	pixel.setColor(color_another);
	
	return 0;
}