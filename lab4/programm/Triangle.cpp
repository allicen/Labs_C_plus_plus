#include <iostream>
#include <cmath>
#include <limits>

#include "Triangle.hpp"
#include "Line.hpp"

using namespace std;

Triangle::Triangle() {
    Point a, b, c;
    a.SetX(0);
    a.SetY(0);
    b.SetX(0);
    b.SetY(0);
    c.SetX(0);
    c.SetY(0);
    
    a_ = a;
    b_ = b;
    c_ = c;
}

Triangle::Triangle(Point a, Point b, Point c) {
    a_ = a;
    b_ = b;
    c_ = c;
}

Triangle::Triangle(const Triangle& t): a_(t.a_), b_(t.b_), c_(t.c_) {
    
}

Triangle::~Triangle() {
    
}

Triangle& Triangle::operator =(const Triangle& t) {
    a_ = t.a_;
    b_ = t.b_;
    c_ = t.c_;
}

bool Triangle::operator ==(Triangle& t) const {
    return perimeter() == t.perimeter();
}

bool Triangle::operator >(Triangle& t) const {
    perimeter() > t.perimeter();
}

bool Triangle::operator <(Triangle& t) const {
    perimeter() < t.perimeter();
}


//////////////////////////////////////////
//////////////////////////////////////////

Point Triangle::getA() const {
    return a_;
}

Point Triangle::getB() const {
    return b_;
}

Point Triangle::getC() const {
    return c_;
}

void Triangle::setA(Point a) {
    a_ = a;
}

void Triangle::setB(Point b) {
    b_ = b;
}

void Triangle::setC(Point c) {
    c_ = c;
}

void Triangle::print() const {
    a_.Print();
    b_.Print();
    c_.Print();
}

bool Triangle::read() {
    bool readA = a_.Read("Введите точку A в виде (x,y) ");
    if (!readA) {
        return false;
    }
    
    bool readB = a_.Read("Введите точку B в виде (x,y) ");
    if (!readB) {
        return false;
    }
    
    bool readC = a_.Read("Введите точку C в виде (x,y) ");
    if (!readC) {
        return false;
    }
    
    return true;
}

void Triangle::move(double ax, double ay, double bx, double by, double cx, double cy) {
    a_.Move(ax, ay);
    b_.Move(bx, by);
    c_.Move(cx, cy);
}

double Triangle::perimeter() const {
    Line a, b, c;
    a.setPointA(a_);
    a.setPointB(b_);
    b.setPointA(a_);
    b.setPointB(c_);
    c.setPointA(b_);
    c.setPointB(c_);
    
    return c.length() + b.length() + b.length();
}

Point Triangle::center() const {
    Point p;
    p.SetX((a_.GetX() + b_.GetX() + c_.GetX()) / 3);
    p.SetY((a_.GetY() + b_.GetY() + c_.GetY()) / 3);
    return p;
}