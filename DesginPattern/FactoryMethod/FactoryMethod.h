#ifndef __FACTORYMETHOD__H
#define __FACTORYMETHOD__H
#include <string>
// 1. 创建product类
class Product {
public:
    virtual ~Product() {};
    virtual std::string Operation() const = 0;
};

// 2. 实现对Product类不同的接口实现
class ConceretProduct1 : public Product {
public:
    virtual std::string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    };
};

class ConceretProduct2 : public Product {
public:
    virtual std::string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    };
};

// 3. 创建Creator类
class Creator {
public:
    virtual ~Creator() {};
    virtual Product* FactoryMethod() const = 0;

    std::string someOperation() const {
        auto product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        product = nullptr;
        return result;
    }
};

// 4. 具体Creator实现类
class ConceretCreator1 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConceretProduct1();
    }
};

class ConceretCreator2 : public Creator {
public:
    Product* FactoryMethod() const override {
        return new ConceretProduct2();
    }
};




#endif //! __FACTORYMETHOD__H