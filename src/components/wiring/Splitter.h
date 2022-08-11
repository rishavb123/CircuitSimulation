#ifndef SPLITTER_H
#define SPLITTER_H

#include "../CircuitComponent.h"
#include "../typedefs.h"

class Splitter : public CircuitComponent
{
public:
    Splitter();
    Splitter(splitter_connection_t connection);
    ~Splitter();
    bool validateInput(component_io_t inp) const override;
    component_io_t calculateOutput() override;

private:
    splitter_connection_t connection;
    std::vector<size_t> inpDims;
};

#endif // !SPLITTER_H