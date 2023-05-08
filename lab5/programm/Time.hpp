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
        
        Time& operator =(const Time&);
        bool operator ==(Time&) const;
        bool operator !=(Time&) const;
        bool operator >(Time&) const;
        bool operator >=(Time&) const;
        bool operator <(Time&) const;
        bool operator <=(Time&) const;
        
        short getHour() const;
        short getMinute() const;
        short getSecond() const;
        
        bool set(short, short, short);
        void print() const;
        void read();
        bool equal(Time) const;
        bool less(Time) const;
        bool grater(Time) const;
};

#endif