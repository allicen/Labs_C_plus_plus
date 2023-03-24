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
#include <cmath>

#include "Date.hpp"
#include "Time.hpp"
#include "Point.hpp"
#include "Pixel.hpp"


int main(int argc, char** argv) {
	
	Date date;
	date.set(8, 5, 2020);
	
	Time time;
	time.set(5, 10, 59);
	
	Point point;
	point.SetX(6);
	point.SetY(8);
	
	Pixel pixel;
	pixel.setPoint(point);
	pixel.setR(0.87);
	pixel.setG(0.55);
	pixel.setB(0.0);
	pixel.setA(0.5);
	
	
	
	return 0;
}