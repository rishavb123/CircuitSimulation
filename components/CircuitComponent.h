#ifndef CIRCUIT_COMPONENT_H
#define CIRCUIT_COMPONENT_H

class CircuitComponent {
    public:
        bool **getInput() const;
        void setInput(bool **inp);
        virtual bool** getOutput() const = 0;
        bool **process(bool **inp);

    protected:
        bool **inp;
};

#endif // !CIRCUIT_COMPONENT_H