#include <iostream>
#include "./components/typedefs.h"
#include "./components/gates/Buffer.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(const int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    component_io_t inp({{"input", {0, 1, 1, 0, 1, 0, 1, 0}},
                        {"enable", {0}}});
    printComponentIO(inp);

    Buffer buffer(8);
    component_io_t out = buffer.process(inp);
    printComponentIO(out);

    return 0;
}
