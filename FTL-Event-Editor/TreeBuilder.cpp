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
    // Base case
    if (p_XMLEvent == nullptr) return Event(); // TODO: Base case
    
    // Event name or load attribute
    EventId eventID;
    const char* eventName;

    if (p_XMLEvent->QueryStringAttribute("name", &eventName) == tinyxml2::XML_SUCCESS)
    {
        eventID.eventType = IdType::Name;
        eventID.eventName = std::string(eventName);

        // <event name="" load=""> is wrong.
        if (p_XMLEvent->QueryStringAttribute("load", &eventName) == tinyxml2::XML_SUCCESS) throw;
    }
    else if (p_XMLEvent->QueryStringAttribute("load", &eventName) == tinyxml2::XML_SUCCESS)
    {
        eventID.eventType = IdType::Load;
        eventID.eventName = std::string(eventName);
    }

    // Start building the event
    Event currentEvent(eventID);

    if (eventID.eventType == IdType::Load) return currentEvent;

    eventDataBuilder(currentEvent.getEventData(), p_XMLEvent);
    return currentEvent;
}

void eventDataBuilder(std::shared_ptr<EventData> currentEventData, tinyxml2::XMLElement* p_XMLEvent)
{
    
    currentEventData->setText();
}

// Input is a pointer to the XML node containing the choice
Choice choiceBuilder(tinyxml2::XMLElement* p_XMLChoice)
{
    if (p_XMLChoice == nullptr) return Choice();

}

Text textBuilder(tinyxml2::XMLElement* p_XMLText)
{
    if (p_XMLText == nullptr) return Text();


}