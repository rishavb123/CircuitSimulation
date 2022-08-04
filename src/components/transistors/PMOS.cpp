#include "PMOS.h"

PMOS::PMOS() {}
PMOS::~PMOS() {}

bool PMOS::validateInput(component_io_t inp) const
{
    return inp.contains("input") &&
           inp.contains("gate") &&
           inp["input"].size() == 1 &&
           inp["gate"].size() == 1;
}

component_io_t PMOS::getOutput()
{
    bool input = this->inp["input"][0];
    bool gate = this->inp["gate"][0];
    component_io_t out;
    if (gate)
    {
        return out;
    }
    wire_t output{input};
    out["output"] = output;
    return out;
}