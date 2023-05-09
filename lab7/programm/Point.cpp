//Файл Point_2.cpp: реализация класса Point

#include <iostream>
#include <cmath>
#include <limits>

#include "Point.hpp" 	//включение делает видимым определение
						//класса Point в файле реализации
						
using namespace std;


ostream& operator <<(ostream &os, const Point &point) {
	point.Print(os);
	return os;
}

istream& operator >>(istream &is, Point &point) {
	point.Read(is);
	return is;
}

void Point::SetX(double x)
{
	x_ = x;
}

void Point::SetY(double y)
{
	y_ = y;
}

double Point::GetY() const {
	return x_;	
}


void Point::Print(std::ostream& os) const
{
	os << '(' << x_ << ',' << y_ << ')';
}

bool Point::Read(std::istream& is, const char *txt)
{
	bool flag = false;
	if(txt != nullptr) cout << txt;
	double x, y; 
	char c;
	if( is >> c && c == '(' &&
		is >> x &&
		is >> c && c == ',' &&
		is >> y &&
		is >> c && c == ')'
	)
	{
		SetX(x); 
		SetY(y);
		flag = true;
	}
	else
	{ 
	}
	return flag;
}

//вот как «на самом деле» выглядит метод Move (и другие методы тоже!)
void Point::Move(double dx, double dy)
{
	this->SetX(this->x_ + dx); //методы класса могут использовать
	this->SetY(this->y_ + dy); //другие методы своего класса
}

double Point::Dist(Point& other) const
{
	return sqrt((x_ - other.x_) * (x_ - other.x_) 
				+ (y_ - other.y_) * (y_ - other.y_));
}

//** 2.2 **
//реализацию friend-функции целесообразно размещать в файле
//реализации класса, потому что она тесно связана с классом;
//она НЕ использует GetX() и GetY() так как имеет непосредственный
//доступ к компонентам x_ и y_
double fdist(Point& a, Point& b)
{
	return sqrt((a.x_ - b.x_) * (a.x_ - b.x_) 
				+ (a.y_ - b.y_) * (a.y_ - b.y_));
}
