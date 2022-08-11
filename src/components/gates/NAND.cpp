#include "NAND.h"

NAND::NAND()
{
    this->pmosA = new PMOS();
    this->pmosB = new PMOS();
    this->nmosA = new NMOS();
    this->nmosB = new NMOS();
    this->junction = new Junction(3);
}

NAND::~NAND() {}

bool NAND::validateInput(component_io_t inp) const
{
    return inp.contains("a") &&
           inp.contains("b") &&
           inp["a"].size() == 1 &&
           inp["b"].size() == 1;
}

component_io_t NAND::calculateOutput()
{
    component_io_t pmosA_inp;
    pmosA_inp["input"] = wire_t{HIGH};
    pmosA_inp["gate"] = this->inp["a"];
    component_io_t pmosA_out = this->pmosA->process(pmosA_inp);

    component_io_t pmosB_inp;
    pmosB_inp["input"] = wire_t{HIGH};
    pmosB_inp["gate"] = this->inp["b"];
    component_io_t pmosB_out = this->pmosB->process(pmosB_inp);

    component_io_t nmosA_inp;
    nmosA_inp["input"] = wire_t{LOW};
    nmosA_inp["gate"] = this->inp["a"];
    component_io_t nmosA_out = this->nmosA->process(nmosA_inp);

    component_io_t nmosB_inp;
    nmosB_inp["input"] = nmosA_out["output"];
    nmosB_inp["gate"] = this->inp["b"];
    component_io_t nmosB_out = this->nmosB->process(nmosB_inp);

    component_io_t junction_inp;
    junction_inp["input_0"] = pmosA_out["output"];
    junction_inp["input_1"] = pmosB_out["output"];
    junction_inp["input_2"] = nmosB_out["output"];

    return this->junction->process(junction_inp);
}