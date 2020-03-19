#pragma once
#include <string>
#include <vector>

// Either name=, id=, load=
enum class IdType
{
    Direct = 0, // Text located between opening and closing tags
    Name, // name=
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

struct AttributeType
{
    IdType type = IdType::Name;
    std::string data = "";
};

// Text wrapper
// IdType::Direct means direct text, id= is load from text_events.xml, load= is load from textList
struct Text
{
    Text() = default;
    Text(AttributeType newType) : textType(newType) {}

    AttributeType textType;

    std::string planet = "";
    std::string back = "";
};

struct TextList
{
    std::string name = "";
    std::vector<Text> texts;
};
