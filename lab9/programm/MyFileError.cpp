#include "MyFileError.hpp"

std::ostream &operator <<(std::ostream &os, const MyFileError &error) {
	return os << error.what() << ": " << (error.fileName == nullptr ? "null" : error.fileName); 
}