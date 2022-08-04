#include "CircuitComponent.h"

bool** CircuitComponent::getInput() const {
    return this->inp;
}

bool CircuitComponent::validateInput(bool **inp) const {
    return true;
}

void CircuitComponent::setInput(bool **inp) {
    if (this->validateInput(inp)) {
        this->inp = inp;
    } else {
        throw "Invalid Input";
    }
}

bool** CircuitComponent::process(bool **inp) {
    this->setInput(inp);
    return this->getOutput();
}