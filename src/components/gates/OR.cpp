#include "OR.h"

OR::OR()
{
    this->norGate = new NOR();
    this->notGate = new NOT();
}

OR::~OR() {}

bool OR::validateInput(component_io_t inp) const
{
    return inp.contains("a") &&
           inp.contains("b") &&
           inp["a"].size() == 1 &&
           inp["b"].size() == 1;
}

component_io_t OR::calculateOutput()
{
    component_io_t nor_out = this->norGate->process(this->inp);

    component_io_t not_inp;
    not_inp["input"] = nor_out["output"];
    return this->notGate->process(not_inp);
}