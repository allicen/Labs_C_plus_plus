#include <iostream>
#include <cmath>
#include <limits>

#include "Time.hpp"

using namespace std;

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

bool Time::equal(Time one, Time two) {
    return one.hour == two.hour && one.minute == two.minute && one.second == two.second;
}

bool Time::less(Time one, Time two) {
    return one.hour < two.hour || one.hour == two.hour && one.minute < two.minute ||
        one.hour == two.hour && one.minute == two.minute && one.second < two.second;
}

bool Time::grater(Time one, Time two) {
    return one.hour > two.hour || one.hour == two.hour && one.minute > two.minute ||
        one.hour == two.hour && one.minute == two.minute && one.second > two.second;
}

bool Time::create() {
    return true;
}

bool Time::resize() {
    return true;
}

bool Time::remove() {
    return true;
}

bool Time::apply() {
    return true;
}