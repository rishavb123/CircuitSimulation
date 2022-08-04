#include "Junction.h"

Junction::Junction(size_t numInputs)
{
    this->numInputs = numInputs;
}
Junction::~Junction() {}

bool Junction::validateInput(component_io_t inp) const
{
    int outDim = -1;
    for (size_t i = 0; i < this->numInputs; i++)
    {
        if (!inp.contains("input_" + std::to_string(i)))
        {
            continue;
        }
        else if (outDim == -1)
        {
            outDim = inp["input_" + std::to_string(i)].size();
        }
        else if (outDim != (int)inp["input_" + std::to_string(i)].size())
        {
            return false;
        }
    }
    for (int j = 0; j < outDim; j++)
    {
        bit_t val = 0;
        bool first = true;
        for (size_t i = 0; i < this->numInputs; i++)
        {

            if (!inp.contains("input_" + std::to_string(i)))
            {
                continue;
            }
            if (first)
            {
                first = false;
                val = inp["input_" + std::to_string(i)][j];
            }
            if (inp["input_" + std::to_string(i)][j] != val)
            {
                return false;
            }
        }
    }
    return true;
}

component_io_t Junction::getOutput()
{
    component_io_t out;
    for (size_t i = 0; i < this->numInputs; i++)
    {
        if (inp.contains("input_" + std::to_string(i)))
        {
            out["output"] = this->inp["input_" + std::to_string(i)];
            return out;
        }
    }
    return out;
}