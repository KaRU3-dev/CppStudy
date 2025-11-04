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

    // Typedef for Dictionary
    typedef std::vector<std::pair<std::string, int>> Dictionary_t;
}

#endif // CALCULATORS_H
