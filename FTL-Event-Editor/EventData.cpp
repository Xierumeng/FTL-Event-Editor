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

    std::cout << std::endl;
    std::cout << "CHOICES" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < (int)m_choices.size(); i++)
    {
        std::cout << (i + 1) << ". "; // Rebase to 1
        m_choices[i].printChoice();
        std::cout << std::endl;
    }

    if (m_choices.size() > 0)
    {
        std::cout << "0. Exit this event (return to main input)." << std::endl;
        std::cout << std::endl;

        std::string userInput = "";
        int choice = (int)m_choices.size();

        // Choice loop
        while (choice >= (int)m_choices.size())
        {
            std::cout << "Select a choice (choose a number): ";
            getline(std::cin, userInput);
            choice = stoi(userInput) - 1; // Rebase to 0

            if (choice >= 0 && choice < (int)m_choices.size())
            {
                m_choices[choice].printChoiceEvent();
                break;
            }
        }
    }
    else
    {
        std::cout << "No choices (end of event)." << std::endl;
    }
}
