#include "Splitter.h"

#include <algorithm>

Splitter::Splitter()
{
    this->connection = {};
    this->inpDims = {};
}

Splitter::Splitter(splitter_connection_t connection)
{
    this->connection = connection;

    this->inpDims = {};

    for (auto &output_wire_connection : this->connection)
    {
        for (auto &connection_pair : output_wire_connection)
        {
            if (this->inpDims.size() < connection_pair.first + 1)
            {
                this->inpDims.resize(connection_pair.first + 1);
            }
            this->inpDims[connection_pair.first] = std::max(this->inpDims[connection_pair.first], connection_pair.second + 1);
        }
    }
}

Splitter::~Splitter() {}

bool Splitter::validateInput(component_io_t inp) const
{
    size_t s = this->inpDims.size();
    for (size_t i = 0; i < s; i++)
    {
        if (!inp.contains("input" + std::to_string(i)) &&
            inp["input" + std::to_string(i)].size() != this->inpDims[i])
        {
            return false;
        }
    }
    return true;
}

component_io_t Splitter::getOutput()
{
    component_io_t out;
    int idx = 0;
    for (auto &output_wire_connection : this->connection)
    {
        std::string k = "output_" + std::to_string(idx);
        out[k] = {};
        for (auto &connection_pair : output_wire_connection)
        {
            out[k].push_back(this->inp["input_" + std::to_string(connection_pair.first)][connection_pair.second]);
        }
        idx++;
    }
    return out;
}