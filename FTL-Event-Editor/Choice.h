#pragma once
#include "Event.h"
#include "Common.h"

struct MaxGroup
{
    bool active = false;
    int value = 0;
};

class Choice
{
public:

    Choice() = default;
    Choice(Event newEvent) : m_event(newEvent) {}
    Choice(Text newText, Event newEvent) : m_text(newText), m_event(newEvent) {}
    ~Choice() = default;

    Text getText() { return m_text; }
    void setText(Text newText) { m_text = newText; }

    Event getEvent() { return m_event; }
    void setEvent(Event newEvent) { m_event = newEvent; }

private:

    Text m_text;
    Event m_event;

#if 0 // TODO Remove when Choice class testing complete
    bool m_blue = false;
    bool m_resultsHidden = false; // Outcome hidden e.g. rewards
    std::string m_requirement = "";
    int m_exactLevel = 0;
    int m_maxlevel = 0;
    MaxGroup m_maxGroup;
#endif
};

