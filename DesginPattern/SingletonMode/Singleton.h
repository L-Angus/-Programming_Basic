//
// Created by 李顺东 on 2022/8/30.
//

#ifndef SINGLETONMODE_SINGLETON_H
#define SINGLETONMODE_SINGLETON_H
#include <mutex>
// 懒汉模式：线程安全
class Singleton_lazy {
private:
    Singleton_lazy() = default;
    Singleton_lazy(const Singleton_lazy& other) = delete;
    static Singleton_lazy* m_instance;
    static std::mutex mtx;
public:
    static Singleton_lazy* getInstance(){
        std::lock_guard<std::mutex> locker(mtx);
        if(m_instance == nullptr){
            m_instance = new Singleton_lazy();
        }
        return m_instance;
    }
};

Singleton_lazy * Singleton_lazy::m_instance = nullptr;
std::mutex Singleton_lazy::mtx;

// 饿汉模式
class Singleton_hungry{
public:
    static Singleton_hungry* getInstance(){
        return m_instance;
    }

private:
    Singleton_hungry() = default;
    static Singleton_hungry* m_instance;
};

Singleton_hungry* Singleton_hungry::m_instance = new Singleton_hungry();

// Scott Mayers推荐的C++单例模式的写法
class Singleton_Mayers{
public:
    static Singleton_Mayers& getInstance(){
        static Singleton_Mayers m_instance; // 局部static变量，不存在，则创建，否则，用已存在的变量。
        return m_instance;
    }
    Singleton_Mayers(const Singleton_Mayers&) = delete;
    Singleton_Mayers& operator=(const Singleton_Mayers&) = delete;

private:
    Singleton_Mayers() = default;
};

#endif//SINGLETONMODE_SINGLETON_H
