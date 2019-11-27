#pragma once

#include "Common.h"
#include "EventSupport.h"

#include <string>
#include <vector>

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
    EventName(Event const &oldEvent, std::string newId = ""); // Copy constructor
    ~EventName() = default;

    Text getText();
    std::string getTextString();
    IdType getTextType();
    void setText(Text newText);

    bool getUnique();
    void setUnique(bool newUnique);
    void toggleUnique();

    bool getEventBreak();
    void setEventBreak(bool newBreak);
    void toggleEventBreak();

private:

    Text text;
    bool unique;
    bool eventBreak; // <event/>

    std::vector<Choice*> choices;

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