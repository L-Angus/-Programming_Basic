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