#ifndef CIRCUIT_COMPONENT_H
#define CIRCUIT_COMPONENT_H

#include "typedefs.h"

class CircuitComponent
{
public:
    component_io_t getInput() const;
    virtual bool validateInput(component_io_t inp) const;
    virtual void setInput(component_io_t inp);
    virtual component_io_t getOutput();
    virtual component_io_t calculateOutput() = 0;
    component_io_t process(component_io_t inp);

protected:
    component_io_t inp;
    component_io_t out;
    bool inputChanged;
};

#endif // !CIRCUIT_COMPONENT_H