/*
// ------------
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.2 //FROM PROGRAM_VERSION
// Patch:   5
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
// FROM: Matches code (kinda) from other sections
// TEST: For testing
// TEMP: Needs to be changed after testing complete
//
// id  : Internal identification
// ID  : External identification
//
// One line separations between categories. Exceptions: One liners, bracket-only lines
// Classes: Constructor/destructor, read functions, write functions
// ------------
*/

/*
// ------------
// Program Notes
//
// CURRENT: Test global functions.
// TODO   : Complete class Ship and associated global functions.
// ------------
*/

#include "FTL-Event-Editor.h"

#define PROGRAM_VERSION "0.1.3" //FROM Version
#define MAX_CREW_PROP 4 //Crew types
//#define ZERONE "(0 for no, 1 for yes): " //Event, Choice
//#define TYPE "(-1 for direct string, 0 for id=, 1 for load=): " //Reference or direct
//#define CONFIRM "y for yes, otherwise no: " //y confirmation
//#define INVALID "Invalid input, operation aborted."
#define NOABORT "(Warning: You cannot abort this operation once it has begun)" //Cannot abort action once started

/* TODO Later
class Ship : public Node { //T value is autoB boolean //TODO
public:

	Ship(std::string ID, Event* p_next = nullptr);

protected:

	//bool autoB; //auto_blueprint?
	std::string blueprint;

	//Surrender_Escape chance; TODO

	Event destroyed;
	Event deadCrew;
	Event surrender;
	Event escape;
	Event gotaway;

	Crew_Member crew[MAX_CREW_PROP];
};

Ship::Ship(std::string ID, Event * p_next) :
	Node(ID, p_next, nullptr),
	//autoB{0},
	blueprint{ "" }
{
}*/

void findEvent(Event* p_event) { //!!!!

	int command{ 1 };
	Choice* p_choice{ nullptr };

	std::cout << std::endl;

	while (command >= 0) {

		while (command == 1) {

			p_event->printSelf();

			std::cout << std::endl;
			std::cout << "Enter an integer (0 to edit event and choice list, # to continue to choice, invalid to return to menu): ";
			std::cin >> command;
			std::cout << std::endl;

			if (command == 0)
				p_event->replaceValue();
		}

		p_choice = p_event->getChoiceList()->findNode(std::to_string(command)); //Converts command to string and then searches p_event's !!!! FIX
		if (p_choice == nullptr)
			command = -1;

		else
			command = 0;

		while (command == 0) {

			p_choice->printSelf();
			std::cout << "Enter an integer (0 to edit choice and event type, 1 to continue to event, invalid to return to menu)" << std::endl;
			std::cout << "Note: If the event is referenced you will be returned to menu. If you want edit the referenced event use FIND from the menu." << std::endl;
			std::cin >> command;
			std::cout << std::endl;

			if (command == 0)
				p_choice->replaceValue();

		}

		p_event = p_choice->getEvent();
		if (p_event == nullptr)
			command = -1;
	}
}

void helpText() {

	std::cout << std::endl << "Valid commands are:" << std::endl << std::endl;
	std::cout << "BACK   - Goes back to the main menu." << std::endl;
	std::cout << "PRINT  - Prints the current table of items." << std::endl;
	std::cout << "FIND   - Searches for the item specificed and prints its contents. For events, allows you to edit the contents as well." << std::endl;
	std::cout << "CREATE - Creates a new item with the specificed name without duplicates. The item starts without any data." << std::endl;
	std::cout << "EDIT   - Replaces the contents of the item with the specified input. Not used for events (use FIND instead)." << std::endl;
	std::cout << "DELETE - Deletes the specified item and its contents. This is irreversible." << std::endl;
	//std::cout << "IMPORT - Imports an XML file into the program." << std::endl;
	//std::cout << "EXPORT - Exports program contents into an XML file." << std::endl;
	std::cout << std::endl << "Warning: You might not be able to cancel an operation once it has begun." << std::endl;
}

void eventMenu(Linked_List<Event>* eventList) {

	Event* p_current{ nullptr }; //Keep for load functions
	//Event* p_event{ nullptr }; //For findEvent TODO

	bool back{ 0 };
	std::string command{ "" };
	std::string parent{ "" };

	while (!back) {

		std::cout << std::endl << "In event table menu (enter HELP for a list of valid commands): ";
		std::cin >> command;

		if (command == "BACK") //FROM replaceChoice
			back = 1;

		else if (command == "HELP")
			helpText();

		else if (command == "PRINT")
			eventList->printList();

		else if (command == "FIND") {

			std::cout << "Event ID to find: ";
			std::cin >> command;
			p_current = eventList->findNode(command);

			if (p_current == nullptr)
				std::cout << "ID not found." << std::endl;

			else
				findEvent(p_current);
		}
		else if (command == "CREATE") {

			std::cout << "New event ID name: ";
			std::cin >> command;

			if (eventList->findNode(command) != nullptr)
				std::cout << "An ID with this name already exists." << std::endl;

			else {

				if (!eventList->emptyList()) {

					std::cout << "Under parent (if you don't want under parent, type a non-existent ID: ";
					std::cin >> parent;
				}

				if (eventList->findLinearNode(parent) == nullptr)
					parent = "";

				if (eventList->createNode(command, parent) == 1) {

					std::cout << command << " created successfully";

					if (parent != "")
						std::cout << " under " << parent;

					std::cout << "." << std::endl;

				}
				else
					std::cout << "ERROR: Invalid return " << eventList->createNode(command, parent) << " on createNode." << std::endl;
			}

		}
		/*else if (command == "EDIT") {

			std::cout << "Event ID to modify: ";
			std::cin >> command;
			p_current = eventList->findNode(command);

			if (p_current == nullptr)
				std::cout << "Not found." << std::endl;

			else {

				std::cout << "Contents of text ID replacement text: ";
				std::cin >> command;
				eventList->modifyNode(p_current, 0);
				p_current = nullptr;
				std::cout << command << " replaced successfully." << std::endl;
			}

		}*/
		else if (command == "DELETE") {

			std::cout << "Event ID to delete: ";
			std::cin >> command;

			if (eventList->findNode(command) == nullptr)
				std::cout << "ID not found." << std::endl;

			else {

				if (eventList->deleteNode(command))
					std::cout << command << " successfully deleted." << std::endl;

				else
					std::cout << "ERROR: Invalid return 0 on deleteNode." << std::endl;
			}

		}
		else
			std::cout << "Invalid command, type HELP for help." << std::endl;
	}
}

