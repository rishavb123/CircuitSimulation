#include "NOT.h"

NOT::NOT()
{
    this->nmos = new NMOS();
    this->pmos = new PMOS();
}

NOT::~NOT() {}

bool NOT::validateInput(component_io_t inp) const
{
    return inp.contains("input") &&
           inp["input"].size() == 1;
}

void NOT::setInput(component_io_t inp)
{
    CircuitComponent::setInput(inp);
    
    component_io_t pmos_inp;
    pmos_inp["input"] = wire_t{1};
    pmos_inp["gate"] = inp["input"];
    this->pmos->setInput(pmos_inp);

    component_io_t nmos_inp;
    nmos_inp["input"] = wire_t{0};
    nmos_inp["gate"] = inp["input"];
    this->nmos->setInput(nmos_inp);
}

component_io_t NOT::getOutput()
{
    component_io_t pmos_out = this->pmos->getOutput();
    component_io_t nmos_out = this->nmos->getOutput();
    
    component_io_t out = pmos_out;

    out.insert(nmos_out.begin(), nmos_out.end());

    return out;
}
