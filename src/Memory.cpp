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

    void examplePointerUsage()
    {
        std::string data = "Pointer Example";
        std::string *ptr = &data;

        std::cout << "Data: " << data << std::endl;
        std::cout << "Pointer address: " << ptr << std::endl;
        std::cout << "Value via pointer: " << *ptr << std::endl;
    }

    void nullptrExample()
    {
        int *ptr = nullptr;
        int value = 42;

        // ptr = &value;

        if (ptr == nullptr)
        {
            std::cout << "Pointer is null." << std::endl;
        }
        else
        {
            std::cout << "Pointer is not null." << std::endl;
        }
    }

    void dynamicMemoryExample()
    {
        int *arr = new int[5];

        for (int i = 0; i < 5; ++i)
        {
            arr[i] = i * 10;
        }

        std::cout << "Dynamic array contents: ";
        for (int i = 0; i < 5; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        delete[] arr;
    }
}
