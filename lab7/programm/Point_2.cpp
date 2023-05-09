//Файл Point_6.cpp: реализация класса Point

#include <cmath>
#include <limits>

#include "Point_2.hpp" 	//включение делает видимым определение
						//класса Point в файле реализации

//#define POINT_TEST
						
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

//** 2.1 ** методы, расширяющие функциональность класса

void Point::Print(ostream& os) const
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
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return flag;
}

//вот как «на самом деле» выглядит метод Move (и другие методы тоже!)
void Point::Move(double dx, double dy)
{
	this->SetX(this->x_ + dx); //методы класса могут использовать
	this->SetY(this->y_ + dy); //другие методы своего класса
}

double Point::Dist(const Point& other) const
{
	return sqrt((x_ - other.x_) * (x_ - other.x_) 
				+ (y_ - other.y_) * (y_ - other.y_));
}

//** 2.2 **
//реализацию friend-функции целесообразно размещать в файле
//реализации класса, потому что она тесно связана с классом;
//она НЕ использует GetX() и GetY() так как имеет непосредственный
//доступ к компонентам x_ и y_
double fdist(const Point& a, const Point& b)
{
	return sqrt((a.x_ - b.x_) * (a.x_ - b.x_) 
				+ (a.y_ - b.y_) * (a.y_ - b.y_));
}

//** 3.1 **
//конструкторы и деструктор (специальные методы) класса
Point::Point()
{
	SetX(0);
	SetY(0);
#ifdef POINT_TEST	
	cout << "Point(): "; Print(); cout << endl; //для отладки
#endif
}

Point::Point(double x)
{
	SetX(x);
	SetY(0);
#ifdef POINT_TEST	
	cout << "Point(double): "; Print(); cout << endl; //для отладки
#endif
}

Point::Point(double x, double y)
{
	SetX(x);
	SetY(y);
#ifdef POINT_TEST	
	cout << "Point(double, double): "; Print(); cout << endl; //для отладки
#endif
}

Point::Point(const Point& other)
: x_(other.x_), y_(other.y_) //список инициализации
{
#ifdef POINT_TEST	
	cout << "Point(const Point&): "; Print(); cout << endl; //для отладки
#endif
}

Point::~Point()
{
#ifdef POINT_TEST	
	cout << "~Point(): "; Print(); cout << endl; //для отладки
#endif
}

//** 3.2 ** оператор присваивания
Point& Point::operator =(const Point& other)
{
	x_ = other.x_;
	y_ = other.y_;
#ifdef POINT_TEST	
	cout << "operator=(const Point&): "; Print(); cout << endl; //для отладки
#endif
	return *this; 	//возвращаем левый операнд
					//вот где явно используется this (см. тему 2)
}

//** 5 ** операторы ввода-вывода
std::ostream& operator <<(std::ostream& os, const Point& point)
{
	point.Print(os);
	return os;
}

std::istream& operator >>(std::istream& is, Point& point)
{
	point.Read(is);
	return is;
}