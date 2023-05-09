/*
win
-fexec-charset=CP866
-O2
-Wall
-Wextra
-pedantic
-s
UNIX
c++ main.cpp -o main -O2 -Wall -Wextra -pedantic -s
*/

#include <iostream>
#include <fstream>

#include "Stack.hpp"
#include "String_5.hpp"
#include "MyFileError.hpp"

using namespace std;

class Point
{
	public:
		virtual void Print() const
		{
			cout << "Я Точка\n";
		}
		
		virtual ~Point(){}
};

class Circle : public Point
{
	public:
		void Print() const override
		{
			cout << "Я Круг\n";
		}
		
		virtual void Square() const
		{
			cout << "Круг имеет площадь\n";
		}

		~Circle(){}
};

class Cylinder : public Circle
{
	public:
		void Print() const override
		{
			cout << "Я Цилиндр\n";
		}

		void Square() const override
		{
			cout << "Цилиндр имеет площадь\n";
		}

		virtual void Volume() const
		{
			cout << "Цилиндр имеет объем\n";
		}

		~Cylinder(){}
};

void test(const Point *p) {
	cout << "\n------- virtual --------\n";
	
	p->Print();
	
	cout << "\n------- typeid() -------\n";
	
	const type_info &ti = typeid(*p);
	cout << ti.name() << endl;
	
	if( ti == typeid(Circle) )
	{
		const Circle *q = static_cast<const Circle *>(p);
		q->Square();
	}
	
	if( ti == typeid(Cylinder) )
	{
		const Cylinder *q = static_cast<const Cylinder *>(p);
		q->Square();
		q->Volume();
	}
	
	cout <<"\n--- dynamic_cast<>() ---\n";
	
	if(const Circle *q = dynamic_cast<const Circle *>(p); q != nullptr) q->Square();
	if(const Cylinder *q = dynamic_cast<const Cylinder*>(p); q != nullptr) q->Volume();
}


int main() {
	// 9.1. 
	String a;
	
	ofstream out;
	out.open("test.txt");
	if(out.good()) {
		out << a << endl;
		out.close();
		ifstream in;
		in.open("test.txt");
		if(in.good()) {
			in >> a;
			cout << "Строка из файла:" << endl;
			cout << a << endl;
			in.close();
		} else {
			throw MyFileError("Ошибка открытия файла");
		}
	} else {
		throw MyFileError("Ошибка открытия файла");
	}
	
	
	
	// 9.2. 
	Stack<int, 10> iStack;
	
	for(size_t i = 0; !iStack.IsFull(); ++i)
		iStack.Push(i);
	
	iStack.Push(777); 	//контроль переполнения стека
	
	while(!iStack.IsEmpty())
		cout << iStack.Pop() << " ";
	
	iStack.Pop(); 		//контроль исчерпания стека
	
	//Стек для char
	Stack<char, 26> cStack;
	
	for(size_t i = 0; !cStack.IsFull(); ++i)
		cStack.Push('A' + i);
	
	while(!cStack.IsEmpty())
		cout << cStack.Pop();
	
	cout << endl;
	
	
	
	// 9.3.
	Point a; a.Print(); cout<<endl;
	
	Circle b; b.Print(); b.Square(); cout<<endl;
	
	Cylinder c; c.Print(); c.Square(); c.Volume(); cout<<endl;

	cout <<"------------------------\n";
	test(&a);
	cout <<"\n------------------------\n";
	test(&b);
	cout <<"\n------------------------\n";
	test(&c);
	cout <<"\n------------------------\n";
	
	
	return 0;
}
