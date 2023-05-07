#include "ArrayDinMem.hpp"

#include <iostream>

custom_type* create(size_t size) {
	char *arr = new char[sizeof(size) + size * sizeof(custom_type)];
	*reinterpret_cast<size_t*>(arr) = size;
	return reinterpret_cast<custom_type*>(arr + sizeof(size_t));
}

void remove(custom_type *arr) {
	char *array = reinterpret_cast<char*>(arr) - sizeof(size_t);
	delete[] array;
}

custom_type* resize(custom_type *arr, size_t size) {
	custom_type* arr_new = create(size);
	char *arr_old = reinterpret_cast<char*>(arr) - sizeof(size_t);
	size_t size_old = *reinterpret_cast<size_t*>(arr_old);
	
	size_t size_min = size_old < size ? size_old : size;
	for (size_t i = 0; i < size_min; i++) {
		arr_new[i] = arr[i];
	}
	
	delete[] arr_old;
	return arr_new;
}

// применение функции func поэлементно
void apply(custom_type* data, void(*func)(custom_type&)) {
	size_t size = *reinterpret_cast<size_t*>(reinterpret_cast<char*>(data) - sizeof(size_t));
	for (size_t i = 0; i < size; i++) {
		func(data[i]);
	}
}
