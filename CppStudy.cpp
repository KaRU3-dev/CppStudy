#include <iostream>

#include "src/includes/Calculators.h"

int main()
{
    std::cout << "Hello, MinGW!" << std::endl;

    int sum = CppStudy::add(3, 5);
    std::cout << "The sum of 3 and 5 is: " << sum << std::endl;

    CppStudy::Dictionary_t dict;
    dict.push_back(std::make_pair("apple", 1));
    dict.push_back(std::make_pair("banana", 2));

    std::cout << "Dictionary contents:" << std::endl;
    for (const auto &pair : dict)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
