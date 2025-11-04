#include "includes/Calculators.h"

namespace CppStudy
{
    int add(int a, int b)
    {
        return a + b;
    }

    int add(int a, int b, int limit)
    {
        int sum = a + b;

        if (sum > limit)
        {
            return limit;
        }
        else
        {
            return sum;
        }
    }
}
