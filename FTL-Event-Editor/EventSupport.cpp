#include "EventSupport.h"

#include <iostream>

void printEnvironment(Environment hazard)
{
    if (hazard == Environment::asteroid)
    {
        std::cout << "asteroid";
    }
    else if (hazard == Environment::sun)
    {
        std::cout << "sun";
    }
    else if (hazard == Environment::pulsar)
    {
        std::cout << "pulsar";
    }
    else if (hazard == Environment::PDSEnemy)
    {
        std::cout << "PDS target=enemy";
    }
}