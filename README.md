# FTL Event Editor

WIP: Allows the user to import, create, modify, delete, test, and export events for the video game FTL: Faster Than Light.
This is a work-in-progress. I hope to have a working version by the end of the year. But given how lazy I am, this is probably not going to occur.

## Features

### Planned

* Import, export: The user can take an entire event XML file and transfer the data into the program, and can also transfer the program's internal data into an XML file that's ready for FTL. This will be the most difficult part to debug.
* Create, modify, delete: The user can edit the data in the program, or even create new events.
* Test, simulate: The user can load in events and proceed just like in FTL. Note that more interaction is required (e.g. if a list is loaded the user must specify which item to load next).
* Interface: Something that is not just entering commands into a console. Visualization of the event tree. Maybe even click-and-drag.

### Implemented

* None, at the moment, since I'm refactoring.

## Usage Instructions

While one *could* simply double-click the binary file (.exe), it's better to run the program from the command prompt, as crashes won't immediately close the window. This would help immensely with bug testing. Open a new issue and copy-paste the inputs and outputs into the text field.

## Versioning

### Planned

Versioning is in the form of a.b.c where:
* a is major version, most likely due to refactoring.
* b is minor version, adding/changing functionality, mostly stable.
* c is the old "will compile" version containing runtime errors.
Note: Versioning numbers are more of a guide than a rule.

#### Alpha Versions

* 0.0.x Implementation of templated linked lists and nodes, basic commands (creating, finding, editing, deleting) for node and content manipulation
* 0.1.x Addition of FTL data (events, text, rewards, ships, equipment etc.) and simulation environment
* 0.1.3 Last version with linked list and nodes. 2019-09-13.
* 0.1.4 Refactoring using maps instead of linked lists. Start of proper versioning control with Git.
* 0.4 Quality assurance, UI changes, improved error feedback, forum post

#### Beta Versions

* 0.5 First finalized version of project for public consumption, bugfixes
* 0.6 Modify UI to be more user-friendly based on public feedback

#### Release Versions

* 1.0 Second finalized version of project for public consumption, bugfixes

## Conclusion

Hopefully everything goes to plan. I'm also thinking of adapting this to the other FTL XML files (blueprints, auto, etc.), but that will be later.

Xierumeng
