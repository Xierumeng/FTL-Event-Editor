#include <iostream>

#include "EventData.h"

void EventData::printEventData()
{
    m_text.printText();

    std::cout << "unique=";
    if (m_unique)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl;

    for (int i = 0; i < (int)m_choices.size(); i++)
    {
        std::cout << i << ". ";
        m_choices[i].printChoice();
    }

    std::string userInput = "";
    int choice = -1;

    // Choice loop
    while ((choice < 0 || choice >= (int)m_choices.size()) && (int)m_choices.size() > 0)
    {
        getline(std::cin, userInput);
        choice = stoi(userInput);
        
        if (choice >= 0 && choice < (int)m_choices.size())
        {
            m_choices[choice].printChoiceEvent();
            break;
        }
    }
}
