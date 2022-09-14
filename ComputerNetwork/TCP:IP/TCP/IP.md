# TCP/IP网络编程
## Charpter1
### 1. 网络编程的核心：套接字。分为服务端套接字（监听）和客户端套接字。
### 2. 服务端套接字的创建过程：
第一步：调用socket函数创建套接字；
第二步：调用bind函数绑定IP和端口号；
第三步：调用listen函数转为可接收请求状态；
第四步：调用accept函数受理连接请求。
```c++
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <arpa/inet.h>

void error_handing(const std::string& message);

int main(int argc, char* argv[])
{
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    socklen_t clinet_addr_size;
    char message[] = "hello world";
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    // 创建socket
    auto serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) error_handing("socket() error");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // bind
    if (bind(serv_sock, (struct sockaddr*)&server_addr, sizeof(server_addr) == -1)) {
        error_handing("bind() error");
    }

    // listen
    if (listen(serv_sock, 5) == -1) {
        error_handing("listen() error");
    }

    clinet_addr_size = sizeof(client_addr);
    auto client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &clinet_addr_size);
    if (client_sock == -1) {
        error_handing("accept() error");
    }

    write(client_sock, message, sizeof(message));
    close(client_sock);
    close(serv_sock);
    return 0;
}

void error_handing(const std::string& message) {
    fputs(message.c_str(), stderr);
    fputc('\n', stderr);
    exit(1);
}
```
### 3. 客户端套接字的创建过程：
第一步：调用socket函数和connect函数；
第二步：与服务端共同运行以收发字符串数据。
```c++
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <arpa/inet.h>

void error_handing(const std::string& message);

int main(int argc, char* argv[])
{
    struct sockaddr_in serv_addr;
    char* message;
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    auto sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) error_handing("socket() error");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr) == -1)) {
        error_handing("connect() error");
    }

    auto str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1) {
        error_handing("read() error");
    }

    printf("Message from server: %s\n", message);
    close(sock);
    return 0;
}

void error_handing(const std::string& message) {
    fputs(message.c_str(), stderr);
    fputc('\n', stderr);
    exit(1);
}
```