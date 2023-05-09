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
#include "Stack.hpp"

using namespace std;

int main() 
{
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
