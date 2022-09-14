//
// Created by 李顺东 on 2022/8/31.
//

#ifndef OBSERVERPATTERN_SUBSCRIBE_H
#define OBSERVERPATTERN_SUBSCRIBE_H
#include "AbstractObserver.h"
#include <string>

class Mouse : public AbstractObserver{
public:
    Mouse() = default;
    Mouse(const std::string& n) : m_name(n){
        std::cout << "Observer:" << m_name << std::endl;
    }

    virtual void response() override{
        std::cout << "老鼠逃跑" << std::endl;
    }

//    virtual std::string name() override {
//        return m_name;
//    }
private:
    std::string m_name;
};

class Dog : public AbstractObserver{
public:
    Dog() {}
    Dog(const std::string& n) : m_name(n){
        std::cout << "Observer:" << m_name << std::endl;
    }
    virtual void response() override {
        std::cout << "狗追猫" << std::endl;
    }
//    virtual std::string name() override {
//        return m_name;
//    }
private:
    std::string m_name;
};

#endif//OBSERVERPATTERN_SUBSCRIBE_H
