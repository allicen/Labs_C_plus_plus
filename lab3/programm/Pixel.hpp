#ifndef PIXEL_H
#define PIXEL_H

#include "Point.hpp"

class Pixel {
    private:
        Point point_;
        float r_, g_, b_, a_;
        
    public:
    	Pixel();
    	Pixel(Point);
    	Pixel(Point, float, float, float);
    	Pixel(Point, float, float, float, float);
    	Pixel(const Pixel&);
    	~Pixel();
    	
    	Pixel& operator =(const Pixel&);
    	bool operator ==(Pixel&);
    	
        Point getPoint();
        float getR();
        float getG();
        float getB();
        float getA();
        
        void setPoint(Point);
        void setR(float);
        void setG(float);
        void setB(float);
        void setA(float);
        
        void print();
        bool read();
        void move(double delta_x, double delta_y);
        double dist(Point&);
};

#endif