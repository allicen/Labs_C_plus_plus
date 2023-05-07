#ifndef TIME_H
#define TIME_H

class Time {
    private:
        short hour;
        short minute;
        short second;
        
    public:
        bool set(short, short, short);
        void print();
        void read();
        bool equal(Time);
        bool less(Time);
        bool grater(Time);
};

#endif