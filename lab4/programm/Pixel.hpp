#ifndef PIXEL_H
#define PIXEL_H

#include "Point.hpp"
#include "Color.hpp"

class Pixel {
    private:
        Point point_;
        Color color_;
        
    public:
    	Pixel();
    	Pixel(Point);
    	Pixel(Point, Color);
    	Pixel(const Pixel&);
    	~Pixel();
    	
    	Pixel& operator =(const Pixel&);
    	bool operator ==(Pixel&);
    	
        Point getPoint();
        Color getColor();
        
        void setPoint(Point);
        void setColor(Color);
        
        void print();
        bool read();
        void move(double delta_x, double delta_y);
        double dist(Point&);
};

#endif