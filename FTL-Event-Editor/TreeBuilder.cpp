#pragma once

#include "TreeBuilder.h"

bool eventNameCheck(tinyxml2::XMLElement* p_XMLEvent)
{
    if (p_XMLEvent == nullptr) {
        return false;
    }

    const char* eventName;
    return (p_XMLEvent->QueryStringAttribute("name", &eventName) == tinyxml2::XML_SUCCESS);
}

// Input is a pointer to the XML node containing the event
Event eventBuilder(tinyxml2::XMLElement* p_XMLEvent)
{
    // Base case
    if (p_XMLEvent == nullptr) {
        return Event(); // TODO: Base case
    }
    
    // Event name or load attribute
    EventId eventID;
    const char* eventName;

    // TODO: Can we turn this into a function?
    if (p_XMLEvent->QueryStringAttribute("name", &eventName) == tinyxml2::XML_SUCCESS)
    {
        eventID.eventType.type = IdType::Name;
        eventID.eventType.data = std::string(eventName);

        // <event name="" load=""> is wrong.
        if (p_XMLEvent->QueryStringAttribute("load", &eventName) == tinyxml2::XML_SUCCESS) throw;
    }
    else if (p_XMLEvent->QueryStringAttribute("load", &eventName) == tinyxml2::XML_SUCCESS)
    {
        eventID.eventType.type = IdType::Load;
        eventID.eventType.data = std::string(eventName);
    }

    // Build the event
    Event currentEvent(eventID);

    if (eventID.eventType.type == IdType::Name)
    {
        eventDataBuilder(currentEvent.getEventData(), p_XMLEvent);
    }

    return currentEvent;
}

void eventDataBuilder(std::shared_ptr<EventData> currentEventData, tinyxml2::XMLElement* p_XMLEvent)
{
    currentEventData->setText(textBuilder(p_XMLEvent->FirstChildElement("text")));
    
    // TODO: Why does replacing this with a do-while loop crash it?
    for (tinyxml2::XMLElement* p_itr = p_XMLEvent->FirstChildElement("choice"); p_itr != p_XMLEvent->LastChildElement("choice"); p_itr->NextSiblingElement("choice"))
    {
        currentEventData->insertChoice(choiceBuilder(p_itr));
    }
    currentEventData->insertChoice(choiceBuilder(p_XMLEvent->LastChildElement("choice")));
}

// Input is a pointer to the XML node containing the choice
Choice choiceBuilder(tinyxml2::XMLElement* p_XMLChoice)
{
    if (p_XMLChoice == nullptr) {
        return Choice();
    }

    return Choice(textBuilder(p_XMLChoice->FirstChildElement("text")), new Event(eventBuilder(p_XMLChoice->FirstChildElement("event"))));
}

Text textBuilder(tinyxml2::XMLElement* p_XMLText)
{
    if (p_XMLText == nullptr) {
        return Text();
    }

    // Text data
    return Text(getAttributeTypeFromXMLElement(p_XMLText));
}

AttributeType getAttributeTypeFromXMLElement(tinyxml2::XMLElement* p_XMLElement)
{
    // Throw maybe?
    if (p_XMLElement == nullptr) {
        return AttributeType();
    }

    AttributeType type;
    const char* textString;

    if (p_XMLElement->QueryStringAttribute("name", &textString) == tinyxml2::XML_SUCCESS)
    {
        type.type = IdType::Name;
        type.data = std::string(textString);
    }
    else if (p_XMLElement->QueryStringAttribute("load", &textString) == tinyxml2::XML_SUCCESS)
    {
        type.type = IdType::Load;
        type.data = std::string(textString);
    }
    else if (p_XMLElement->QueryStringAttribute("id", &textString) == tinyxml2::XML_SUCCESS)
    {
        type.type = IdType::Id;
        type.data = std::string(textString);
    }
    else
    {
        type.type = IdType::Direct;
        type.data = std::string(p_XMLElement->GetText());
    }

    return type;
}