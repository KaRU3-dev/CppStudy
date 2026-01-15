#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <format>
#include <stdarg.h>

#ifndef LOGGER_H
#define LOGGER_H
/**
 * Test
 */
namespace MultiProject::Logging
{
#define COUT(msg) \
    std::cout << msg << std::endl;
#define CERR(msg) \
    std::cerr << msg << std::endl;

    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    class Logger
    {
    private:
        std::string sourceName;
        LogLevel logLevel;

    public:
        Logger(std::string sourceName, LogLevel level);
        ~Logger();

        void Log(const LogLevel level, std::string message);
        void LogInfo(std::string message);
        void LogWarning(std::string message);
        void LogError(std::string message);
        void LogFatal(std::string message);
        bool IsEnabled(LogLevel level);
    };
}
#endif // LOGGER_H
