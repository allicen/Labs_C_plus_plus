#ifndef DATE_H
#define DATE_H

class Date {
    private:
        short day;
        short month;
        int year;
        
    public:
        bool set(short, short, int);
        void print();
        void read();
        bool equal(Date);
        bool less(Date);
        bool grater(Date);
};

#endif