#include <iostream>
#include "./components/typedefs.h"
#include "./components/transistors/PMOS.h"
#include "./utils/output.h"

int main(int argc, char const *argv[])
{

    PMOS pmos;
    
    component_io_t inp {{"input", {true}}, {"gate", {true}}};
    component_io_t out = pmos.process(inp);

    std::cout << "Input: " << std::endl;
    printComponentIO(inp);

    std::cout << "Output: " << std::endl;
    printComponentIO(out);

    return 0;
}
