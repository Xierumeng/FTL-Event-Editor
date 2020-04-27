/*
// ------------
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.5
// For FTL: 1.6? The latest, anyway
// Plan:    Adding own, simulating. Later: Import, export.
// Author:  Xierumeng
// Contact: https://github.com/Xierumeng/FTL-Event-Editor
// License: Copyright © 2020. All rights reserved.
// Notes:   For FTL Faster-than-Light. Use at your own risk; no liability is held to the author of this program.
// ------------
*/

/*
// ------------
// Program Conventions
//
// TODO: Things that will need to be modified later
// !!!!: Urgency
// FROM: Duplicate code
// TEST: For testing
//
// Classes: Constructor/destructor, get read functions, set write functions
// ------------
*/

// Change std::map::find to std::map::contains once C++20 is out.

#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Event.h"
#include "TreeBuilder.h"
#include "Logging.h"

//#include <QApplication>
//#include <QPushButton>

int main()
{
    // State variables
    // XML Document
    tinyxml2::XMLDocument eventXML;
    
    // Top nodes of tree
    // Using map to avoid duplicate named objects
    std::map<std::string, Event> events;
    std::map<std::string, EventList> eventLists;
    std::map<std::string, TextList> textLists;

    std::string userInput = "";

    // UI loop
    while (!std::cin.eof() && userInput != "exit") // When not at end of file
    {
        // User input
        getline(std::cin, userInput);

        // Skip if we're at the end
        if (std::cin.eof())
        {
            continue;
        }

        if (userInput.find("import ") != std::string::npos)
        {
            // Get parameters substring
            std::string userValue = userInput.substr(7);

            // User output
            if (eventXML.LoadFile(userValue.c_str()) == tinyxml2::XML_SUCCESS)
            {
                std::cout << "Successfully imported " << userValue << std::endl;

                tinyxml2::XMLElement* p_XMLFTLRoot = eventXML.FirstChildElement("FTL");
                if (p_XMLFTLRoot != nullptr)
                {
                    // Insertion loop
                    tinyxml2::XMLElement* p_itr = p_XMLFTLRoot->FirstChildElement("event");
                    while (p_itr != nullptr)
                    {
                        // Name check
                        if (!eventNameCheck(p_itr)) {
                            Log::warning("Top-level event has no name.");
                        }

                        Event tempEvent = eventBuilder(p_itr);

                        // Duplicate key check TODO: Change to ::contains
                        if (events.find(tempEvent.getEventIdString()) != events.end()) {
                            Log::warning("Duplicate event name. The event will be overwritten.");
                        }

                        events.insert({ tempEvent.getEventIdString(), tempEvent });
                        
                        std::cout << "Inserted " << tempEvent.getEventIdString() << std::endl;

                        p_itr = p_itr->NextSiblingElement("event");
                    }
                }

            }
            else
            {
                Log::error("import failure");
            }
        }

    }

    eventXML.LoadFile("D:/Repositories/FTL-Event-Editor/Tests/barebone_event.xml");

    tinyxml2::XMLElement* p_XMLFTLRoot = eventXML.FirstChildElement("FTL");
    if (p_XMLFTLRoot == nullptr)
    {
        throw;
    }

    p_XMLFTLRoot->Name();
    tinyxml2::XMLElement* p_XMLEvent = nullptr;
    p_XMLEvent = p_XMLFTLRoot->FirstChildElement();
    p_XMLEvent->Name();
    if (eventNameCheck(p_XMLEvent))
    {
        try
        {
            std::cout << "Event insertion start." << std::endl;
            Event tempEvent = eventBuilder(p_XMLEvent);
            events.insert({ tempEvent.getEventIdString(), tempEvent });
        }
        catch (...)
        {
            std::cout << "ERROR: eventBuilder exception." << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Failed to insert top-level nameless event." << std::endl;
    }

    // Example code
#if 0
    ///*
    // <FTL>
    //   <event etc.>
    tinyxml2::XMLElement* currentNode = eventXML.FirstChildElement("FTL")->FirstChildElement("event");
    //     <text> We are here
    tinyxml2::XMLElement* textElement = currentNode->FirstChildElement("text");
    // <text>Now we are in here</text>
    std::string text0 = textElement->GetText();
    //*/

    ///*
    // <FTL>
    //   <event etc.>
    //     <boarders etc.> We are here
    tinyxml2::XMLElement* boarderElement = currentNode->FirstChildElement("boarders");
    int minBoarders = 0;
    // <boarders min="Now we are here">
    boarderElement->QueryIntAttribute("min", &minBoarders);

    // To the next XML element (which is probably an event)
    currentNode = currentNode->NextSiblingElement();
    const char* eventName;
    currentNode->QueryStringAttribute("name", &eventName);

    // Hello? text0=="Oh no enemies!" minBoarders==3 eventName=="REMOVAL_TEST"
    std::cout << "Hello? " << text0 << " " << minBoarders << " " << eventName << std::endl;
#endif

    system("PAUSE");
    return 0;
}
