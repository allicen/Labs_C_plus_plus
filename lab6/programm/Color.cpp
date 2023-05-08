#include <iostream>

#include "Color.hpp"

using namespace std;

Color::Color() {
    setR(0);
    setG(0);
    setB(0);
    setA(0);
}

Color::Color(float r, float g, float b) {
    setR(r);
    setG(g);
    setB(b);
    setA(0);
}

Color::Color(float r, float g, float b, float a) {
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}

Color::~Color() {
#ifdef COLOR_TEST	
    cout << "~Color(): "; print(); cout << endl; //для отладки
#endif
}


float Color::getR() const {
    return r_;
}

float Color::getG() const {
    return g_;
}

float Color::getB() const{
    return b_;
}

float Color::getA() const{
    return a_;
}

void Color::setR(float r) {
    r_ = r;
}

void Color::setG(float g) {
    g_ = g;    
}

void Color::setB(float b) {
    b_ = b;
}

void Color::setA(float a) {
    a_ = a;
}

Color& Color::operator =(const Color& c) {
	r_ = c.r_;
	g_ = c.g_;
	b_ = c.b_;
	a_ = c.a_;
	
	return *this;
}

bool Color::operator ==(const Color& c) const {
	return r_ == c.getR() && g_ == c.getG() && b_ == c.getB() && a_ == c.getA();
}

void Color::print() const {
	cout << r_ << ", " << g_ << ", " << b_ << ", " << a_;
}
