#ifndef TIME_H
#define TIME_H

class Time {
    private:
        short hour;
        short minute;
        short second;
        
    public:
        Time();
        Time(short, short, int);
        Time(const Time&);
        ~Time();
        
        Time& operator =(Time&);
        bool operator ==(Time&);
        bool operator >(Time&);
        bool operator <(Time&);
        
        short getHour();
        short getMinute();
        short getSecond();
        
        bool set(short, short, short);
        void print();
        void read();
        bool equal(Time);
        bool less(Time);
        bool grater(Time);
};

#endif