#include "logger.h"

namespace logger
{
    void Log(std::string message, LogLevel level)
    {
        auto currentTime = std::chrono::system_clock::now();
        auto readableTime = std::chrono::system_clock::to_time_t(currentTime);
        auto localTime = *std::localtime(&readableTime);
        auto timeString = std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

        std::cout << "[" << timeString << "] [" << LogLevel::ToString(level.level) << "] " << message << std::endl;
    }
}
