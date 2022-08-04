#include "PMOS.h"

PMOS::PMOS() {}
PMOS::~PMOS() {}

bool PMOS::validateInput(bool **inp) const {
    return length(inp) == 2 &&
           length(inp[0]) == 1 &&
           length(inp[1]) == 1;
}

bool** PMOS::getOutput() const {
    bool input = this->inp[0][0];
    bool gate = this->inp[1][0];
    if (gate) {
        return {nullptr};
    }
    bool* outputWire = new bool[1] {input};
    bool** output = new bool*[1] {outputWire};
    return output;
}