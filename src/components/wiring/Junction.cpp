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
            return false;
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
            if (inp["input_" + std::to_string(i)][j] == UNKNOWN)
            {
                continue;
            }
            else if (first)
            {
                first = false;
                val = inp["input_" + std::to_string(i)][j];
            }
            else if (inp["input_" + std::to_string(i)][j] != val)
            {
                return false;
            }
        }
    }
    return true;
}

component_io_t Junction::calculateOutput()
{
    component_io_t out;
    out["output"] = {};
    size_t outDim = this->inp["input_0"].size();
    out["output"].resize(outDim, UNKNOWN);
    for (size_t i = 0; i < this->numInputs; i++)
    {
        for (size_t j = 0; j < outDim; j++)
        {
            if (out["output"][j] == UNKNOWN && this->inp["input_" + std::to_string(i)][j] != UNKNOWN)
            {
                out["output"][j] = this->inp["input_" + std::to_string(i)][j];
            }
        }
    }
    return out;
}