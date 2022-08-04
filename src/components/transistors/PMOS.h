#ifndef PMOS_H
#define PMOS_H

#include "../typedefs.h"
#include "../CircuitComponent.h"

class PMOS : public CircuitComponent
{
public:
    PMOS();
    ~PMOS();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;
};

#endif // !PMOS_H
