#include "Choice.h"
#include "Linked_List.h"
#include <iostream>

Choice::Choice(std::string ID, Choice* p_next) :
	Node(ID, p_next, nullptr),
	//choice{""},
	hidden{ 0 },
	blue{ 0 },
	req{ "None" },
	lvl{ 0 },
	maxLvl{ 0 },
	maxGroup{ 0 },
	textType{ -1 },
	textID{ "" },
	eventType{ -1 },
	eventID{ "" },
	p_event{ nullptr }
{
}

Choice::~Choice()
{
	delete p_event;
	p_event = nullptr;
}

void Choice::printSelf() {

	std::cout << "Name ID: " << id << std::endl;

	std::cout << std::endl;

	std::cout << "Choice text: " << contents << std::endl;
	std::cout << "Results text: ";

	if (textType >= 0)
		std::cout << "(Reference) ";

	std::cout << textID << std::endl;

	std::cout << std::endl;

	std::cout << "Results hidden: " << hidden << std::endl;
	std::cout << "Blue text: " << blue << std::endl;
	std::cout << "System required: " << req << std::endl;
	std::cout << "Minimum level: " << lvl << std::endl;
	std::cout << "Maximum level: " << maxLvl << std::endl;
	std::cout << "Maximum group: " << maxGroup << std::endl;

	std::cout << std::endl;

	std::cout << "Event ID: ";

	if (eventType >= 0)
		std::cout << "(Reference) " << eventID;

	else if (p_event != nullptr)
		std::cout << "(Subordinate) " << p_event->getID();

	std::cout << std::endl;
}

Event * Choice::getEvent() {
	return p_event;
}

void Choice::replaceValue() {

	std::string command{ "" };

	std::string choice{ "" };
	std::string result{ "" };
	int resultType{ -1 };
	bool hide{ 0 };
	bool bloo{ 0 };
	std::string required{ "None" };
	int level{ 0 };
	int maxLevel{ 0 };
	int maxGroups{ 0 };

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input or decline at end." << std::endl;

	std::cout << std::endl;

	std::cout << "Choice text: ";
	std::cin >> choice;
	std::cout << "Results text type (-1 for direct string, 0 for id=, 1 for load=): ";
	std::cin >> resultType;

	if (resultType < -1 || resultType > 1) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "Results text: ";
	std::cin >> result;

	std::cout << "Results hidden (0 for no, 1 for yes):";
	std::cin >> hide;

	if (hide < 0 || hide > 1) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "Blue text (0 for no, 1 for yes):";
	std::cin >> bloo;

	if (bloo < 0 || bloo > 1) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "System required text: ";
	std::cin >> required;
	std::cout << "Minimum level (positive integer): ";
	std::cin >> level;

	if (level < 0) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "Maximum level (positive integer): ";
	std::cin >> maxLevel;

	if (maxLevel < 0) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "Maximum group (positive integer): ";
	std::cin >> maxGroups;

	if (maxGroups < 0) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	std::cout << "Confirm changes (y for yes, otherwise no): ";
	std::cin >> command;

	if (command == "y") {

		contents = choice;
		textID = result;
		textType = resultType;
		hidden = hide;
		blue = bloo;
		req = required;
		lvl = level;
		maxLvl = maxLevel;
		maxGroup = maxGroups;

		std::cout << "Done." << std::endl;

	}
	else
		std::cout << "Operation aborted." << std::endl;

	std::cout << std::endl;

	std::cout << "Edit event ID (y for yes, otherwise no): ";
	std::cin >> command;

	if (command == "y")
		replaceEvent();

	std::cout << std::endl;
	std::cout << "replaceValue in Choice class operation completed." << std::endl;
}

void Choice::replaceEvent() {

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input. Otherwise, the event will be erased." << std::endl;

	int command{ 0 };

	std::cout << "Choice event type (-1 for direct string, 0 for id=, 1 for load=): ";
	std::cin >> command;

	if (command < -1 || command > 1) {

		std::cout << "Invalid input, operation aborted." << std::endl;
		return;
	}

	eventType = command;
	delete p_event;
	p_event = nullptr;

	if (eventType == -1) {
		p_event = new Event("", nullptr);

	}
	else {

		std::cout << "event ID: ";
		std::cin >> eventID;
	}
	std::cout << "replaceEvent in Choice class operation completed." << std::endl;
}