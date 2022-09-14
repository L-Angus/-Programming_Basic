//
// Created by 李顺东 on 2022/8/31.
//

#ifndef OBSERVERPATTERN_PUBLISHER_H
#define OBSERVERPATTERN_PUBLISHER_H

#include <vector>
#include "AbstractObserver.h"

class Publisher{
public:
    // register obeservers
    void attach(AbstractObserver* pub){
        m_publishers.push_back(pub);
    }

    // detach observers
    void detach(AbstractObserver* pub){
        for(auto it = m_publishers.end(); it != m_publishers.end(); ++it){
            if (*it == pub){
                m_publishers.erase(it);
            }
        }
    }

    void Cry(){
        std::cout << "猫叫" << std::endl;
        for(auto ob : m_publishers){
            ob->response();
        }
    }
private:
    std::vector<AbstractObserver*> m_publishers;
};

#endif//OBSERVERPATTERN_PUBLISHER_H
