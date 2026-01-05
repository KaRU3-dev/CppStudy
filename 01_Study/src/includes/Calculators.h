#pragma once
#include <string>
#include <vector>

#ifndef CALCULATORS_H
#define CALCULATORS_H

namespace CppStudy
{
    /*
     * Function to add two integers
     */
    int add(int a, int b);

    /*
     * Function to add two integers with a limit
     */
    int add(int a, int b, int limit);

    /*
     * Function to get data by ID (stub function for demonstration)
     */
    std::string getData(int id);

    /*
     * Function to check if a number is even
     */
    std::string isEven50(int number);

    /*
     * Function to check if a number is odd or even using ternary operator
     */
    std::string hasOrEven50(int number);

    // Typedef for Dictionary
    typedef std::vector<std::pair<std::string, int>> Dictionary_t;
}

#endif // CALCULATORS_H
