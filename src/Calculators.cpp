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

    std::string getData(int id)
    {
        switch (id)
        {
        case 1:
            return "Data for ID 1";
        case 2:
            return "Data for ID 2";
        default:
            return "No data found";
        }
    }
}
