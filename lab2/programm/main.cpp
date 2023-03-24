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


int main(int argc, char** argv) {
	
	Date date;
	date.set(8, 5, 2020);
	
	Time time;
	time.set(5, 10, 59); 
	
	
	return 0;
}