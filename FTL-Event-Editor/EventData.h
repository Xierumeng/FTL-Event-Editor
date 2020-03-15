#pragma once
//#include <memory>

#include "Common.h"
#include "Choice.h"
#include "EventSupport.h"

class Choice;

// name= and unnamed
class EventData
{
public:

    EventData() = default;
    EventData(Text newText) : m_text(newText) {}
    ~EventData() = default;

    Text getText() { return m_text; }
    void setText(Text newText) { m_text = newText; }

    bool getUnique() { return m_unique; }
    void setUnique(bool newUnique) { m_unique = newUnique; }
    void toggleUnique() { m_unique = !m_unique; }

    bool getEventBreak() { return m_eventBreak; }
    void setEventBreak(bool newBreak) { m_eventBreak = newBreak; }
    void toggleEventBreak() { m_eventBreak = !m_eventBreak; }

    // Strings must include clear function

private:

    Text m_text;
    bool m_unique = false;
    bool m_eventBreak = false; // <event/>

    std::vector<Choice> m_p_choices;

#if 0 // TODO Remove when Event class testing complete
    // Beacon appearance
    Environment m_hazard = Environment::None;
    bool m_distress = false;
    bool m_repair = false;
    bool m_store = false;

    // Single-line XML items
    int m_modifyPursuit = 0; // Negative delays, positive speeds up fleet
    bool m_reveal_map = false; // Map has been updated
    bool m_secretSector = false; // Crystal sector
    Fleet m_fleet = Fleet::None; // Background ships
    int m_unlockShip = 0; // TODO: Make this an enumeration
    std::string m_quest = ""; // Makes a new quest with the event at that beacon

    // Resources
    std::string m_augment = "";
    std::string m_drone = "";
    std::string m_weapon = "";
    std::string m_remove = ""; // Removes equipment
    ItemModify m_item_modify; // Adds or removes consumables
#endif
};
