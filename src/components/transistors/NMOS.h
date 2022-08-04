#ifndef NMOS_H
#define NMOS_H

#include "../typedefs.h"
#include "../CircuitComponent.h"

class NMOS : public CircuitComponent
{
public:
    NMOS();
    ~NMOS();
    bool validateInput(component_io_t inp) const;
    component_io_t getOutput() override;
};

#endif // !NMOS_H