#ifndef CircuitComponent_h
#define CircuitComponent_h

class CircuitComponent {
    public:
        bool **getInput() const;
        void setInput(bool **inp);
        virtual bool** getOutput() = 0;
        bool **process(bool **inp);

    protected:
        bool **inp;
};

#endif // !CircuitComponent_h