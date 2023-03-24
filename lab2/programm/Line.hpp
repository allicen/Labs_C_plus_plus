#ifndef LINE_H
#define LINE_H

#include "Point.hpp"

class Line {
	private:
		Point a_;
		Point b_;
		
	public:
		Point getPointA();
		Point getPointB();
		void setPointA(Point);
		void setPointB(Point);
		void print();
		void read();
		void move(double ax, double ay, double bx, double by);
		double length();
		Point center();	
};
#endif