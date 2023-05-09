#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point_2.hpp"
#include "Shape.hpp"

class Triangle : public Shape {
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
        void Print(std::ostream & = std::cout) const override;
        bool Read(std::istream & = std::cin, const char *txt = nullptr) override;
        void Move(double, double, double, double, double, double);
        double perimeter() const;
        Point center() const;        
};

std::ostream& operator <<(std::ostream& os, const Triangle& t);
std::istream& operator >>(std::istream& is, Triangle& t);

#endif