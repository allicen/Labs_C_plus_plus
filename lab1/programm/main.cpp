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
#include <typeinfo>


struct date {
	public:
		date(int d, int m, int y) {
			day = d;
			month = m;
			year = y;
		}
		
		bool set(int d, int m, int y) {
			bool correctData = true;
		
			if (m < 0 || m > 12) {
				return !correctData;
			}
			
			if (d < 0 || (m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)) {
				return !correctData;
			}
			
			day = d;
			month = m;
			year = y;
			
			return correctData;
		}
		
		void print() {
			std::string dayCorrect = "", monthCorrect = "";
			
			if (day < 10) {
				dayCorrect = "0";
			}
			
			if (month < 10) {
				monthCorrect = "0";
			}
			
			std::cout << "Date: " << dayCorrect << day << "." << monthCorrect << month << "." << year << std::endl;
		}
		
		date read() {
			date d(day, month, year);
			return d;
		}
		
	private:
		int day;
		int month;
		int year;
};

struct time {
	public:
		time(int h, int m, int s) {
			hour = h;
			minute = m;
			second = s;
		}
		
		bool set(int h, int m, int s) {
			
		}
		
	private:
		int hour;
		int minute;
		int second;
};

int main(int argc, char** argv) {

	int day, month, year, hour, minute, second;
	
	char setDate = 'n';
	char setTime = 'n';
	
	std::cout << "Do you want input date? Input y/n" << std::endl;
	std::cin >> setDate;
	
	if (setDate == 'y') {
		std::cout << "Input day (from 1 to 31): ";
		std::cin >> day;
		std::cout << "Input month (from 1 to 12): ";
		std::cin >> month;
		std::cout << "Input year: ";
		std::cin >> year;
		
		date d(day, month, year);
		bool correctData = d.set(day, month, year);
			
		if (correctData) {
			d.read();
			d.print();
		} else {
			std::cout << "Incorrect date!";
		}
				
	}
	
	
	
	

	
	
	return 0;
}