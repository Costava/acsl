#include <iostream>
#include <typeinfo>
class B {
  public :
    virtual const std::string who() { return "B";}
};

class A: public B {
  public:
    virtual const std::string who() {return "A"; }
};

int main() {
    B* b = new B();
    B* bb = new B();
    A* a = new A();
    B* ba = new A();
    const std::type_info& bt = typeid(*b); // *b, NOT b !!
    const std::type_info& bbt = typeid(*bb);
    const std::type_info& at = typeid(*a);
    // type_info of the dynamic type
    const std::type_info& bat = typeid(*ba);

    // Emits dynamic value of who(): BBAA
    std::cout << b->who() << bb->who() << a->who() << ba->who()
              << std::endl;

    // Emits mangled names of dynamic type: 1B 1B 1A 1A
    std::cout << bt.name() << " " << bbt.name() << " "
              << at.name() << " " << bat.name() << std::endl;

    // All comparisons are true. Emits: 1 1 1 1
    std::cout << (bt==bbt) << " " << (bt!=at) << " " << (bt!=bat)
                    << " " << (at==bat) << std::endl;
    return 0;
}
