#pragma once

#include <iostream>

#ifndef MEMORY_H
#define MEMORY_H

namespace CppStudy
{
    void showMemoryAddress(std::string data);
    void swapByAddress(int &a, int &b);

    void examplePointerUsage();
    void nullptrExample();

    void dynamicMemoryExample();
}

#endif // MEMORY_H
