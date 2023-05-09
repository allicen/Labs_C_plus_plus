//Файл Point_2.hpp: определение класса Point

#ifndef POINT_H
#define POINT_H

class Point 			//заголовок описания класса Point
{ 						//начало закрытой (по умолчанию) части класса
	private:	 		//спецификатор закрытой части (секции) класса
		double x_, y_; 	//члены-данные (свойства) класса (подчеркивание в
						//конце – это современные рекомендации экспертов)
	public:		 		//спецификатор открытой части - интерфейса класса
	
		//** 1 ** минимальный интерфейс класса
		//объявленные ниже методы доступа (методы-аксессоры)
		// Get...() и Set...() образуют минимальный интерфейс класса
		double GetX() const	//член-функция (метод) для чтения компонента х_
		{ 					//определение метода в классе неявно объявляет его
			return x_; 		// встроенным (inline) (лучше этого избегать)
		}
		double GetY() const; 		//это прототип метода, а его определение находится
							//здесь же, но после описания класса (так лучше)
		void SetX(double); 	//метод для установки значения компонента х_,
							//определение его и всех остальных методов
		void SetY(double); 	//размещается в файле реализации Point_2.cpp
		
		//** 2.1 ** методы, расширяющие функциональность класса
		void Print(std::ostream & = std::cout) const;//печать координат точки
													//в формате (x,y)
		bool Read(std::istream & = std::cin, const char *txt = nullptr);		//ввод с клавиатуры
													//(с подсказкой)
		void Move(double delta_x, double delta_y); 	//относительное перемещение
													//(от текущей позиции)
		double Dist(Point&) const;		 			//расстояние между точками
													//(имеет один аргумент!)
		
		//** 2.2 ** внешняя функция, объявленная дружественной к классу
		friend double fdist(Point&, Point&); //расстояние
		
		
};

std::ostream& operator <<(std::ostream& os, const Point& point);
std::istream& operator >>(std::istream& is, Point& point);

#endif	