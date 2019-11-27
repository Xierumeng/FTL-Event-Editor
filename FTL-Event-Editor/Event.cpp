#include "Event.h"

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

Text getText();
std::string getTextString();
void setText(Text newText);

bool getUnique();
void setUnique(bool newUnique);

bool getEventBreak();
void setEventBreak();