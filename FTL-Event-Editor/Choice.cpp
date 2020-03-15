#include "Choice.h"
#include "Event.h"

Choice::Choice(Event* newEvent)
{
    p_m_event = std::make_shared<Event>(*newEvent);
}

Choice::Choice(Text newText, Event* newEvent) : m_text(newText)
{
    p_m_event = std::make_shared<Event>(*newEvent);
}

void Choice::setEvent(Event* newEvent)
{
    p_m_event.reset(); // Choice owns this.
    p_m_event = std::make_shared<Event>(*newEvent);
}