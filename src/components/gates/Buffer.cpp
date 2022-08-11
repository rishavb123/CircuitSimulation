#include "Buffer.h"

Buffer::Buffer(size_t bitSize)
{
    this->bitSize = bitSize;
    this->nmos = new NMOS();
}

Buffer::~Buffer() {}

bool Buffer::validateInput(component_io_t inp) const
{
    return inp.contains("input") &&
           inp["input"].size() == bitSize &&
           inp.contains("enable") &&
           inp["enable"].size() == 1;
}

component_io_t Buffer::calculateOutput()
{
    component_io_t out = {{"output", {}}};
    for (size_t i = 0; i < bitSize; i++)
    {
        component_io_t nmos_inp;
        nmos_inp["input"] = wire_t{this->inp["input"][i]};
        nmos_inp["gate"] = this->inp["enable"];
        component_io_t nmos_out = this->nmos->process(nmos_inp);
        out["output"].push_back(nmos_out["output"][0]);
    }
    return out;
}