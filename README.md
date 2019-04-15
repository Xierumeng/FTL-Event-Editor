# FTL Event Editor

WIP: Allows the user to import, create, modify, delete, test, and export events for the video game FTL: Faster Than Light.
This is a work-in-progress. I hope to have version 0.5.0 done before 2019 September and version 1.0.0 done before 2020.

## Features

### Planned

* Import: The user can take an entire event xml and transfer the data into the program.
* Create, modify, delete: The user can edit the data in the program, or even create new events.
* Test, simulate: The user can load in events and proceed just like in FTL. Note that more interaction is required (e.g. if a list is loaded the user must specify which item to load next).
* Export: The user can transfer the program's internal data into an xml that's ready for FTL. This will be the most difficult part to debug.
* Interface: Something that is not just entering commands into a console. Maybe even click-and-drag.

### Implemented

* Create, modify, delete: Complete for events and text, but not ships. Also extremely buggy.

## Versioning

### Planned

Versioning is in the form of a.b.x.y where:
* a is major version, most likely due to refactoring.
* b is minor version, adding/changing functionality, mostly stable.
* x is patch version, code will compile but will have runtime errors (buggy/crashes).
* y is night version, code will not compile due to syntax errors.

#### Alpha Versions

* 0.0.x Implementation of templated linked lists and nodes, basic commands (creating, finding, editing, deleting) for node and content manipulation
* 0.1.x Addition of FTL data (events, text, rewards, ships, equipment etc.) and simulation environment
* 0.2.x Exporting program contents to XML format
* 0.3.x Importing XML to program-readable format
* 0.4.x Quality assurance, UI changes, improved error feedback, forum post

#### Beta Versions

* 0.5.x First finalized version of project for public consumption, bugfixes
* 0.6.x Modify UI to be more user-friendly based on public feedback
* 0.7.x ???
* 0.8.x ???
* 0.9.x ???

#### Release Versions

* 1.0.x Second finalized version of project for public consumption, bugfixes
* 2.0.x Overhaul if necessary

### Changelog

Please see the appropriate file.

## Conclusion

Hopefully everything goes to plan. I'm also thinking of adapting this to the other FTL xml files (blueprints, auto, etc.), but that will be for next year (2020).

Xierumeng
