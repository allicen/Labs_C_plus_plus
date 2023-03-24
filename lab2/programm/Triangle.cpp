#include <iostream>
#include <cmath>
#include <limits>

#include "Triangle.hpp"
#include "Line.hpp"

using namespace std;

Point Triangle::getA() {
    return a_;
}

Point Triangle::getB() {
    return b_;
}

Point Triangle::getC() {
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

void Triangle::print() {
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

double Triangle::perimeter() {
    Line a, b, c;
    a.setPointA(a_);
    a.setPointB(b_);
    b.setPointA(a_);
    b.setPointB(c_);
    c.setPointA(b_);
    c.setPointB(c_);
    
    return c.length() + b.length() + b.length();
}

Point Triangle::center() {
    Point p;
    p.SetX((a_.GetX() + b_.GetX() + c_.GetX()) / 3);
    p.SetY((a_.GetY() + b_.GetY() + c_.GetY()) / 3);
    return p;
}