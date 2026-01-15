#include "Logger.h"

using namespace MultiProject::Logging;

class Sample
{
    //
};

int main()
{
    auto logger = new Logger("Sample", LogLevel::INFO);

    logger->Log(LogLevel::INFO, std::format("Hello, World {}", 123));
    logger->Log(LogLevel::WARNING, std::format("Hello, World {}", 123));

    logger->LogInfo(std::format("Hello, World {}", 123));

    delete logger;
    return 0;
}
