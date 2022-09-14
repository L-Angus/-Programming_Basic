#include <iostream>
#include "Singleton.h"

int main() {
    std::cout << "Hello Singleton Pattern!" << std::endl;
    Singleton_lazy * instance1 = Singleton_lazy::getInstance();
    Singleton_lazy * instance2 = Singleton_lazy::getInstance();
    Singleton_hungry * instance3 = Singleton_hungry::getInstance();
    Singleton_hungry * instance4 = Singleton_hungry::getInstance();
    Singleton_Mayers& instance5 = Singleton_Mayers::getInstance();
    Singleton_Mayers& instance6 = Singleton_Mayers::getInstance();
    std::cout << "&instance1: " << &instance1 << std::endl;
    std::cout << "&instance2: " << &instance2 << std::endl;
    std::cout << "&instance3: " << &instance3 << std::endl;
    std::cout << "&instance4: " << &instance4 << std::endl;
    std::cout << "&instance5: " << &instance5 << std::endl;
    std::cout << "&instance6: " << &instance6 << std::endl;
    return 0;
}
