#include <iostream>
#include "./components/typedefs.h"
#include "./components/wiring/Constant.h"
#include "./components/wiring/Junction.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    Constant *c1 = new Constant({1, 0});
    Constant *c2 = new Constant({0, 1});

    component_io_t inp({{"input_0", c1->getOutput()["output"]}, {"input_1", c2->getOutput()["output"]}});

    Junction *j = new Junction(2);
    component_io_t out = j->process(inp);

    printComponentIO(inp);
    printComponentIO(out);

    return 0;
}
