# 编程四大件

## 1. 操作系统



## 2. 计算机网络

### TCP/TP

### HTTP

## 3. 数据结构与算法

### 数据结构

### 算法

## 4. 设计模式

### 创建型

```markdown
这类模式提供创建对象的机制， 能够提升已有代码的灵活性和可复用性。
```

#### 1. 工厂方法

![WeChatc4f33312a73798f33dd9d72e96031611](/Users/lishundong/Desktop/WeChatc4f33312a73798f33dd9d72e96031611.png)

```c++
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
```



```c++
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
  	std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConceretCreator2();
    ClientCode(*creator2);
    return 0;
}
```

##### 执行结果：

```shell
App: Launched with the ConcreteCreator1.
Client: I'm not aware of the creator's class, but it still works.
Creator: The same creator's code has just worked with {Result of the ConcreteProduct1}
App: Launched with the ConcreteCreator2.
Client: I'm not aware of the creator's class, but it still works.
Creator: The same creator's code has just worked with {Result of the ConcreteProduct2}
```

#### 2. 抽象工厂模式

**抽象工厂模式**是一种创建型设计模式， 它能创建一系列相关的对象， 而无需指定其具体类。

![抽象工厂模式](https://refactoringguru.cn/images/patterns/content/abstract-factory/abstract-factory-zh.png)

![生成不同风格的系列家具。](https://refactoringguru.cn/images/patterns/diagrams/abstract-factory/problem-zh.png)



![抽象工厂设计模式](https://refactoringguru.cn/images/patterns/diagrams/abstract-factory/structure.png)



##### 1. 抽象产品A（AbstractProductA）

```
抽象产品 （Abstract Product） 为构成系列产品的一组不同但相关的产品声明接口。
```

```c++
class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
    virtual std::string UsefulFunctionA() const = 0;
};

```

##### 2. 具体产品类A (ConceretProductA)

```c++
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
```

##### 3. 抽象产品B（AbstractProductB）

```c++
class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};
```

##### 4. 具体产品B（ConceretProductB）

```c++
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
```

##### 5. 抽象工厂类（AbstractFactory）

```c++
class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};
```

##### 6. 具体工厂类（ConceretFactory）

```c++
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
```

##### example:

```c++
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
```

##### 运行结果：

```c++
Client1: 
[===== Abstract Product B1 =====]
B1 result: [===== Abstract Product A1 =====]
===============================================
Client2: 
[===== Abstract Product B2 =====]
B2 result: [===== Abstract Product A2 =====]
```

### 结构型

```markdown
这类模式介绍如何将对象和类组装成较大的结构， 并同时保持结构的灵活和高效。
```

### 行为型

```markdown
这类模式负责对象间的高效沟通和职责委派。
```

#### 1. 迭代器模式

**迭代器模式**是一种行为设计模式， 让你能在不暴露集合底层表现形式 （列表、 栈和树等） 的情况下遍历集合中所有的元素。

![迭代器模式示例的结构](https://refactoringguru.cn/images/patterns/diagrams/iterator/example-zh.png)



## 5. 编程语言

### C

### C++

### Shell

### Python

## 6. 工具类

### git

### cmake

### gdb

### makefile





















