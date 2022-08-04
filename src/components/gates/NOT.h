#ifndef NOT_H
#define NOT_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "../transistors/PMOS.h"
#include "../transistors/NMOS.h"

class NOT : public CircuitComponent
{
public:
    NOT();
    ~NOT();
    bool validateInput(component_io_t inp) const override;
    void setInput(component_io_t inp) override;
    component_io_t getOutput() override;
private:
    PMOS *pmos;
    NMOS *nmos;
};

#endif // !NOT_H
