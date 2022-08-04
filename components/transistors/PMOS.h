#ifndef PMOS_H
#define PMOS_H

#include "../CircuitComponent.h"
#include "../../utils/arrayutils.h"

class PMOS : public CircuitComponent {
    public:
        PMOS();
        ~PMOS();
        bool validateInput(bool **inp) const;
        bool** getOutput() const override;
};

#endif // !PMOS_H
