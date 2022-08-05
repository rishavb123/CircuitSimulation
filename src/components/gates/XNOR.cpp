#include "XNOR.h"

XNOR::XNOR()
{
    this->notA = new NOT();
    this->notB = new NOT();
    this->andNotANotB = new AND();
    this->andAB = new AND();
    this->orGate = new OR();
}

XNOR::~XNOR() {}

bool XNOR::validateInput(component_io_t inp) const
{
    return inp.contains("a") &&
           inp.contains("b") &&
           inp["a"].size() == 1 &&
           inp["b"].size() == 1;
}

component_io_t XNOR::getOutput()
{
    component_io_t notA_inp;
    notA_inp["input"] = this->inp["a"];
    component_io_t notA_out = this->notA->process(notA_inp);

    component_io_t notB_inp;
    notB_inp["input"] = this->inp["b"];
    component_io_t notB_out = this->notB->process(notB_inp);

    component_io_t andNotANotB_inp;
    andNotANotB_inp["a"] = notA_out["output"];
    andNotANotB_inp["b"] = notB_out["output"];
    component_io_t andNotANotB_out = this->andNotANotB->process(andNotANotB_inp);

    component_io_t andAB_inp;
    andAB_inp["a"] = this->inp["a"];
    andAB_inp["b"] = this->inp["b"];
    component_io_t andAB_out = this->andAB->process(andAB_inp);

    component_io_t orGate_inp;
    orGate_inp["a"] = andNotANotB_out["output"];
    orGate_inp["b"] = andAB_out["output"];
    return this->orGate->process(orGate_inp);
}