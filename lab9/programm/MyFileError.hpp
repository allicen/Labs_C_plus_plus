#ifndef MYFILEERROR_H
#define MYFILEERROR_H

#include <stdexcept>
#include <iostream>
#include <string>

class MyFileError : public std::runtime_error {
	public:
		MyFileError(const std::string &error) : std::runtime_error{ error.c_str() } { }	
};


#endif