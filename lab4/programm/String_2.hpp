//Файл String_2.hpp – определение класса String

#ifndef STRING_H
#define STRING_H

class String
{
	public:
		// ** 1 **
		String(const char *str ="");
		String(const String&);// = delete;
		~String();
		String& operator =(const String&);// = delete;
		size_t Length() { return n_; }
		void Print() const { std::cout << s_; }
		// ** 2 **
		String(String&&);
		String & operator =(String&&);

	private:
	size_t n_; 	//длина строки (без учета завершающего ‘\0’)
	char *s_; 	//адрес буфера для строки в динамической памяти
				//память выделяется в конструкторе
				//ее следует освободить в деструкторе
				//также для класса следует переопределить
				//конструктор копирования (и оператор присваивания)
};

#endif
