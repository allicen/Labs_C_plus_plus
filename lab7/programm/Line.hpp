#ifndef LINE_H
#define LINE_H

#include "Point_2.hpp"
#include "Shape.hpp"

class Line : public Shape {
    private:
        Point a_;
        Point b_;
        
    public:
        Line();
        Line(const Point& a, const Point& b);
        Line(const Line&);
        ~Line();
        
        Line& operator =(const Line&);
        bool operator ==(Line&) const;
        bool operator >(Line&) const;
        bool operator <(Line&) const;
        
        const Point getPointA() const;
        const Point getPointB() const;
        
        void setPointA(Point);
        void setPointB(Point);
        
        void Print(std::ostream & = std::cout) const override;
        bool Read(std::istream & = std::cin, const char *txt = nullptr) override;
        void Move(double ax, double ay, double bx, double by);
        double length() const;
        Point center() const;    
};

std::ostream& operator <<(std::ostream& os, const Line& line);
std::istream& operator >>(std::istream& is, Line& line);

#endif