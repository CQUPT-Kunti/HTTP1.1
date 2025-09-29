#pragma one
#include <sys/socket.h>
#include <iostream>

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
    }
}