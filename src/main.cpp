#include <iostream>
#include "./components/typedefs.h"
#include "./components/gates/XOR.h"
#include "./components/extenders/Bitwise.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(const int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    XOR *gate = new XOR();

    component_io_t inp({{"a", {1}}, {"b", {1}}});

    component_io_t out = gate->process(inp);

    std::cout << "XOR" << std::endl;
    printComponentIO(inp);
    printComponentIO(out);

    Bitwise *bitwise = new Bitwise(4, gate);

    component_io_t inp8({{"a", {0, 0, 1, 1}}, {"b", {0, 1, 0, 1}}});

    component_io_t out8 = bitwise->process(inp8);
    std::cout << "Bitwise XOR" << std::endl;
    printComponentIO(inp8);
    printComponentIO(out8);

    return 0;
}
