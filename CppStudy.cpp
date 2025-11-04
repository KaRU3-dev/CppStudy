#include <iostream>

#include "src/includes/Calculators.h"
#include "src/includes/Loops.h"

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

    int limitedSum = CppStudy::add(10, 20, 25);
    std::cout << "The limited sum of 10 and 20 with limit 25 is: " << limitedSum << std::endl;

    std::string data = CppStudy::getData(1);
    std::cout << "Data for ID 1: " << data << std::endl;

    std::string evenCheck = CppStudy::isEven50(50);
    std::cout << "Is 50 even? " << evenCheck << std::endl;

    std::string oddEvenCheck = CppStudy::hasOrEven50(33);
    std::cout << "Is 33 odd or even? " << oddEvenCheck << std::endl;

    CppStudy::whileCountUp(5);
    CppStudy::doWhileExample(5);
    CppStudy::forCountLimited(0, 10, 2);
    CppStudy::countWithLimit(5);

    // std::string input;
    // std::cout << "Press Enter to exit...";
    // std::getline(std::cin, input);

    return 0;
}
