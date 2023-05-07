#include <iostream>
#include <cmath>
#include <limits>

#include "Line.hpp"

using namespace std;

Line::Line() {
    Point a;
    Point b;
    a.SetX(0);
    a.SetY(0);
    b.SetX(0);
    b.SetY(0);
    
    a_ = a;
    b_ = b;
}

Line::Line(Point a, Point b) {
    a_ = a;
    b_ = b;
}

Line::Line(Point a) {
    Point b;
    b.SetX(0);
    b.SetY(0);
    
    a_ = a;
    b_ = b;
}

Line::Line(const Line& line): a_(line.a_), b_(line.b_) {
    
}

Line::~Line() {
    
}

Line& Line::operator =(const Line& line) {
    a_ = line.a_;
    b_ = line.b_;
    
    return *this;
}

bool Line::operator ==(Line& line) const {
    return line.length() ==  length();
}

bool Line::operator >(Line& line) const {
    return  length() > line.length();
}

bool Line::operator <(Line& line) const {
    return  length() < line.length();
}


//////////////////////////////////////////////
//////////////////////////////////////////////

Point Line::getPointA() const {
    return a_;
}

Point Line::getPointB() const {
    return b_;
}

void Line::setPointA(Point a) {
    a_ = a;
}

void Line::setPointB(Point b) {
    b_ = b;
}

void Line::print() const {
    cout << "Point A: ";
    a_.Print();
    cout << "Point B: ";
    b_.Print();
}

void Line::read() {
    a_.Read("Введите точку A в виде (x,y) ");
    b_.Read("Введите точку B в виде (x,y) ");
}

void Line::move(double ax, double ay, double bx, double by) {
    a_.Move(ax, ay);
    b_.Move(bx, by);
}

double Line::length() const {
    double ax, ay, bx, by, res;
    ax = a_.GetX();
    ay = a_.GetX();
    bx = b_.GetX();
    by = b_.GetX();
    
    res = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
    return res;
}

Point Line::center() const {
    double ax, ay, bx, by, res;
    ax = a_.GetX();
    ay = a_.GetX();
    bx = b_.GetX();
    by = b_.GetX();
    
    Point p;
    p.SetX(ax + bx / 2);
    p.SetY(ay + by / 2);
    
    return p;
}