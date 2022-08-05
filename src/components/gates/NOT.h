#ifndef NOT_H
#define NOT_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "../transistors/PMOS.h"
#include "../transistors/NMOS.h"
#include "../wiring/Junction.h"

class NOT : public CircuitComponent
{
public:
    NOT();
    ~NOT();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;
private:
    PMOS *pmos;
    NMOS *nmos;
    Junction *junction;
};

#endif // !NOT_H
