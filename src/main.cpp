#include <iostream>
#include "./components/typedefs.h"
#include "./components/gates/NOT.h"
#include "./components/extenders/Bitwise.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(const int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    NOT *n = new NOT();

    component_io_t inp({{"input", {0}}});

    component_io_t out = n->process(inp);

    std::cout << "NOT" << std::endl;
    printComponentIO(inp);
    printComponentIO(out);

    Bitwise *bitwiseNot = new Bitwise(8, n);

    component_io_t inp8({{"input", {0, 1, 1, 1, 0, 1, 0, 1}}});

    component_io_t out8 = bitwiseNot->process(inp8);
    std::cout << "Bitwise NOT" << std::endl;
    printComponentIO(inp8);
    printComponentIO(out8);

    return 0;
}
