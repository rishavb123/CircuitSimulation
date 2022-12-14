#ifndef JUNCTION_H
#define JUNCTION_H

#include "../typedefs.h"
#include "../CircuitComponent.h"

class Junction : public CircuitComponent
{
public:
    Junction(size_t numInputs = 2);
    ~Junction();
    bool validateInput(component_io_t inp) const override;
    component_io_t calculateOutput() override;

private:
    size_t numInputs;
};

#endif // !JUNCTION_H