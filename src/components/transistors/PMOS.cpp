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
    int input = this->inp["input"][0];
    int gate = this->inp["gate"][0];
    component_io_t out;
    wire_t output{gate > 0? input: UNKNOWN};
    out["output"] = output;
    return out;
}