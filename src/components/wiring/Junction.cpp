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
        else if (outDim != inp["input_" + std::to_string(i)].size())
        {
            return false;
        }
    }
    for (int j = 0; j < outDim; j++)
    {
        for (size_t i = 1; i < this->numInputs; i++)
        {
            if (inp["input_" + std::to_string(i)][j] != inp["input_" + std::to_string(i - 1)][j])
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
    out["output"] = this->inp["input_0"];
    return out;
}