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

#include "Event.h"

#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
//#include <QApplication>
//#include <QPushButton>

int main()
{
    tinyxml2::XMLDocument eventXML;
    eventXML.LoadFile("D:/FTLDats/data/events.xml");

    std::vector<Event> eventList;

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