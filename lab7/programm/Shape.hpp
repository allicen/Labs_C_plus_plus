//Файл Shape_1.hpp

#ifndef SHAPE_H
#define SHAPE_H

class Shape //ABC - Abstract Base Class (interface)
{
	public:
		virtual ~Shape() {}
		
		//чистые виртуальные функции
		virtual bool Read(std::istream & = std::cin, const char *txt = nullptr) = 0;
		virtual void Print(std::ostream & = std::cout) const = 0;	
		virtual void Move(double delta_x, double delta_y) = 0;
};

#endif
