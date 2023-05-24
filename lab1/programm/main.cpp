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
#include "ArrayDinMem.hpp"

#include "LinkedList.hpp"
#include "Node.hpp"

int main(int argc, char** argv) {
    
    // Реализация двусвязного списка
    LinkedList list;
    list.pushBack(1.0);
    list.pushBack(2.0);
    list.pushBack(3.0);
    list.pushBack(4.0);
    
    std::cout << "Добавлены элементы в список: ";
    list.print();
    std::cout << std::endl;
    
    list.popFront();
    list.popBack();
    
    std::cout << "Список после удаления элементов сначала и с конца строки: ";
    list.print();
    std::cout << std::endl;
    
    list.pushFront(10.0);
    
    std::cout << "Список после добавления элементов в начало строки: ";
    list.print();
    std::cout << std::endl;
    
    std::cout << "Элемент на позиции 0 из списка: " << list[0]->data << std::endl;

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
    
    custom_type* t = create(10);    

    return 0;
}