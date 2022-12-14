#include "CircuitComponent.h"

#include <stdexcept>
#include "../utils/macros.h"

component_io_t CircuitComponent::getInput() const
{
    return this->inp;
}

bool CircuitComponent::validateInput(component_io_t inp) const
{
    UNUSED(inp);
    return true;
}

void CircuitComponent::setInput(component_io_t inp)
{
    if (this->validateInput(inp))
    {
        this->inputChanged = true;
        this->inp = inp;
    }
    else
    {
        throw std::invalid_argument("Invalid Input");
    }
}

component_io_t CircuitComponent::getOutput()
{
    if (this->inputChanged)
    {
        this->out = this->calculateOutput();
        this->inputChanged = false;
    }
    return this->out;
}

component_io_t CircuitComponent::process(component_io_t inp)
{
    this->setInput(inp);
    return this->getOutput();
}