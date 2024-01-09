#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>

class Logger
{
public:
    static void Log(const std::string &message);
    static void Info(const std::string &message);
    static void Error(const std::string &message);

private:
    static void Write(const std::string &messageType, const std::string &message);
    static std::string GetCurrentTime();
};