#pragma once

#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace CppStudy
{
    // template
    template <typename T>
    T whichIsGreater(T a, T b)
    {
        return (a > b) ? a : b;
    }
}

#endif // FUNCTIONS_H
