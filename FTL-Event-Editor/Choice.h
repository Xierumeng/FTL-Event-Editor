#pragma once
#include <memory>

//#include "Event.h"
#include "Common.h"

class Event;

struct MaxGroup
{
    bool active = false;
    int value = 0;
};

// IMPORTANT: Choice will take ownership of the Event* passed into it!
class Choice
{
public:

    Choice() = default;
    Choice(Event* newEvent);
    Choice(Text newText, Event* newEvent);
    ~Choice() = default;

    Text getText() { return m_text; }
    void setText(Text newText) { m_text = newText; }

    std::shared_ptr<Event> getEvent() { return p_m_event; }
    void setEvent(Event* newEvent);

private:

    Text m_text;
    std::shared_ptr<Event> p_m_event;

#if 0 // TODO Remove when Choice class testing complete
    bool m_blue = false;
    bool m_resultsHidden = false; // Outcome hidden e.g. rewards
    std::string m_requirement = "";
    int m_exactLevel = 0;
    int m_maxlevel = 0;
    MaxGroup m_maxGroup;
#endif
};
