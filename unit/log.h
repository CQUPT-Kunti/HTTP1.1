#pragma once

#include <mutex>
#include <string>
#include <fstream>
class Logger
{
private:
    Logger();
    ~Logger();
    std::ofstream logFile;
    std::mutex mtx;

public:
    static Logger &getInstane();
    void log(const std::string &messgae);
};