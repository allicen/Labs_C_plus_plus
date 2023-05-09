//Файл Pixel_2.hpp
#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include "Point_2.hpp"

class Pixel : public Point
{
	public:
		enum Color : char {blue = 1, green, red = 4, white = 15};
	//Конструкторы	
		Pixel(const Point& p, Color c = white) : Point(p), c_(c) {}
		Pixel(double x = 0, double y = 0, Color c = white) : Point(x, y), c_(c) {}
	//Геттеры	
		Color GetColor() const { return c_;	}
	//Сеттеры	
		void SetColor(Color);
	//Ввод-Вывод
		void Print(std::ostream &os = std::cout) const override;
		bool Read(std::istream& is = std::cin, const char *txt = nullptr) override;
	private:
		Color c_;
};

std::ostream& operator <<(std::ostream& os, const Pixel& pixel);
std::istream& operator >>(std::istream& is, Pixel& pixel);

#endif
