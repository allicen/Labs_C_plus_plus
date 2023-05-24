#ifndef MYFILEERROR_H
#define MYFILEERROR_H

#include <stdexcept>
#include <iostream>
#include <string>

class MyFileError : public std::runtime_error {
    private:
        const char* fileName;
    public:
        MyFileError(const std::string &error) : std::runtime_error(error.c_str()), fileName(nullptr) { }
        MyFileError(const std::string &error, const char* file) : std::runtime_error(error.c_str()), fileName(file) { }
        friend std::ostream &operator <<(std::ostream &os, const MyFileError &error);
};


#endif