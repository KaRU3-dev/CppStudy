#include <iostream>

#include "src/includes/Calculators.h"

int main()
{
    std::cout << "Hello, MinGW!" << std::endl;

    int sum = CppStudy::add(3, 5);
    std::cout << "The sum of 3 and 5 is: " << sum << std::endl;

    return 0;
}
