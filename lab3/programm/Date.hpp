#ifndef DATE_H
#define DATE_H

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
        bool operator ==(Date&);
        bool operator >(Date&);
        bool operator <(Date&);
        
        bool set(short, short, int);
        short getDay();
        short getMonth();
        int getYear();
        void print();
        void read();
        bool equal(Date);
        bool less(Date);
        bool grater(Date);
};

#endif