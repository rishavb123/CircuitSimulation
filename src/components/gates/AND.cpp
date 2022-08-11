#include "AND.h"

AND::AND()
{
    this->nandGate = new NAND();
    this->notGate = new NOT();
}

AND::~AND() {}

bool AND::validateInput(component_io_t inp) const
{
    return inp.contains("a") &&
           inp.contains("b") &&
           inp["a"].size() == 1 &&
           inp["b"].size() == 1;
}

component_io_t AND::calculateOutput()
{
    component_io_t nor_out = this->nandGate->process(this->inp);

    component_io_t not_inp;
    not_inp["input"] = nor_out["output"];
    return this->notGate->process(not_inp);
}