#include <iostream>
#include <cmath>
#include <limits>

#include "Date.hpp"

using namespace std;

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

bool Date::create() {
    return true;
}

bool Date::resize() {
    return true;
}

bool Date::remove() {
    return true;
}

bool Date::apply() {
    return true;
}