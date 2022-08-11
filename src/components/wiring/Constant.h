#ifndef CONSTANT_H
#define CONSTANT_H

#include "../CircuitComponent.h"
#include "../typedefs.h"

class Constant : public CircuitComponent
{
public:
    Constant(wire_t value);
    ~Constant();
    component_io_t calculateOutput() override;
    void setValue(wire_t value);
    wire_t getValue();

private:
    wire_t value;
};

#endif // !CONSTANT_H