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

Old system scrapped. Each new branch will follow the format FTLEE-#, where # is the issue at hand in the tracker.

## Conclusion

Hopefully everything goes to plan. I'm also thinking of adapting this to the other FTL XML files (blueprints, auto, etc.), but that will be later.

Xierumeng
