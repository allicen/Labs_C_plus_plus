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
        void print() const;
        void read();
        bool equal(Date) const;
        bool less(Date) const;
        bool grater(Date) const;
};

#endif