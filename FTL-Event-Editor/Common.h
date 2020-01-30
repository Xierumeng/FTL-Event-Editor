#pragma once

#include <string>
#include <vector>

// Either name=, id=, load=
enum class IdType
{
    Name = 0, // name=
    Id, // id=
    Load // load=
};

// Random, low, medium, high
enum class Level
{
    RANDOM = 0,
    LOW,
    MED,
    HIGH
};

// Text wrapper
// IdType::Name means direct text, id= is load from text_events.xml, load= is load from textList
struct Text
{
    IdType textType = IdType::Name;
    std::string textData = "";

    std::string planet = "";
    std::string back = "";
};

struct TextList
{
    std::string name = "";
    std::vector<Text> texts;
};
