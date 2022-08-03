#include "CircuitComponent.h"

void CircuitComponent::setInput(bool **inp) {
    this->inp = inp;
}

bool** CircuitComponent::process(bool **inp) {
    setInput(inp);
    return getOutput();
}