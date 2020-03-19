#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Common.h"
#include "EventSupport.h"
#include "EventData.h"

struct EventId
{
    EventId() = default;
    EventId(AttributeType newType) : eventType(newType) {}
    EventId(std::string name, IdType type)
    {
        eventType.type = type;
        eventType.data = name;
    }
    ~EventId() = default;

    AttributeType eventType;
};

// Event class
class Event
{
public:

    Event() = default; // name=

    Event(std::string eventIdName) : m_id(EventId(eventIdName, IdType::Name)) // name=
    {
        resetEventData();
    }

    Event(EventId newId) :
        m_id(newId)
    {
        if (m_id.eventType.type == IdType::Name)
        {
            resetEventData();
        }
    }

    EventId getEventId() { return m_id; }
    std::string getEventIdString() { return m_id.eventType.data; }
    IdType getEventType() { return m_id.eventType.type; }

    std::shared_ptr<EventData> getEventData() { return m_p_eventData; }
    void resetEventData()
    {
        m_p_eventData.reset();
        m_p_eventData = std::make_shared<EventData>(EventData());
    }

private:

    EventId m_id; // IMPORTANT: Once set, should ABSOLUTELY NOT be changed
    std::shared_ptr<EventData> m_p_eventData = nullptr; // name= event data
};

struct EventList
{
    std::string name = "";
    std::vector<Event> events;
};
