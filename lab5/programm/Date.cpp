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

bool Date::operator ==(Date& date) const {
    return equal(date);
}

bool Date::operator !=(Date& date) const {
    return !equal(date);
}

bool Date::operator >(Date& date) const {
    return grater(date);
}

bool Date::operator >=(Date& date) const {
    return grater(date) || equal(date);
}

bool Date::operator <(Date& date) const {
    return less(date);
}

bool Date::operator <=(Date& date) const {
    return less(date) || equal(date);
}


short Date::getDay() const {
    return day;
}

short Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}


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

void Date::print() const {
    string dayCorrect = "", monthCorrect = "";
    
    if (day < 10) {
        dayCorrect = "0";
    }
    
    if (month < 10) {
        monthCorrect = "0";
    }
    
    cout << dayCorrect << day << "." << monthCorrect << month << "." << year;
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

bool Date::equal(Date two) const {
    return day == two.day && month == two.month && year == two.year;;
}

bool Date::less(Date two) const {
    return year < two.year || year == two.year && month < two.month ||
        year == two.year && month == two.month && day < two.day;
}

bool Date::grater(Date two) const {
    return year > two.year || year == two.year && month > two.month ||
        year == two.year && month == two.month && day > two.day;
}