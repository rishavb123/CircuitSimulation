#ifndef AND_H
#define AND_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "NAND.h"
#include "NOT.h"

class AND : public CircuitComponent
{
public:
    AND();
    ~AND();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;

private:
    NAND *nandGate;
    NOT *notGate;
};

#endif // !AND_H