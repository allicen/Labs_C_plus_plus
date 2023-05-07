#ifndef PIXEL_H
#define PIXEL_H

#include "Point.hpp"
#include "Color.hpp"

class Pixel {
    private:
        Point point_;
        Color color_;
        static size_t count;
        
    public:
    	Pixel();
    	Pixel(Point);
    	Pixel(Point, Color);
    	Pixel(const Pixel&);
    	~Pixel();
    	
    	Pixel& operator =(const Pixel&);
    	bool operator ==(Pixel&) const;
    	
        Point getPoint() const;
        Color getColor() const;
        
        void setPoint(Point);
        void setColor(Color);
        
        void print() const;
        bool read();
        void move(double delta_x, double delta_y);
        double dist(Point&) const;
        
        static size_t getCount() {
        	return count;
		};
};

#endif