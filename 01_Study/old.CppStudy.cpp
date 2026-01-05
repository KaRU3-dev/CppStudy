// #include <iostream>

// #include "Calculators.h"
// #include "Loops.h"
// #include "Memory.h"
// #include "Functions.h"
// #include "Objects.h"

// int main(int argc, char **argv)
// {
//     std::cout << "Hello, MinGW!" << std::endl;

//     int sum = CppStudy::add(3, 5);
//     std::cout << "The sum of 3 and 5 is: " << sum << std::endl;

//     CppStudy::Dictionary_t dict;
//     dict.push_back(std::make_pair("apple", 1));
//     dict.push_back(std::make_pair("banana", 2));

//     std::cout << "Dictionary contents:" << std::endl;
//     for (const auto &pair : dict)
//     {
//         std::cout << pair.first << ": " << pair.second << std::endl;
//     }

//     int limitedSum = CppStudy::add(10, 20, 25);
//     std::cout << "The limited sum of 10 and 20 with limit 25 is: " << limitedSum << std::endl;

//     std::string data = CppStudy::getData(1);
//     std::cout << "Data for ID 1: " << data << std::endl;

//     std::string evenCheck = CppStudy::isEven50(50);
//     std::cout << "Is 50 even? " << evenCheck << std::endl;

//     std::string oddEvenCheck = CppStudy::hasOrEven50(33);
//     std::cout << "Is 33 odd or even? " << oddEvenCheck << std::endl;

//     CppStudy::whileCountUp(5);
//     CppStudy::doWhileExample(5);
//     CppStudy::forCountLimited(0, 10, 2);
//     CppStudy::countWithLimit(5);

//     std::string students[] = {"Alice", "Bob", "Charlie"};
//     std::cout << "Student names:" << std::endl;
//     for (const auto &name : students)
//     {
//         std::cout << name << std::endl;
//     }

//     CppStudy::showMemoryAddress("Sample Data");
//     int x = 10;
//     int y = 20;
//     CppStudy::swapByAddress(x, y);
//     CppStudy::examplePointerUsage();
//     CppStudy::nullptrExample();
//     CppStudy::dynamicMemoryExample();

//     auto a = CppStudy::whichIsGreater<int>(10, 7);
//     auto b = CppStudy::whichIsGreater<double>(10.5, 7.3);
//     std::cout << "Greater integer: " << a << std::endl;
//     std::cout << "Greater double: " << b << std::endl;

//     CppStudy::Person person = {"John Doe", 30};
//     std::cout << "Person Name: " << person.name << ", Age: " << person.age << std::endl;
//     CppStudy::UpdatePersonName(person, "Jane Smith");
//     std::cout << "Updated Person Name: " << person.name << ", Age: " << person.age << std::endl;

//     CppStudy::Animal animal("Dog", 5);
//     std::cout << "Animal Type: " << animal.getType() << ", Age: " << animal.getAge() << std::endl;

//     CppStudy::Planet planet("Mars", 6.39e23);
//     std::cout << "Planet Name: " << planet.getName() << ", Mass: " << planet.getMass() << " kg" << std::endl;
//     CppStudy::Earth earth;
//     std::cout << "Earth Name: " << earth.getName() << ", Mass: " << earth.getMass() << " kg" << std::endl;

//     // std::string input;
//     // std::cout << "Press Enter to exit...";
//     // std::getline(std::cin, input);
//     return 0;
// }
