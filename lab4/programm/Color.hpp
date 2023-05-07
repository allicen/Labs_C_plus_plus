#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <cmath>
#include <limits>

class Color {
	public:
		Color();
		Color(float, float, float);
		Color(float, float, float, float);
		~Color();
		
		void print();
		
		Color& operator =(const Color&);
    	bool operator ==(const Color&);
		
		void setR(float);
		void setG(float);
		void setB(float);
		void setA(float);
		
		float getR() const;
	    float getG() const;
	    float getB() const;
	    float getA() const;
	
	private:
		float r_;
		float g_;
		float b_;
		float a_;
};

#endif