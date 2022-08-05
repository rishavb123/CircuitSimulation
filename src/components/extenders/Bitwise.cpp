#include "Bitwise.h"

Bitwise::Bitwise(size_t numBits, CircuitComponent *component)
{
    this->numBits = numBits;
    this->component = component;
}

Bitwise::~Bitwise() {}

bool Bitwise::validateInput(component_io_t inp) const
{
    for (auto const &pair : inp)
    {
        if (pair.second.size() != this->numBits)
        {
            return false;
        }
    }
    return true;
}

component_io_t Bitwise::getOutput()
{
    component_io_t out;
    for (size_t i = 0; i < this->numBits; i++)
    {
        component_io_t singleInp;
        for (auto const &pair : this->inp)
        {
            singleInp[pair.first] = wire_t{pair.second[i]};
        }
        component_io_t singleOutput = this->component->process(singleInp);
        for (auto const &pair : singleOutput)
        {
            if (out.contains(pair.first))
            {
                out[pair.first].push_back(pair.second[0]);
            }
            else
            {
                out[pair.first] = wire_t{pair.second[0]};
            }
        }
    }
    return out;
}