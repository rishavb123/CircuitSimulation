#include "XOR.h"

XOR::XOR()
{
    this->notA = new NOT();
    this->notB = new NOT();
    this->andANotB = new AND();
    this->andNotAB = new AND();
    this->orGate = new OR();
}

XOR::~XOR() {}

bool XOR::validateInput(component_io_t inp) const
{
    return inp.contains("a") &&
           inp.contains("b") &&
           inp["a"].size() == 1 &&
           inp["b"].size() == 1;
}

component_io_t XOR::calculateOutput()
{
    component_io_t notA_inp;
    notA_inp["input"] = this->inp["a"];
    component_io_t notA_out = this->notA->process(notA_inp);

    component_io_t notB_inp;
    notB_inp["input"] = this->inp["b"];
    component_io_t notB_out = this->notB->process(notB_inp);

    component_io_t andANotB_inp;
    andANotB_inp["a"] = this->inp["a"];
    andANotB_inp["b"] = notB_out["output"];
    component_io_t andANotB_out = this->andANotB->process(andANotB_inp);

    component_io_t andNotAB_inp;
    andNotAB_inp["a"] = notA_out["output"];
    andNotAB_inp["b"] = this->inp["b"];
    component_io_t andNotAB_out = this->andNotAB->process(andNotAB_inp);

    component_io_t orGate_inp;
    orGate_inp["a"] = andANotB_out["output"];
    orGate_inp["b"] = andNotAB_out["output"];
    return this->orGate->process(orGate_inp);
}