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
        bool equal(Date, Date);
        bool less(Date, Date);
        bool grater(Date, Date);
        bool create();
        bool resize();
        bool remove();
        bool apply();
};

#endif