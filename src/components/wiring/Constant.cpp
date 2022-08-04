#include "Constant.h"

Constant::Constant(wire_t value) {
    this->value = value;
}
Constant::~Constant() {}

component_io_t Constant::getOutput() {
    component_io_t out;
    out["output"] = this->value;
    return out;
}

wire_t Constant::getValue() {
    return this->value;
}

void Constant::setValue(wire_t value) {
    this->value = value;
}