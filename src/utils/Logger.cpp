#include "Logger.h"

void Logger::Log(const std::string &message)
{
    Write("LOG", message);
}

void Logger::Info(const std::string &message)
{
    Write("INFO", message);
}

void Logger::Error(const std::string &message)
{
    Write("ERROR", message);
}

void Logger::Write(const std::string &messageType, const std::string &message)
{
    std::string timestamp = GetCurrentTime();
    std::cout << "[" << timestamp << "][" << messageType << "]: " << message << '\n';

    // Additionally, write to a file if needed
    /*     std::ofstream logFile("log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << "[" << timestamp << "][" << messageType << "]: " << message << '\n';
            logFile.close();
        } */
}

std::string Logger::GetCurrentTime()
{
    std::time_t now = std::time(nullptr);
    std::tm ltm;

    localtime_s(&ltm, &now);

    std::ostringstream oss;
    oss << 1900 + ltm.tm_year << "-"
        << 1 + ltm.tm_mon << "-"
        << ltm.tm_mday << " "
        << ltm.tm_hour << ":"
        << ltm.tm_min << ":"
        << ltm.tm_sec;

    return oss.str();
}