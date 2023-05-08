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
        bool operator ==(Line&) const;
        bool operator >(Line&) const;
        bool operator <(Line&) const;
        
        Point getPointA() const;
        Point getPointB() const;
        void setPointA(Point);
        void setPointB(Point);
        void print(std::ostream & = std::cout) const;
        void read(std::istream & = std::cin);
        void move(double ax, double ay, double bx, double by);
        double length() const;
        Point center() const;    
};

std::ostream& operator <<(std::ostream& os, const Line& line);
std::istream& operator >>(std::istream& is, Line& line);

#endif