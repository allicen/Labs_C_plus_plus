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
        
        void print(std::ostream & = std::cout) const;
        bool read(std::istream & = std::cin);
        void move(double delta_x, double delta_y);
        double dist(Point&) const;
        
        static size_t getCount() {
        	return count;
		};
};

std::ostream& operator <<(std::ostream& os, const Pixel& pixel);
std::istream& operator >>(std::istream& is, Pixel& pixel);

#endif