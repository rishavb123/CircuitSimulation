#include "PMOS.h"

PMOS::PMOS() {}
PMOS::~PMOS() {}

bool PMOS::validateInput(component_inp_t inp) const
{
    return inp.contains("input") &&
           inp.contains("gate") &&
           inp["input"].size() == 1 &&
           inp["gate"].size() == 1;
}

component_inp_t PMOS::getOutput() const
{
    bool input = this->inp["input"][0];
    bool gate = this->inp["gate"][0];
    if (gate)
    {
        component_inp_t out;
        return out;
    }
    vector<bool> output{input};
    component_inp_t out{{"output", output}};
    return out;
}