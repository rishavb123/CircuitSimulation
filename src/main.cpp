#include <iostream>
#include "./components/typedefs.h"
#include "./components/wiring/Splitter.h"
#include "./utils/macros.h"
#include "./utils/output.h"

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    Splitter splitter({
        {{0, 0}, {0, 1}, {0, 2}},
        {{0, 3}, {1, 0}, {1, 1}},
        {{1, 2}, {1, 3}, {2, 0}},
        {{2, 1}, {2, 2}, {2, 3}}
    });

    component_io_t inp{
        {"input_0", {1, 0, 0, 1}},
        {"input_1", {0, 0, 1, 1}},
        {"input_2", {1, 1, 0, 1}}
    };

    component_io_t out = splitter.process(inp);

    std::cout << "Input: " << std::endl;
    printComponentIO(inp, "\t");
    std::cout << "Output: " << std::endl;
    printComponentIO(out, "\t");

    return 0;
}
