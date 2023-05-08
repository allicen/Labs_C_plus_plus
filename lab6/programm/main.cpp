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

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	Date date;
	date.read(cin);
	date.print(cout);
	
	Time time;
	time.read(cin);
	time.print(cout);	
	
	return 0;
}