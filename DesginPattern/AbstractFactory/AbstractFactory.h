#ifndef _ABSTRACTFACTORY_H
#define _ABSTRACTFACTORY_H

#include <string>

// 1、创建AbstractProductA类
class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
    virtual std::string UsefulFunctionA() const = 0;
};

// 2、创建具体ConceretProduct类
class ConceretProductA1 : public AbstractProductA {
public:
    virtual std::string UsefulFunctionA() const override {
        return "[===== Abstract Product A1 =====]";
    }
};

class ConceretProductA2 : public AbstractProductA {
public:
    virtual std::string UsefulFunctionA() const override {
        return "[===== Abstract Product A2 =====]";
    }
};

// 3、创建AbstractProductB类
class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};

class ConceretProductB1 : public AbstractProductB {
public:
    virtual std::string UsefulFunctionB() const override {
        return "[===== Abstract Product B1 =====]";
    }

    virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "B1 result: " + result;
    }
};

class ConceretProductB2 : public AbstractProductB {
public:
    virtual std::string UsefulFunctionB() const override {
        return "[===== Abstract Product B2 =====]";
    }

    virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "B2 result: " + result;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcereteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConceretProductA1();
    }
    AbstractProductB* CreateProductB() const override {
        return new ConceretProductB1();
    }
};

class ConcereteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override {
        return new ConceretProductA2();
    }
    AbstractProductB* CreateProductB() const override {
        return new ConceretProductB2();
    }
};




#endif //!_ABSTRACTFACTORY_H