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

#include "ArrayDinMem.hpp"
#include "Date.hpp"
#include "Time.hpp"


int main(int argc, char** argv) {
    size_t size = 5;
    Date* date = create<Date>(size);
    for (size_t i = 0; i < size; i++) {
        date[i].set(i+3, i+10, i+2000);
    }
    
    std::cout << "Результат добавления дат: " << std::endl;
    apply(date, Date::print, std::cout);
    
    remove(date);
    
    Time* time = create<Time>(size);
    for (size_t i = 0; i < size; i++) {
        time[i].set(i+2, i+1, i+3);
    }
    
    std::cout << "Результат добавления времени: " << std::endl;
    apply(time, Time::print, std::cout);
    
    remove(time);
    
    return 0;
}