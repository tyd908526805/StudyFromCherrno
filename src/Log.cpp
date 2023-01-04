#include "Log.h"

const char* MLog(const char* message)
{
    std::cout << message << std::endl;
    return message;
}

void vLog(const char* message)
{
    std::cout << message << std::endl;
}

void iLog(const char* message)
{
    std::cout << message << std::endl;
}

void InitLog()
{
    vLog("Initalized Log");
}
