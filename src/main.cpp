#include <iostream>
#include "./components/typedefs.h"
#include "./components/gates/NOT.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(const int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    NOT *n = new NOT();

    component_io_t inp({{"input", {0}}});

    component_io_t out = n->process(inp);

    printComponentIO(inp);
    printComponentIO(out);

    return 0;
}
