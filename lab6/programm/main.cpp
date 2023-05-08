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

#include "Date.hpp"
#include "Time.hpp"
#include "Triangle.hpp"
#include "Pixel.hpp"
#include "Line.hpp"
#include "Point.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	Date date;
	date.read(cin);
	date.print(cout);
	
	Time time;
	time.read(cin);
	time.print(cout);
	
	Point point;
	point.Read(cin);
	point.Print(cout);
	
	Line line;
	line.read(cin);
	line.print(cout);
	
	Triangle t;
	t.read(cin);
	t.print(cout);
	
	return 0;
}