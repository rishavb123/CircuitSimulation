#ifndef CIRCUIT_COMPONENT_H
#define CIRCUIT_COMPONENT_H

#include "typedefs.h"

class CircuitComponent
{
public:
    component_inp_t getInput() const;
    bool validateInput(component_inp_t inp) const;
    void setInput(component_inp_t inp);
    virtual component_inp_t getOutput() const = 0;
    component_inp_t process(component_inp_t inp);

protected:
    component_inp_t inp;
};

#endif // !CIRCUIT_COMPONENT_H