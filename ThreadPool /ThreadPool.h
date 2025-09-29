#pragma one
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include "Task.h"

class ThreadPool
{
public:
    ThreadPool(size_t thread_count);
    ~ThreadPool();

    // 提交一个任务到线程池
    void enqueue(Task task);

private:
    std::vector<std::thread> workers_;  // 工作线程
    std::queue<Task> tasks_;            // 任务队列
    std::mutex queue_mutex_;            // 任务队列锁
    std::condition_variable condition_; // 条件变量（通知 worker 有新任务）
    std::atomic<bool> stop_;            // 停止标志

    // worker 线程函数（不断取任务执行）
    void worker_loop();
};