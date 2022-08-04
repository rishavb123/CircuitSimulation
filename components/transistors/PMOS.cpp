#include "PMOS.h"

PMOS::PMOS() {}
PMOS::~PMOS() {}

bool PMOS::validateInput(bool **inp) const override {
    return length(inp) == 2 &&
           length(inp[0]) == 1 &&
           length(inp[1]) == 1;
}

bool** PMOS::getOutput() const override {
    bool input = this->inp[0][0];
    bool gate = this->inp[1][0];
    if (gate) {
        return {nullptr};
    }
    return {{input}};
}