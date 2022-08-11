#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <iostream>

#include "../components/typedefs.h"

void printLine(const int width = 80);
void printComponentIO(component_io_t inp, std::string prefix = "");

#endif // !OUTPUT_H
