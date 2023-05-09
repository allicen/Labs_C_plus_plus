//Шаблон класса "Стек" (LIFO) ограниченного размера size

#ifndef STACK_H
#define STACK_H

#include <iostream>

template<typename T, size_t size>
class Stack
{
		T stk[size];
		size_t top;
	public:
		Stack() : top(0) { }
		void Push(const T &);
		T Pop();
		bool IsEmpty() { return !top; }
		bool IsFull() { return top == size; }
};

template<typename T, size_t size>
void Stack<T, size>::Push(const T &x)
{
	if(IsFull()) std::cerr << "\nСтек полон\n";
	else stk[top++] = x;
}

template<typename T, size_t size>
T Stack<T, size>::Pop()
{
	if(IsEmpty()) 
	{
		std::cerr << "\nСтек пуст\n";
		return T();
	}
	else
		return stk[--top];
}

#endif
