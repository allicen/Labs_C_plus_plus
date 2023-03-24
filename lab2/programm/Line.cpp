#include <iostream>
#include <cmath>
#include <limits>

#include "Line.hpp"

using namespace std;

Point Line::getPointA() {
	return a_;
}

Point Line::getPointB() {
	return b_;
}

void Line::setPointA(Point a) {
	a_ = a;
}

void Line::setPointB(Point b) {
	b_ = b;
}

void Line::print() {
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

double Line::length() {
	double ax, ay, bx, by, res;
	ax = a_.GetX();
	ay = a_.GetX();
	bx = b_.GetX();
	by = b_.GetX();
	
	res = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return res;
}

Point Line::center() {
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

