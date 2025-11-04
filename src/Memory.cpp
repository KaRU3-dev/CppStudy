#include "includes/Memory.h"

namespace CppStudy
{
    void showMemoryAddress(std::string data)
    {
        std::cout << "Memory address of data: " << &data << std::endl;
    }

    void swapByAddress(int &a, int &b)
    {
        std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

        int temp = a;
        a = b;
        b = temp;

        std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    }
}
