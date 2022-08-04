#ifndef PMOS_H
#define PMOS_H

#include "../typedefs.h"
#include "../CircuitComponent.h"

class PMOS : public CircuitComponent
{
public:
    PMOS();
    ~PMOS();
    bool validateInput(component_inp_t inp) const;
    component_inp_t getOutput() const override;
};

#endif // !PMOS_H
