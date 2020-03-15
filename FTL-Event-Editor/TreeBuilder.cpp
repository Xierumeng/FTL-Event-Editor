#pragma once
#include "tinyxml2.h"

#include "Event.h"
#include "Choice.h"

bool eventNameCheck(tinyxml2::XMLElement* p_XMLEvent)
{
    if (p_XMLEvent == nullptr) return false;

    const char* eventName;
    if (p_XMLEvent->QueryStringAttribute("name", &eventName) == tinyxml2::XML_SUCCESS) return true;

    return false;
}

// Input is a pointer to the XML node containing the event
Event eventBuilder(tinyxml2::XMLElement* p_XMLEvent)
{
    if (p_XMLEvent == nullptr) throw;

}

// Input is a pointer to the XML node containing the choice
Choice choiceBuilder(tinyxml2::XMLElement* p_XMLChoice)
{
    if (p_XMLChoice == nullptr) return Choice();

}
