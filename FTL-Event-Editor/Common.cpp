#pragma once
#include "Common.h"

void printId(const IdType& id)
{
    if (id == IdType::Direct)
    {
        std::cout << "(Direct) ";
    }
    else if (id == IdType::Name)
    {
        std::cout << "name=";
    }
    else if (id == IdType::Id)
    {
        std::cout << "id=";
    }
    else if (id == IdType::Load)
    {
        std::cout << "load=";
    }
}
