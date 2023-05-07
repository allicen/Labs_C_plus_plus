#ifndef ARRAYDINMEM_H
#define ARRAYDINMEM_H

#include <cstdlib>
#include "DateTime.hpp"

typedef date custom_type;

custom_type* create(size_t);
void remove(custom_type*);
custom_type* resize(custom_type*, size_t);
void apply(custom_type*, void(*)(custom_type&));

#endif
