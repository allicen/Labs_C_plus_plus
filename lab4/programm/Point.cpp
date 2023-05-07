//Файл Point_2.cpp: реализация класса Point

#include <iostream>
#include <cmath>
#include <limits>

#include "Point.hpp" 	//включение делает видимым определение
						//класса Point в файле реализации
						
using namespace std;

//В файле реализации имя каждой функции-члена класса должно быть
//полностью квалифицировано при помощи бинарного оператора ::

//** 1 **
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

//** 2.1 **

void Point::Print() const
{
	cout << '(' << x_ << ',' << y_ << ')';
}

bool Point::Read(const char *txt)
{
	bool flag = false;
	if(txt != nullptr) cout << txt;
	double x, y; 
	char c;
	if( cin >> c && c == '(' &&
		cin >> x &&
		cin >> c && c == ',' &&
		cin >> y &&
		cin >> c && c == ')'
	)
	{
		SetX(x); 
		SetY(y);
		flag = true;
	}
	else
	{ 
		cin.clear();
		//while(cin.get() != '\n');
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return flag;
}

//вот как «на самом деле» выглядит метод Move (и другие методы тоже!)
void Point::Move(double dx, double dy)
{
	this->SetX(this->x_ + dx); //методы класса могут использовать
	this->SetY(this->y_ + dy); //другие методы своего класса
}

double Point::Dist(Point& other)
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
