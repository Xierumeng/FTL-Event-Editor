#pragma once

#include "Common.h"
#include "EventSupport.h"

#include <string>

struct EventId
{
    IdType type = IdType::Name;
    std::string eventName = "";
};

class Event // load=
{
public:

    Event(std::string newId);
    ~Event() = default;

    EventId getEventId();
    std::string getEventIdString();
    IdType getEventType();

protected:

    EventId id; // Once set, cannot be changed
};

class EventName : Event // name=
{
public:

    EventName(std::string newId);
    EventName(const Event &oldEvent, std::string newName); // Copy constructor
    ~EventName() = default;

    Text getText();
    std::string getTextString();
    void setText(Text newText);

    bool getUnique();
    void setUnique(bool newUnique);

    bool getEventBreak();
    void setEventBreak();

private:

    Text text;
    bool unique;
    bool eventBreak; // <event/>

#if 0 // TODO Remove when Event class testing complete
    // Beacon appearance
    Environment hazard = Environment::None;
    bool distress = false;
    bool repair = false;
    bool store = false;

    // Single-line XML items
    int modifyPursuit = 0; // Negative delays, positive speeds up fleet
    bool reveal_map = false;
    bool secretSector = false; // Crystal sector
    Fleet fleet = Fleet::None;
    int unlockShip = 0;
    EventId quest;

    // Resources
    std::string augment = "";
    std::string drone = "";
    std::string weapon = "";
    std::string remove = ""; // Removes equipment
    ItemModify item_modify; // Adds or removes consumables
#endif
};