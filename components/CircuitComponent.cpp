#include "CircuitComponent.h"

bool** CircuitComponent::getInput() const {
    return this->inp;
}

void CircuitComponent::setInput(bool **inp) {
    this->inp = inp;
}

bool** CircuitComponent::process(bool **inp) {
    this->setInput(inp);
    return this->getOutput();
}