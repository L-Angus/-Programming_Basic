#include "FactoryMethod.h"
#include <iostream>

inline void ClientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n";
    std::cout << creator.someOperation() << std::endl;
}


int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator1 = new ConceretCreator1();
    ClientCode(*creator1);
    Creator* creator2 = new ConceretCreator2();
    ClientCode(*creator2);
    return 0;
}