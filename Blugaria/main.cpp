#include <iostream>
#include <ctime>

#include "headers.h"
#include "Application.hpp"

int main()
{
    srand(time(NULL));
    try
    {
        application();
    }
    catch(...)
    {
        exit(0);
    }
    return 0;
}
