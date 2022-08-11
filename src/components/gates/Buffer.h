#ifndef BUFFER_H
#define BUFFER_H

#include "../typedefs.h"
#include "../CircuitComponent.h"
#include "../transistors/NMOS.h"

class Buffer : public CircuitComponent
{
public:
    Buffer(size_t bitSize);
    ~Buffer();
    bool validateInput(component_io_t inp) const override;
    component_io_t calculateOutput() override;

private:
    size_t bitSize;
    NMOS *nmos;
};

#endif // !BUFFER_H