#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
    private:
        short day;
        short month;
        int year;
        
    public:
        Date();
        Date(short, short, int);
        Date(const Date&);
        ~Date();
        
        Date& operator =(Date&);
        bool operator ==(Date&) const;
        bool operator !=(Date&) const;
        bool operator >(Date&) const;
        bool operator >=(Date&) const;
        bool operator <(Date&) const;
        bool operator <=(Date&) const;
        
        bool set(short, short, int);
        short getDay() const;
        short getMonth() const;
        int getYear() const;
        void print(std::ostream & = std::cout) const;
        void read(std::istream & = std::cin);
        bool equal(Date) const;
        bool less(Date) const;
        bool grater(Date) const;
};

std::ostream& operator <<(std::ostream& os, const Date& date);
std::istream& operator >>(std::istream& is, Date& date);

#endif