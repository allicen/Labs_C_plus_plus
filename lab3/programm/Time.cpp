#include <iostream>
#include <cmath>
#include <limits>

#include "Time.hpp"

using namespace std;

Time::Time() {
    set(0, 0, 0);
}

Time::Time(short h, short m, int s) {
    set(h, m, s);
}

Time::Time(const Time& t): hour(t.hour), minute(t.minute), second(t.second) { }

Time::~Time() { }

Time& Time::operator =(Time& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}

bool Time::operator ==(Time& t) {
    return equal(t);
}

bool Time::operator >(Time& t) {
    return equal(t);
}

bool Time::operator <(Time& t) {
    return equal(t);
}

short Time::getHour() {
    return hour;
}

short Time::getMinute() {
    return minute;
}

short Time::getSecond() {
    return second;
}


//////////////////////////////////////////////
//////////////////////////////////////////////

bool Time::set(short h, short m, short s) {
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

void Time::print(){
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

void Time::read() {
    short h, m, s;
    std::cout << "Input time: " << std::endl;
    std::cout << "Input hour: ";
    std::cin >> h;
    std::cout << "Input minute: ";
    std::cin >> m;
    std::cout << "Input second: ";
    std::cin >> s;
}

bool Time::equal(Time two) {
    return hour == two.hour && minute == two.minute && second == two.second;
}

bool Time::less(Time two) {
    return hour < two.hour || hour == two.hour && minute < two.minute ||
        hour == two.hour && minute == two.minute && second < two.second;
}

bool Time::grater(Time two) {
    return hour > two.hour || hour == two.hour && minute > two.minute ||
        hour == two.hour && minute == two.minute && second > two.second;
}
