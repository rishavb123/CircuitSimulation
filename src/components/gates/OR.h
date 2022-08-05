#ifndef OR_H
#define OR_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "NOR.h"
#include "NOT.h"

class OR : public CircuitComponent
{
public:
    OR();
    ~OR();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;

private:
    NOR *norGate;
    NOT *notGate;
};

#endif // !OR_H