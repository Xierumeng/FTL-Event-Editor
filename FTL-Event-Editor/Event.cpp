#include "Event.h"

// Event
Event::Event(std::string newId)
{
    id.eventName = newId;
    id.type = IdType::Load;
}

EventId Event::getEventId()
{
    return id;
}

std::string Event::getEventIdString()
{
    return id.eventName;
}

IdType Event::getEventType()
{
    return id.type;
}

// EventName
EventName::EventName(std::string newId):
    Event(newId)
{
    id.type = IdType::Name;
}

// TODO FIX THIS COPY CONSTRUCTOR
EventName::EventName(Event const &oldEvent, std::string newId):
    EventName(newId)
{

}

Text EventName::getText()
{
    return text;
}

std::string EventName::getTextString()
{
    return text.data;
}

IdType EventName::getTextType()
{
    return text.type;
}

void EventName::setText(Text newText)
{
    text = newText;
}

bool EventName::getUnique()
{
    return unique;
}

void EventName::setUnique(bool newUnique)
{
    unique = newUnique;
}

void EventName::toggleUnique()
{
    unique = !unique;
}

bool EventName::getEventBreak()
{
    return eventBreak;
}

void EventName::setEventBreak(bool newBreak)
{
    eventBreak = newBreak;
}

void EventName::toggleEventBreak()
{
    eventBreak = !eventBreak;
}