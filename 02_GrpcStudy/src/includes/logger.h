#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#ifndef _LOGGER_H
#define _LOGGER_H

namespace logger
{
    class LogLevel
    {
    public:
        enum Level
        {
            INFO,
            DEBUG,
            WARN,
            ERR
        };

        static const char *ToString(Level level)
        {
            switch (level)
            {
            case INFO:
                return "INFO   ";
                break;
            case DEBUG:
                return "DEBUG  ";
                break;
            case WARN:
                return "WARN   ";
                break;
            case ERR:
                return "ERROR  ";
                break;
            default:
                return "UNKNOWN";
                break;
            }
        }

        Level level;

        LogLevel(Level level) : level(level) {}
        LogLevel() : level(INFO) {}
    };

    void Log(std::string message, LogLevel level = LogLevel::INFO);
}

#endif
