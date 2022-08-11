#ifndef BITWISE_H
#define BITWISE_H

#include "../typedefs.h"
#include "../CircuitComponent.h"

class Bitwise : public CircuitComponent
{
public:
    Bitwise(size_t numBits, CircuitComponent *component);
    ~Bitwise();
    bool validateInput(component_io_t inp) const override;
    component_io_t calculateOutput() override;

private:
    size_t numBits;
    CircuitComponent *component;
};

#endif // !BITWISE_H