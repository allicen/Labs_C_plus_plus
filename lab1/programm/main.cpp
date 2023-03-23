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
#include "DateTime.hpp"

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