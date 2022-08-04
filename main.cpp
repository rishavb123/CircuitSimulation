#include <iostream>
#include "./utils/arrayutils.h"
#include "./components/transistors/PMOS.h"

int main(int argc, char const *argv[])
{

    PMOS pmos;
    bool **inp = {{true}, {true}};
    bool **out = pmos.process(inp);
    std::cout << "Input: " << std::endl;
    printArray(inp);
    std::cout << "Output: " << std::endl;
    printArray(out);

    return 0;
}
