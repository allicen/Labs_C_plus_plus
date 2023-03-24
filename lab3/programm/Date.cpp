#include <iostream>
#include <cmath>
#include <limits>

#include "Date.hpp"

using namespace std;


Date::Date () {
    set(0, 0, 0);
}

Date::Date(short d, short m, int y) {
    set(d, m, y);
}

Date::Date(const Date& date): day(date.day), month(date.month), year(date.year) { }

Date::~Date() { }

Date& Date::operator =(Date& date) {
    day = date.getDay();
    month = date.getMonth();
    year = date.getYear();
}

bool Date::operator ==(Date& date) {
    Date d = Date(day, month, year);
    return equal(d, date);
}

bool Date::operator >(Date& date) {
    Date d = Date(day, month, year);
    return grater(d, date);
}

bool Date::operator <(Date& date) {
    Date d = Date(day, month, year);
    return less(d, date);
}

short Date::getDay() {
    return day;
}

short Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////


bool Date::set(short d, short m, int y) {
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

void Date::print(){
    string dayCorrect = "", monthCorrect = "";
    
    if (day < 10) {
        dayCorrect = "0";
    }
    
    if (month < 10) {
        monthCorrect = "0";
    }
    
    cout << "Date: " << dayCorrect << day << "." << monthCorrect << month << "." << year << endl;
}

void Date::read() {
    short d, m;
    int y;
    cout << "Input date: " << endl;
    cout << "Input day: ";
    cin >> d;
    cout << "Input month: ";
    cin >> m;
    cout << "Input year: ";
    cin >> y;
}

bool Date::equal(Date one, Date two) {
    return one.day == two.day && one.month == two.month && one.year == two.year;;
}

bool Date::less(Date one, Date two) {
    return one.year < two.year || one.year == two.year && one.month < two.month ||
        one.year == two.year && one.month == two.month && one.day < two.day;
}

bool Date::grater(Date one, Date two) {
    return one.year > two.year || one.year == two.year && one.month > two.month ||
        one.year == two.year && one.month == two.month && one.day > two.day;
}