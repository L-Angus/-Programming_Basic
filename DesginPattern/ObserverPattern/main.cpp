#include <iostream>
#include "Publisher.h"
#include "Subscribe.h"

int main() {
    std::cout << "=========== Hello Observer Pattern ===========" << std::endl;
    // 发布者
    Publisher pub;

    // 订阅者
    Mouse mouse{"mouse"};
    Dog dog{"dog"};

    // 添加订阅关系
    pub.attach(&mouse);
    pub.attach(&dog);

    // 发布消息
    pub.Cry();
    return 0;
}
