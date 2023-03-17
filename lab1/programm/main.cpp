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
		
			if (m < 1 || m > 12) {
				return !correctData;
			}
			
			if (d < 1 || (m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) || d > 31) {
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
			bool correctTime = true;
			
			if (h < 0 || h > 23) {
				return !correctTime;
			}
			
			if (m < 0 || m > 59) {
				return !correctTime;
			}
			
			if (s < 0 || s > 59) {
				return !correctTime;
			}
			
			hour = h;
			minute = m;
			second = s;
			
			return correctTime;
		}
		
		void print() {
			std::string hourCorrect = "", minuteCorrect = "", secondCorrect = "";
			
			if (hour < 10) {
				hourCorrect = "0";
			}
			
			if (minute < 10) {
				minuteCorrect = "0";
			}
			
			if (second < 10) {
				secondCorrect = "0";
			}
			
			std::cout << hourCorrect << hour << ":" << minuteCorrect << minute << ":" << secondCorrect << second << std::endl;
		}
		
		time read() {
			time t(hour, minute, second);
			return t;
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
			std::cout << "Incorrect date!" << std::endl;
		}
	}
	
	std::cout << "Do you want input time? Input y/n" << std::endl;
	std::cin >> setTime;
	
	if (setTime == 'y') {
		std::cout << "Input hour (from 0 to 23): ";
		std::cin >> hour;
		std::cout << "Input minute (from 0 to 59): ";
		std::cin >> minute;
		std::cout << "Input second (from 0 to 59): ";
		std::cin >> second;
		
		time t(hour, minute, second);
		bool correctTime = t.set(hour, minute, second);
			
		if (correctTime) {
			t.read();
			t.print();
		} else {
			std::cout << "Incorrect time!" << std::endl;
		}
	}
		
		
		
		
		
		
	
	
	

	
	
	return 0;
}