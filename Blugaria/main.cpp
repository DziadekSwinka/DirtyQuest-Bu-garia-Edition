#include <iostream>

#include "Application.hpp"

int main()
{
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
