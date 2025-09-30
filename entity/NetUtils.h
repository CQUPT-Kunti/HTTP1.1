#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "log.h"

namespace NetUtils
{
    // 创建监听 socket，返回 fd
    int create_listen_socket(int port);

    // 将 fd 设置为非阻塞
    void set_non_blocking(int fd);
}

int NetUtils::create_listen_socket(int port)
{

    int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
    {
        Logger::getInstane().log("socket() error");
        return -1;
    }

    int opt = 1;
    if (setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        Logger::getInstane().log("setsockopt() error");
        close(serv_sock);
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(serv_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        Logger::getInstane().log("bind() error");
        close(serv_sock);
        return -1;
    }

    if (listen(serv_sock, SOMAXCONN) < 0)
    {
        Logger::getInstane().log("listen error");
        close(serv_sock);
        return -1;
    }

    set_non_blocking(serv_sock);
    return serv_sock;
}

void NetUtils::set_non_blocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
    {
        Logger::getInstane().log("fcntl(F_GETFL) error");
        return;
    }
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
    {
        Logger::getInstane().log("fcntl(F_SETFL) error");
    }
}
