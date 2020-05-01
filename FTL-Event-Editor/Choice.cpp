#include "Choice.h"
#include "Event.h"

Choice::Choice(Event* newEvent)
{
    m_p_event = std::make_shared<Event>(*newEvent);
}

Choice::Choice(Text newText, Event* newEvent) : m_text(newText)
{
    m_p_event = std::make_shared<Event>(*newEvent);
}

void Choice::setEvent(Event* newEvent)
{
    m_p_event.reset(); // Choice owns this.
    m_p_event = std::make_shared<Event>(*newEvent);
}

void Choice::printChoice()
{
    m_text.printText();
}

void Choice::printChoiceEvent()
{
    if (m_p_event != nullptr)
    {
        m_p_event->printEvent();
    }
}