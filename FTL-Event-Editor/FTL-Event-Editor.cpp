/*
// ------------
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.4 //FROM PROGRAM_VERSION
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
#include <QApplication>
#include <QPushButton>

int main()
{
    tinyxml2::XMLDocument eventDoc;
    eventDoc.LoadFile("D:/Games/Science Fiction and Space/FTL Faster Than Light/Modding/Dats/data/events.xml");

    system("PAUSE");
    return 0;
}