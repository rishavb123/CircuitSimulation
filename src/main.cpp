#include <iostream>
#include "./components/typedefs.h"
#include "./components/transistors/NMOS.h"
#include "./components/wiring/Constant.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    Constant constant({1});

    NMOS nmos;

    component_io_t inp {{"input", {0}}, {"gate", constant.getOutput()["output"]}};
    component_io_t out = nmos.process(inp);

    std::cout << "Input: " << std::endl;
    printComponentIO(inp, "\t");

    std::cout << "Output: " << std::endl;
    printComponentIO(out, "\t");

    return 0;
}
