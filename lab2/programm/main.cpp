/*
win
-fexec-charset=CP866
-O2
-Wall
-Wextra
-pedantic
-s
UNIX
c++ main.cpp -o main -O2 -Wall -Wextra -pedantic -s
*/


#include <iostream>
#include <cmath>

#include "Date.hpp"
#include "Time.hpp"
#include "Point.hpp"
#include "Pixel.hpp"
#include "Line.hpp"
#include "Triangle.hpp"

float eps = 0.001;

bool point_in_line (Point p, Line line) {
    double a = line.getPointB().GetY() - line.getPointA().GetY();
    double b = line.getPointA().GetY() - line.getPointA().GetY();
    double c = - a * line.getPointA().GetX() - b * line.getPointA().GetY();
    if (abs(a * p.GetX() + b * p.GetY() + c) > eps) return false;

    return point_in_line (p, line);
}

int main(int argc, char** argv) {
    
    Date date;
    date.set(8, 5, 2020);
    
    Time time;
    time.set(5, 10, 59);
    
    Point point;
    point.SetX(6);
    point.SetY(8);
    
    Pixel pixel;
    pixel.setPoint(point);
    pixel.setR(0.87);
    pixel.setG(0.55);
    pixel.setB(0.0);
    pixel.setA(0.5);
    
    Point a;
    Point b;
    Point c;
    a.SetX(6);
    a.SetY(8);
    b.SetX(7);
    b.SetY(10);
    c.SetX(17);
    c.SetY(10);
    
    Line line;
    line.setPointA(a);
    line.setPointB(b);
    
    Triangle t;
    t.setA(a);
    t.setB(b);
    t.setC(c);
    
    bool check = point_in_line (a, line);
    
    return 0;
}