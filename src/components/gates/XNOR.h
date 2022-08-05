#ifndef XNOR_H
#define XNOR_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "NOT.h"
#include "AND.h"
#include "OR.h"

class XNOR : public CircuitComponent
{
public:
    XNOR();
    ~XNOR();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;

private:
    NOT *notA;
    NOT *notB;
    AND *andNotANotB;
    AND *andAB;
    OR *orGate;
};

#endif // !XNOR_H