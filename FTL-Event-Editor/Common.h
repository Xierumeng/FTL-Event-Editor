#pragma once

#include <string>

enum class IdType
{
    Name = 0, // name=
    Id, // id=
    Load // load=
};

enum class Level
{
    RANDOM = 0,
    LOW,
    MED,
    HIGH
};

struct Text
{
    IdType type = IdType::Name;
    std::string data = "";
};