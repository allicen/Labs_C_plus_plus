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
        bool equal(Time, Time);
        bool less(Time, Time);
        bool grater(Time, Time);
        bool create();
        bool resize();
        bool remove();
        bool apply();
};

#endif