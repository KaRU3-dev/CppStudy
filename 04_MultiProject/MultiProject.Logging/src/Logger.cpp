#include "Logger.h"

using namespace MultiProject::Logging;

Logger::Logger(std::string sourceName, LogLevel level)
{
    this->sourceName = sourceName;
    this->logLevel = level;
}

Logger::~Logger()
{
}

void Logger::Log(const LogLevel level, std::string message)
{
    if (!IsEnabled(level))
    {
        return;
    }

    auto date = std::chrono::system_clock::now();
    auto date_time = std::chrono::system_clock::to_time_t(date);
    auto date_time_str = (std::string)std::ctime(&date_time);
    date_time_str.pop_back();

    std::string msg = " " + date_time_str + " | " + sourceName + ": " + message;

    switch (level)
    {
    case LogLevel::INFO:
        LogInfo(msg);
        break;
    case LogLevel::WARNING:
        LogWarning(msg);
        break;
    case LogLevel::ERROR:
        LogError(msg);
        break;
    case LogLevel::FATAL:
        LogFatal(msg);
        break;
    default:
        break;
    }
}

void Logger::LogInfo(std::string message)
{
    if (!IsEnabled(LogLevel::INFO))
    {
        return;
    }

    auto msg = "INFO  :" + message;
    COUT(msg);
}

void Logger::LogWarning(std::string message)
{
    if (!IsEnabled(LogLevel::INFO))
    {
        return;
    }

    auto msg = "WARN  :" + message;
    COUT(msg);
}

void Logger::LogError(std::string message)
{
    if (!IsEnabled(LogLevel::INFO))
    {
        return;
    }

    auto msg = "ERROR :" + message;
    CERR(msg);
}

void Logger::LogFatal(std::string message)
{
    if (!IsEnabled(LogLevel::INFO))
    {
        return;
    }

    auto msg = "FATAL :" + message;
    CERR(msg);
}

bool Logger::IsEnabled(LogLevel level)
{
    return level >= logLevel;
}
