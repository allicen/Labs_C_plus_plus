#ifndef ARRAYDINMEM_H
#define ARRAYDINMEM_H

#include <cstdlib>

template <typename T>T* create(size_t size) {
	char *arr = new char[sizeof(size) + size * sizeof(T)];
	*reinterpret_cast<size_t*>(arr) = size;
	return reinterpret_cast<T*>(arr + sizeof(size_t));
}

template <typename T> void remove(T *arr) {
	char *array = reinterpret_cast<char*>(arr) - sizeof(size_t);
	delete[] array;
}

template <typename T>T* resize(T *arr, size_t size) {
	char* arr_tmp = new char[sizeof(size) + size * sizeof(T)];
	*reinterpret_cast<size_t*>(arr_tmp) = size;
	T* arr_new = reinterpret_cast<T*>(arr_tmp + sizeof(size_t));
	
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
template <typename T, typename F, typename ... args>
void apply(T* data, F func, args&& ... arg) {
	size_t size = *reinterpret_cast<size_t*>(reinterpret_cast<char*>(data) - sizeof(size_t));
	for (size_t i = 0; i < size; i++) {
		(data[i].*func)(arg ...);
	}
}


#endif
