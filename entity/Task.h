#pragma one
#include <string>
#include <functional>

struct Task
{
    int client_fd;            // 客户端 socket
    std::string request_data; // 客户端发送的数据

    // 任务执行函数（worker 线程执行）
    std::function<void()> func;
};
