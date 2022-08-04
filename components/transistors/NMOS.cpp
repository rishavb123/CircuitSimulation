#include "NMOS.h"

NMOS::NMOS() {}
NMOS::~NMOS() {}

bool NMOS::validateInput(bool **inp) const override {
    return length(inp) == 2 &&
           length(inp[0]) == 1 &&
           length(inp[1]) == 1;
}

bool** NMOS::getOutput() const override {
    bool input = this->inp[0][0];
    bool gate = this->inp[1][0];
    if (!gate)
    {
        return {nullptr};
    }
    return {{input}};
}