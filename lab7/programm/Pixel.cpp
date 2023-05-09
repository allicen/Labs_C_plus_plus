#include <iostream>
#include <cmath>
#include <limits>

#include "Pixel.hpp"
#include "Point.hpp"
#include "Color.hpp"

using namespace std;

size_t Pixel::count = 0;


Pixel::Pixel() {
	Point p;
	p.SetX(0);
	p.SetY(0);
    setPoint(p);
    
    Color color;
    setColor(color);
    
    Pixel::count++;
}

Pixel::Pixel(Point p) {
    setPoint(p);
    
    Color color;
    setColor(color);
    
    Pixel::count++;
}

Pixel::Pixel(Point p, Color color) {
	setPoint(p);
    setColor(color);
    
    Pixel::count++;
}

Pixel::Pixel(const Pixel& p) : point_(p.point_), color_(p.color_) {
    cout << "Copy Pixel: ";
    print();
    cout << endl;
}
 
Pixel::~Pixel() {
	Pixel::count--;
}

Pixel& Pixel::operator =(const Pixel& p) {
	point_ = p.point_;
	color_ = p.color_;
	
	return *this;
}

bool Pixel::operator ==(Pixel& p) const {
	return point_.GetX() == p.point_.GetX() && point_.GetY() == p.point_.GetY() && color_ == p.getColor();
}

ostream& operator <<(ostream &os, const Pixel &pixel) {
	pixel.print(os);
	return os;
}

istream& operator >>(istream &is, Pixel &pixel) {
	pixel.read(is);
	return is;
}

Point Pixel::getPoint() const {
    return point_;
}

Color Pixel::getColor() const {
    return color_;
}

void Pixel::setColor(Color color) {
	color_ = color;
}

void Pixel::setPoint(Point point) {
	point_ = point;
}

void Pixel::print(std::ostream& os) const {
    os << "point: (" << point_.GetX() << ", " << point_.GetY() << "), "
         << "color: (";
	color_.print();
	os << ")" << endl;
}

bool Pixel::read(std::istream& is) {
    bool flag = false;
    bool successReadPoint = point_.Read(is, "Введите Точку в виде (x,y) ");
    if (successReadPoint) {
        cout << "Выедите цвет в виде (R,G,B,A)";
        float r, g, b, a;
        char c;
        
        if( is >> c && c == '(' &&
            is >> r &&
            is >> c && c == ',' &&
            is >> g &&
            is >> c && c == ',' &&
            is >> b &&
            is >> c && c == ',' &&
            is >> a &&
            is >> c && c == ')'
        ) {
        	Color color(r, g, b, a);
        	setColor(color);
            flag = true;
            
        } else { 
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    return flag;
}

void Pixel::move(double delta_x, double delta_y) {
    Point p;
    p.Move(delta_x, delta_y);
}

double Pixel::dist(Point& b) const {
    Point a;
    a.SetX(1);
    a.SetY(6);
    
    return b.Dist(a);
}


//static size_t getCount() {
//	return Pixel::count_;
//}
