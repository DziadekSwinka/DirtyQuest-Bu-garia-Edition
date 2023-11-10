#include <iostream>
#include <ctime>

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
