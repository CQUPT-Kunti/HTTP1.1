#pragma one
#include <string>

class Server
{
public:
private:
    int port_;
    int listen_fd_;
    int epoll_fd_;

    // 处理新连接（accept 客户端）
    void handle_new_connection();

    // 处理客户端可读事件（读数据 → 投递给线程池）
    void handle_client_read(int client_fd);

    // 发送响应给客户端（写事件触发时）
    void handle_client_write(int client_fd, const std::string &response);

    // 关闭客户端连接
    void close_connection(int client_fd);
};