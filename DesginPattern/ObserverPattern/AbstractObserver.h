//
// Created by 李顺东 on 2022/8/31.
//

#ifndef OBSERVERPATTERN_ABSTRACTOBSERVER_H
#define OBSERVERPATTERN_ABSTRACTOBSERVER_H
#include <string>
class AbstractObserver{
public:
    virtual void response() = 0;
};

#endif//OBSERVERPATTERN_ABSTRACTOBSERVER_H
