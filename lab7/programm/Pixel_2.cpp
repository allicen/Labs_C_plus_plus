//Файл Pixel_2.cpp

#include <limits>

#include "Pixel_2.hpp"

using namespace std;

void Pixel::SetColor(Color c)
{
	c_ = c;
}

void Pixel::Print(ostream& os) const
{
	os << static_cast<Point>(*this); 
	char ch = ' ';
	switch(c_)
	{
		case blue:
			ch = 'b';
			break;
		case green:
			ch = 'g';
			break;
		case red:
			ch = 'r';
			break;
		case white:
			ch = 'w';
	}
	os << ch;
}

bool Pixel::Read(istream& is, const char *txt)
{
	bool flag = false;
	if(this -> Point::Read(is, txt))
	{
		char ch;
		if(is >> ch)
		{	
			switch(ch)
			{
				case 'b':
					SetColor(blue);
					flag = true;
					break;
				case 'g':
					SetColor(green);
					flag = true;
					break;
				case 'r':
					SetColor(red);
					flag = true;
					break;
				case 'w':
					SetColor(white);
					flag = true;	
			}
		}
		if(!(is && flag))
		{
			is.clear(); 
			is.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return flag;
}

std::ostream& operator <<(std::ostream& os, const Pixel& pixel)
{
	pixel.Print(os);
	return os;
}

std::istream& operator >>(std::istream& is, Pixel& pixel)
{
	pixel.Read(is);
	return is;
}
