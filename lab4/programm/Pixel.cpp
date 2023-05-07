#include <iostream>
#include <cmath>
#include <limits>

#include "Pixel.hpp"
#include "Point.hpp"
#include "Color.hpp"

using namespace std;


Pixel::Pixel() {
	Point p;
	p.SetX(0);
	p.SetY(0);
    setPoint(p);
    
    Color color;
    setColor(color);
}

Pixel::Pixel(Point p) {
    setPoint(p);
    
    Color color;
    setColor(color);
}

Pixel::Pixel(Point p, Color color) {
	setPoint(p);
    setColor(color);
}

Pixel::Pixel(const Pixel& p) : point_(p.point_), color_(p.color_) {
    cout << "Copy Pixel: ";
    print();
    cout << endl;
}
 
Pixel::~Pixel() {
#ifdef PIXEL_TEST	
    cout << "~Pixel(): "; print(); cout << endl; //для отладки
#endif
}

Pixel& Pixel::operator =(const Pixel& p) {
	point_ = p.point_;
//	color_ = p.color_;
	
	return *this;
}

bool Pixel::operator ==(Pixel& p) const {
	return point_.GetX() == p.point_.GetX() && point_.GetY() == p.point_.GetY() && color_ == p.getColor();
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

void Pixel::print() const {
    cout << "point: (" << point_.GetX() << ", " << point_.GetY() << "), "
         << "color: (";
	color_.print();
	cout << ")" << endl;
}

bool Pixel::read() {
    bool flag = false;
    bool successReadPoint = point_.Read("Введите Точку в виде (x,y) ");
    if (successReadPoint) {
        cout << "Выедите цвет в виде (R,G,B,A)";
        float r, g, b, a;
        char c;
        
        if( cin >> c && c == '(' &&
            cin >> r &&
            cin >> c && c == ',' &&
            cin >> g &&
            cin >> c && c == ',' &&
            cin >> b &&
            cin >> c && c == ',' &&
            cin >> a &&
            cin >> c && c == ')'
        ) {
        	Color color(r, g, b, a);
        	setColor(color);
            flag = true;
            
        } else { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    return flag;
}

void Pixel::move(double delta_x, double delta_y) {
    Point p;
    p.Move(delta_x, delta_y);
}

double Pixel::dist(Point& b) {
    Point a;
    a.SetX(1);
    a.SetY(6);
    
    return b.Dist(a);
}