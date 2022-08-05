#include <iostream>
#include "./components/typedefs.h"
#include "./components/gates/NOR.h"
#include "./components/extenders/Bitwise.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(const int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    NOR *n = new NOR();

    component_io_t inp({{"a", {0}}, {"b", {0}}});

    component_io_t out = n->process(inp);

    std::cout << "NOR" << std::endl;
    printComponentIO(inp);
    printComponentIO(out);

    Bitwise *bitwiseNor = new Bitwise(8, n);

    component_io_t inp8({{"a", {0, 1, 1, 1, 0, 1, 0, 1}}, {"b", {1, 0, 1, 0, 0, 0, 1, 0}}});

    component_io_t out8 = bitwiseNor->process(inp8);
    std::cout << "Bitwise NOR" << std::endl;
    printComponentIO(inp8);
    printComponentIO(out8);

    return 0;
}
