#ifndef NOR_H
#define NOR_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "../transistors/PMOS.h"
#include "../transistors/NMOS.h"
#include "../wiring/Junction.h"

class NOR : public CircuitComponent
{
public:
    NOR();
    ~NOR();
    bool validateInput(component_io_t inp) const override;
    component_io_t calculateOutput() override;

private:
    PMOS *pmosA;
    PMOS *pmosB;
    NMOS *nmosA;
    NMOS *nmosB;
    Junction *junction;
};

#endif // !NOR_H