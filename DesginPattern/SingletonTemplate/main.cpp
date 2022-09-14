#include <iostream>
#include <string>
#include "Singleton.h"

struct A{
    A(const std::string& ){
        std::cout << "lvalue" << std::endl;
    }
    A(std::string&& x){
        std::cout << "rvalue" << std::endl;
    }
};

struct B{
    B(const std::string& ){
        std::cout << "lvalue" << std::endl;
    }
    B(std::string&& x){
        std::cout << "rvalue" << std::endl;
    }
};

struct C{
    C(int x, double y){}
    void Fun(){
        std::cout << "test" << std::endl;
    }
};


int main() {
    std::cout << "============= Singleton Template ============" << std::endl;
    std::string str = "bb";
    auto a = Singleton<A>::getInstance(str);
    auto b = Singleton<B>::getInstance(std::move(str));
    Singleton<C>::getInstance(1, 3.14);
    Singleton<C>::GetInstance()->Fun();
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    Singleton<A>::DestoryInstance();
    Singleton<B>::DestoryInstance();
    Singleton<C>::DestoryInstance();
    return 0;
}
