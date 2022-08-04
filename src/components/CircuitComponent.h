#ifndef CIRCUIT_COMPONENT_H
#define CIRCUIT_COMPONENT_H

#include "typedefs.h"

class CircuitComponent
{
public:
    component_io_t getInput() const;
    bool validateInput(component_io_t inp) const;
    void setInput(component_io_t inp);
    virtual component_io_t getOutput() = 0;
    component_io_t process(component_io_t inp);

protected:
    component_io_t inp;
};

#endif // !CIRCUIT_COMPONENT_H