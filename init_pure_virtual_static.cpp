#include <cassert>
/*
 * Question: How do we properly initialize a const static variable of a pure virtual class?
 *
 * Answer: We can do so prior to the main function and prior to any instantiation of its derived classes.
 *
 * Why: This can be useful as a 'global' configuration for all derived classes of the pure virtual class.
 */
class PureVirtual {
    public:
        PureVirtual() {};
        int getCommon() {return s_common;};
        const static int s_common;
};

class Derived1: public PureVirtual {
    public:
        Derived1(): PureVirtual() {};
};

class Derived2: public PureVirtual {
    public:
        Derived2(): PureVirtual() {};
};

const int PureVirtual::s_common = 10;
int main() {
    PureVirtual d1 = Derived1();
    PureVirtual d2 = Derived2();

    assert(d1.getCommon() == PureVirtual::s_common);
    assert(d2.getCommon() == PureVirtual::s_common);
}