//void shipMenu(Linked_List *shipList); //TODO

int main() {

	Linked_List<std::string> textList;
	//Linked_List<std::string> shipList;
	Linked_List<Event> eventList;
	int command{ 0 };

	std::cout << "FTL Event Simulator v" << PROGRAM_VERSION << std::endl;
	std::cout << "Disclaimer: This is Xierumeng's program and is extremely buggy. Xierumeng is not liable for any losses of data due to bugs or crashes from you using this. If you do encounter such problems, please open an issue on Github (https://github.com/Xierumeng/FTL-Event-Editor) so Xierumeng can fix it." << std::endl;

	while (command != 4) { //FROM replaceChoice

		std::cout << "Please choose a table to edit (enter a number):" << std::endl;
		std::cout << "1. TEXT" << std::endl;
		std::cout << "2. SHIP (WIP, coming soon)" << std::endl; //TODO
		std::cout << "3. EVENT" << std::endl;
		std::cout << "4. EXIT" << std::endl;
		std::cin >> command;

		/*if (command == 4)
			exit = 1;*/

		if (command == 1)
			textMenu(&textList);

		else if (command == 2) //TODO
			std::cout << "TODO Coming soon!" << std::endl;
		//shipMenu(&shipList);

		else if (command == 3)
			eventMenu(&eventList);

		else
			std::cout << "Invalid command." << std::endl;
	}

	std::cout << "Ending program." << std::endl;
	system("PAUSE");
	return 0;
}

void textMenu(Linked_List<std::string>* textList) { //FROM [...]Menu //TODO: Possibly add templated functions?

	Node<std::string>* p_current{ nullptr }; //Keep for load functions

	bool back{ 0 };
	std::string command{ "" };
	std::string parent{ "" };

	while (!back) {

		std::cout << std::endl << "In text table menu (enter HELP for a list of valid commands): ";
		std::cin >> command;

		if (command == "BACK") //FROM replaceChoice
			back = 1;

		else if (command == "HELP")
			helpText();

		else if (command == "PRINT")
			textList->printList();

		else if (command == "FIND") {

			std::cout << "Text ID to find: ";
			std::cin >> command;
			p_current = textList->findNode(command);

			if (p_current == nullptr)
				std::cout << "ID not found." << std::endl;

			else {

				std::cout << std::endl;
				textList->printNode(p_current); //Finds the node, then prints its ID and contents
				p_current = nullptr;
			}

		}
		else if (command == "CREATE") {

			std::cout << "New text ID name: ";
			std::cin >> command;

			if (textList->findNode(command) != nullptr)
				std::cout << "An ID with this name already exists." << std::endl;

			else {

				if (!textList->emptyList()) {

					std::cout << "Under parent (if you don't want under parent, type a non-existent ID: ";
					std::cin >> parent;
				}

				if (textList->findLinearNode(parent) == nullptr)
					parent = "";

				if (textList->createNode(command, parent) == 1) {

					std::cout << command << " created successfully with no parent";

					if (parent != "")
						std::cout << " under " << parent;

					std::cout << "." << std::endl;

				}
				else
					std::cout << "ERROR: Invalid return " << textList->createNode(command, parent) << " on createNode." << std::endl;
			}

		}
		else if (command == "EDIT") {

			std::cout << "Text ID to modify: ";
			std::cin >> command;
			p_current = textList->findNode(command);

			if (p_current == nullptr)
				std::cout << "ID not found." << std::endl;

			else {

				std::cout << "Contents of text ID replacement text: ";
				std::cin >> command;
				textList->modifyNode(p_current, command);
				//std::cout << p_current->getID << " replaced successfully." << std::endl; !!!!
				p_current = nullptr;
			}

		}
		else if (command == "DELETE") {

			std::cout << "Text ID to delete: ";
			std::cin >> command;

			if (textList->findNode(command) == nullptr)
				std::cout << "ID not found." << std::endl;

			else {

				if (textList->deleteNode(command))
					std::cout << command << " successfully deleted." << std::endl;

				else
					std::cout << "ERROR: Invalid return 0 on deleteNode." << std::endl;
			}

		}
		else
			std::cout << "Invalid command, type HELP for help." << std::endl;
	}
}