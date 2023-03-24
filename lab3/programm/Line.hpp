#ifndef LINE_H
#define LINE_H

#include "Point.hpp"

class Line {
    private:
        Point a_;
        Point b_;
        
    public:
        Line();
        Line(Point, Point);
        Line(Point);
        Line(const Line&);
        ~Line();
        
        Line& operator =(const Line&);
        bool operator ==(Line&);
        bool operator >(Line&);
        bool operator <(Line&);
        
        Point getPointA();
        Point getPointB();
        void setPointA(Point);
        void setPointB(Point);
        void print();
        void read();
        void move(double ax, double ay, double bx, double by);
        double length();
        Point center();    
};
#endif