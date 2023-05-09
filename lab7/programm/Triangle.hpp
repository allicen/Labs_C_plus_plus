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
        void print(std::ostream & = std::cout) const;
        bool read(std::istream & = std::cin);
        void move(double, double, double, double, double, double);
        double perimeter() const;
        Point center() const;        
};

std::ostream& operator <<(std::ostream& os, const Triangle& t);
std::istream& operator >>(std::istream& is, Triangle& t);

#endif