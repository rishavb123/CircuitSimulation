#include "output.h"

#include <iostream>

void printComponentIO(component_io_t inp)
{
    for (auto& [name, values] : inp)
    {
        std::cout << name << ": ";
        for (const auto& value : values)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}