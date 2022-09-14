#include "AbstractFactory.h"
#include <iostream>

inline void ClientCode(const AbstractFactory& factory) {
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    std::cout << product_b->UsefulFunctionB() << "\n";
    std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}

int main()
{
    AbstractFactory* factory1 = new ConcereteFactory1();
    std::cout << "Client1: \n";
    ClientCode(*factory1);
    std::cout << "==============================\n";
    AbstractFactory* factory2 = new ConcereteFactory2();
    std::cout << "Client2: \n";
    ClientCode(*factory2);
    return 0;
}