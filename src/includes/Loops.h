#pragma once

#include <iostream>

#ifndef LOOPS_H
#define LOOPS_H

namespace CppStudy
{
    // Function to count up to a limit using a for loop
    void whileCountUp(int limit);

    // Do before adding more loop functions here
    void doWhileExample(int limit);

    // Count limited loop example
    void forCountLimited(int start, int end, int step);

    // When over limit, stop counting
    void countWithLimit(int limit);
}

#endif // LOOPS_H
