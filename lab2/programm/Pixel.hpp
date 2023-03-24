#ifndef PIXEL_H
#define PIXEL_H

#include "Point.hpp"

class Pixel {
    private:
        Point point_;
        float r_;
        float g_;
        float b_;
        float a_;
        
    public:
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