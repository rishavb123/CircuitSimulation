#include "NOT.h"

NOT::NOT()
{
    this->nmos = new NMOS();
    this->pmos = new PMOS();
    this->junction = new Junction(2);
}

NOT::~NOT() {}

bool NOT::validateInput(component_io_t inp) const
{
    return inp.contains("input") &&
           inp["input"].size() == 1;
}

component_io_t NOT::calculateOutput()
{
    component_io_t pmos_inp;
    pmos_inp["input"] = wire_t{HIGH};
    pmos_inp["gate"] = inp["input"];
    component_io_t pmos_out = this->pmos->process(pmos_inp);

    component_io_t nmos_inp;
    nmos_inp["input"] = wire_t{LOW};
    nmos_inp["gate"] = inp["input"];
    component_io_t nmos_out = this->nmos->process(nmos_inp);

    component_io_t junction_inp;
    junction_inp["input_0"] = pmos_out["output"];
    junction_inp["input_1"] = nmos_out["output"];

    return this->junction->process(junction_inp);
}
