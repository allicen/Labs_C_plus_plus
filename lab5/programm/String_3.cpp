//Файл String_3.cpp – реализация класса String

#include <cstring>

#include "String_3.hpp"

//#define STRING_TEST

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

//** 3 **

String &String::operator +=(const String &rh)
{
	char *t = strcpy(new char[n_+rh.n_+1], s_);
	delete[] s_;
	s_ = strcat(t, rh.s_);
	n_ += rh.n_;
	return *this;
}

String operator +(const String &lh, const String &rh)
{
	String t = lh;
	return t += rh;
}

bool operator ==(const String &lh, const String &rh)
{
	return strcmp(lh.s_, rh.s_) == 0;
}

bool operator !=(const String &lh, const String &rh)
{
	return !(lh == rh);
}

bool operator >(const String &lh, const String &rh)
{
	return strcmp(lh.s_, rh.s_) > 0;
}

bool operator <=(const String &lh, const String &rh)
{
	return !(lh > rh);
}

bool operator <(const String &lh, const String &rh)
{
	return rh > lh;
}

bool operator >=(const String &lh, const String &rh)
{
	return !(lh < rh);
}

char &String::operator [](size_t i)
{
	if(i <= n_) return s_[i];
	cerr << "Индекс вне диапазона" << endl;
	static char dummy;
	dummy = '\0';
	return dummy;
}
