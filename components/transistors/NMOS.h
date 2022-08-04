#ifndef NMOS_H
#define NMOS_H

#include "../CircuitComponent.h"
#include "../../utils/arrayutils.h"

class NMOS : public CircuitComponent {
    public:
        NMOS();
        ~NMOS();
        bool validateInput(bool **inp) const override;
        bool** getOutput() const override;
};

#endif // !NMOS_H
