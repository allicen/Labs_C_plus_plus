#include <iostream>
#include <cmath>
#include <limits>

#include "Pixel.hpp"
#include "Point.hpp"

using namespace std;


Pixel::Pixel() {
	Point p;
	p.SetX(0);
	p.SetY(0);
	
    setPoint(p);
    setR(0);
    setG(0);
    setB(0);
    setA(0);
}

Pixel::Pixel(Point p) {
    setPoint(p);
    setR(0);
    setG(0);
    setB(0);
    setA(0);
}

Pixel::Pixel(Point p, float r, float g, float b) {
	setPoint(p);
    setR(r);
    setG(g);
    setB(b);
    setA(0);
}

Pixel::Pixel(Point p, float r, float g, float b, float a) {
	setPoint(p);
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}

Pixel::Pixel(const Pixel& p) : point_(p.point_), r_(p.r_), g_(p.g_), b_(p.b_), a_(p.a_) {
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
	r_ = p.r_;
	g_ = p.g_;
	b_ = p.b_;
	a_ = p.a_;
	
	return *this;
}

bool Pixel::operator ==(Pixel& p) {
	return point_.GetX() == p.point_.GetX() && point_.GetY() == p.point_.GetY()
		   && r_ == p.r_ && g_ == p.g_ && b_ == p.b_ && a_ == p.a_;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

Point Pixel::getPoint(){
    return point_;
}

float Pixel::getR(){
    return r_;
}

float Pixel::getG(){
    return g_;
}

float Pixel::getB(){
    return b_;
}

float Pixel::getA(){
    return a_;
}

void Pixel::setPoint(Point p) {
    point_ = p;
}

void Pixel::setR(float r) {
    r_ = r;
}

void Pixel::setG(float g) {
    g_ = g;    
}

void Pixel::setB(float b) {
    b_ = b;
}

void Pixel::setA(float a) {
    a_ = a;
}

void Pixel::print() {
    cout << "point: (" << point_.GetX() << ", " << point_.GetY() << "), "
         << "color: (" << r_ << ", " << g_ << ", " << b_ << ", " << a_ << ")" << endl;
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
            setR(r);
            setR(g); 
            setR(b); 
            setR(a); 
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