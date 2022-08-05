#ifndef XOR_H
#define XOR_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "NOT.h"
#include "AND.h"
#include "OR.h"

class XOR : public CircuitComponent
{
public:
    XOR();
    ~XOR();
    bool validateInput(component_io_t inp) const override;
    component_io_t getOutput() override;
private:
    NOT *notA;
    NOT *notB;
    AND *andANotB;
    AND *andNotAB;
    OR *orGate;
};

#endif // !XOR_H