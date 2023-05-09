//Файл String_5.hpp – определение класса String

#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
	public:
		// ** 1 **
		String(const char *str ="");
		String(const String&);// = delete;
		~String();
		String& operator =(const String&);// = delete;
		size_t Length() const { return n_; }
		void Print() const { std::cout << s_; }
		// ** 2 **
		String(String&&);
		String & operator =(String&&);	
		//** 3 **
		String &operator +=(const String &rhs);
		friend bool operator ==(const String &lhs, const String &rhs);
		friend bool operator >(const String &lhs, const String &rhs);
		char &operator [](size_t i);
		char operator [](size_t i) const; 	//Возвращаться должно по значению 
											//или по ссылке на константу, 
											//иначе будут возможны 
											//изменения элемента.
		
		//** 4 **
		friend std::ostream &operator <<(std::ostream &, const String &);

	private:
	size_t n_; 	//длина строки (без учета завершающего ‘\0’)
	char *s_; 	//адрес буфера для строки в динамической памяти
				//память выделяется в конструкторе
				//ее следует освободить в деструкторе
				//также для класса следует переопределить
				//конструктор копирования (и оператор присваивания)
};

//** 3 **
String operator +(const String &lhs, const String &rhs);
bool operator !=(const String &lhs, const String &rhs);
bool operator <=(const String &lhs, const String &rhs);
bool operator <(const String &lhs, const String &rhs);
bool operator >=(const String &lhs, const String &rhs);

//** 4 **
std::istream &operator >>(std::istream &, String &);

#endif
