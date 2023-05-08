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
#include "String.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	// Сравнение даты
	Date date_one(1, 1, 2003);
	Date date_two(30, 11, 2004);
	Date date_three(30, 11, 2004);
	Date date_four(8, 5, 2023);
	
	if (date_two == date_three) {
		cout << "Даты равны: ";
		date_two.print();
		cout << endl;
	}
	
	if (date_one < date_two) {
		cout << "Дата ";
		date_one.print();
		cout << " меньше даты ";
		date_two.print();
		cout << endl;
	}
	
	if (date_four >= date_two) {
		cout << "Дата ";
		date_four.print();
		cout << " больше или равна дате ";
		date_two.print();
		cout << endl;
	}
	
	
	// Сравнение времени
	Time time_one(0, 0, 0);
	Time time_two(59, 59, 59);
	Time time_three(10, 10, 10);
	Time time_four(10, 10, 10);
	
	if (time_three == time_three) {
		cout << "Время одинаковое" << endl;
	}
	
	if (time_one != time_two) {
		cout << "Время разное" << endl;
	}
	
	if (time_one <= time_three) {
		cout << "Время ";
		time_one.print();
		cout << " меньше или равно времени ";
		time_three.print();
		cout << endl;
	}
	
	
	// Строка
	String line("Пример строки");
	cout << "Первый символ 1 строки: " << line[0] << endl;
	
	const String line2("Константная строка");
	cout << "Первый символ константной строки: " << line2[0] << endl;
	
	
	return 0;
}