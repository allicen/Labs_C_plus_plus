#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.hpp"

class Triangle {
    private:
        Point a_;
        Point b_;
        Point c_;
        
    public:
        Point getA();
        Point getB();
        Point getC();
        void setA(Point);
        void setB(Point);
        void setC(Point);
        void print();
        bool read();
        void move(double, double, double, double, double, double);
        double perimeter();
        Point center();        
};

#endif