//Файл String_2.cpp – реализация класса String

#include <iostream>
#include <cstring>

#include "String_2.hpp"

#define STRING_TEST

using namespace std;

// ** 1 **

String::String(const char *str)
{
	n_ = strlen(str); 		//вычислили длину строки
	s_ = new char[n_ + 1]; 	//выделили буфер
	//здесь может быть отказ в выделении памяти
	strcpy(s_,str); 		//скопировали в буфер строку
#ifdef STRING_TEST
	std::cout << "String()" << std::endl;
#endif
}

String::~String()
{
	delete[] s_; 	// если new[], то и delete[]
#ifdef STRING_TEST
	std::cout << "~String()" << std::endl;
#endif
}

//здесь может быть отказ в выделении памяти
String::String(const String& str) : n_(str.n_), s_(new char[str.n_ + 1])  
{
	strcpy(s_, str.s_); //глубокая копия
#ifdef STRING_TEST
	std::cout << "String(&)" << std::endl;
#endif
}

String & String::operator =(const String& str)
{
	if(this == &str) return *this; //защита от самоприсваивания
	delete[] s_; 	//освободили блок, которым владели
	n_ = str.n_;
	s_ = new char[n_ + 1]; //здесь может быть отказ в выделении памяти
	strcpy(s_, str.s_);
#ifdef STRING_TEST
	std::cout << "=(&)" << std::endl;
#endif
	return *this; 	//возвращаем левый операнд
}

// ** 2 **

String::String(String&& str) : n_(str.n_), s_ (str.s_)
{
	str.n_ = 0;
	str.s_ = nullptr;
#ifdef STRING_TEST
	std::cout << "String(&&)" << std::endl;
#endif
}

String& String::operator =(String&& str)
{
	if(this == &str) return *this; //защита от самоприсваивания
	delete[] s_; 	//освободили блок, которым владели
	n_ = str.n_;
	s_ = str.s_;
	str.n_ = 0;
	str.s_ = nullptr;
#ifdef STRING_TEST
	std::cout << "=(&&)" << std::endl;
#endif
	return *this; 	//возвращаем левый операнд
}
