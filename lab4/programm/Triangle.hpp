#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.hpp"

class Triangle {
    private:
        Point a_;
        Point b_;
        Point c_;
        
    public:
        Triangle();
        Triangle(Point, Point, Point);
        Triangle(const Triangle&);
        ~Triangle();
        
        Triangle& operator =(const Triangle&);
        bool operator ==(Triangle&) const;
        bool operator >(Triangle&) const;
        bool operator <(Triangle&) const;
        
        Point getA() const;
        Point getB() const;
        Point getC() const;
        void setA(Point);
        void setB(Point);
        void setC(Point);
        void print() const;
        bool read();
        void move(double, double, double, double, double, double);
        double perimeter() const;
        Point center() const;        
};

#endif