#include "output.h"

void printComponentIO(component_io_t inp, std::string prefix)
{
    for (auto &[name, values] : inp)
    {
        std::cout << prefix << name << ": ";
        for (const auto &value : values)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}