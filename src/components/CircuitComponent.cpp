#include "CircuitComponent.h"

component_io_t CircuitComponent::getInput() const
{
    return this->inp;
}

bool CircuitComponent::validateInput(component_io_t inp) const
{
    return true;
}

void CircuitComponent::setInput(component_io_t inp)
{
    if (this->validateInput(inp))
    {
        this->inp = inp;
    }
    else
    {
        throw "Invalid Input";
    }
}

component_io_t CircuitComponent::process(component_io_t inp)
{
    this->setInput(inp);
    return this->getOutput();
}