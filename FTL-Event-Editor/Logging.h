#pragma once
#include <string>
#include <iostream>

namespace Log
{
    void error(std::string message)
    {
        std::cout << "ERROR: " << message << std::endl;
    }

    void warning(std::string message)
    {
        std::cout << "WARNING: " << message << std::endl;
    }
}