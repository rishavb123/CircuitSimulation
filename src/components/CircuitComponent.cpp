#include "CircuitComponent.h"

component_inp_t CircuitComponent::getInput() const
{
    return this->inp;
}

bool CircuitComponent::validateInput(component_inp_t inp) const
{
    return true;
}

void CircuitComponent::setInput(component_inp_t inp)
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

component_inp_t CircuitComponent::process(component_inp_t inp)
{
    this->setInput(inp);
    return this->getOutput();
}