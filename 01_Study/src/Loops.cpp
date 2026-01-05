#include "includes/Loops.h"

namespace CppStudy
{
    void whileCountUp(int limit)
    {
        int count = 0;
        while (count < limit)
        {
            std::cout << "Count: " << count << std::endl;
            count++;
        }
    }

    void doWhileExample(int limit)
    {
        int count = 0;
        do
        {
            std::cout << "Do-While Count: " << count << std::endl;
            count++;
        } while (count < limit);
    }

    void forCountLimited(int start, int end, int step)
    {
        for (int i = start; i < end; i += step)
        {
            std::cout << "For Loop Count: " << i << std::endl;
        }
    }

    void countWithLimit(int limit)
    {
        for (int i = 0;; i++)
        {
            if (i >= limit)
            {
                break;
            }
            std::cout << "Counting with limit: " << i << std::endl;
        }
    }
}
