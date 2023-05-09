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
	
	
	
	//Стек для int
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
	
	return 0;
}
