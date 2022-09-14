//
// Created by 李顺东 on 2022/8/30.
//

#ifndef SINGLETONTEMPLATE_SINGLETON_H
#define SINGLETONTEMPLATE_SINGLETON_H
#include <iostream>

template<typename T>
class Singleton {
public:
    template<typename... Args>
    static T& getInstance(Args&&... args){
        if (m_instance == nullptr){
            m_instance = new T(std::forward<Args>(args)...);
        }
        return m_instance;
    }
    static T* GetInstance(){
        if (m_instance == nullptr){
            throw std::logic_error("the instance is not init, please initialize the instance first.");
        }
        return m_instance;
    }

    static void DestoryInstance(){
        delete m_instance;
        m_instance = nullptr;
    }
private:
    Singleton() = default;
    virtual ~Singleton(){};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton& ) = delete;
    static T* m_instance;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;

#endif//SINGLETONTEMPLATE_SINGLETON_H
