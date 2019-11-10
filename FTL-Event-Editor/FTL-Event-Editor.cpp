/*
// ------------
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.4
// For FTL: 1.6? The latest, anyway
// Plan:    Adding own, simulating. Later: Import, export.
// Author:  Xierumeng
// Contact: https://github.com/Xierumeng/FTL-Event-Editor
// License: Copyright © 2019. All rights reserved.
// Notes:   For FTL Faster-than-Light. Use at your own risk; no liability is held to the author of this program.
// ------------
*/

/*
// ------------
// Program Conventions
//
// TODO: Things that will need to be modified later
// !!!!: Urgency
// FROM: Duplicates code
// TEST: For testing
//
// Classes: Constructor/destructor, get read functions, set write functions
// ------------
*/

#include "FTL-Event-Editor.h"
#include "tinyxml2.h"
#include <stdlib.h>
//#include <QApplication>
//#include <QPushButton>

int main()
{
    tinyxml2::XMLDocument eventXML;
    eventXML.LoadFile("D:/FTLDats/data/events.xml");

    ///*
    // <FTL>
    //   <event etc.>
    //     <text> We are here
    tinyxml2::XMLElement* textElement = eventXML.FirstChildElement("FTL")->FirstChildElement("event")->FirstChildElement("text");
    // <text>Now we are here</text>
    std::string text = textElement->GetText();
    //*/
    
    ///*
    // <FTL>
    //   <event etc.>
    //     <boarders etc.> We are here
    tinyxml2::XMLElement* boarderElement = eventXML.FirstChildElement("FTL")->FirstChildElement("event")->FirstChildElement("boarders");
    int minBoarders = 0;
    // <boarders min="Now we are here">
    boarderElement->QueryIntAttribute("min", &minBoarders);

    std::cout << "Hello? " << text << " " << minBoarders << std::endl;
    //eventXML.Print();
    
    system("PAUSE");
    return 0;
}