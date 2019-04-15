#include "Event.h"

Event::Event(std::string ID, Event* p_next) :
	Node(ID, p_next, nullptr),
	Unique{0},
	textType{ -1 },
	textID{ "" },

	distress{ 0 },
	repair{ 0 },
	store{ 0 },
	environment{ "" },
	target{ "" },

	modifyPursuit{ 0 },
	revealMap{ 0 },
	secretSector{ 0 },
	unlockShip{ "" },
	fleet{ "" },

	augment{ "" },
	drone{ "" },
	weapon{ "" },
	removeEquip{ "" },

	shipID{ "" },
	hostile{ 0 },

	questID{ "" },
	returnEvent{ 0 },
	p_choices{ new Linked_List }
{
}

Event::~Event()
{
	delete p_choices;
	p_choices = nullptr;
}

void Event::printSelf() {

	std::cout << "Name ID: " << id << std::endl;
	std::cout << "Unique tag: " << contents << std::endl;
	std::cout << "Event text: ";

	if (textType >= 0)
		std::cout << "(Reference) ";

	std::cout << textID << std::endl;

	std::cout << "Map distress: " << distress << std::endl;
	std::cout << "Map repair: " << repair << std::endl;
	std::cout << "Map store: " << store << std::endl;
	std::cout << "Environmental hazard: " << environment << std::endl;
	std::cout << "PDS target: " << target << std::endl;

	std::cout << std::endl;

	std::cout << "Fleet pursuit modifier: " << modifyPursuit << std::endl;
	std::cout << "Reveal sector: " << revealMap << std::endl;
	std::cout << "Secret sector: " << secretSector << std::endl;
	std::cout << "Unlock ship: " << unlockShip << std::endl;
	std::cout << "Background ships: " << fleet << std::endl;

	//Resources
	reward.printReward();
	std::cout << std::endl;
	items.printItem();
	std::cout << std::endl;

	std::cout << "New augment: " << augment << std::endl;
	std::cout << "New drone: " << drone << std::endl;
	std::cout << "New weapon: " << weapon << std::endl;
	std::cout << "Remove equipment: " << removeEquip << std::endl;

	std::cout << std::endl;

	//System
	damage.printDamage();
	std::cout << std::endl;
	status.printStatus();
	std::cout << std::endl;

	//Crew
	boarders.printBoarder();
	std::cout << std::endl;
	crew.printCrew();
	std::cout << std::endl;

	//Ship
	std::cout << "Ship: " << shipID << std::endl;
	std::cout << "Hostile: " << hostile << std::endl;
	std::cout << std::endl;

	std::cout << "Quest: " << questID << std::endl;
	std::cout << "Forcibly end event: " << returnEvent << std::endl;

	std::cout << std::endl;

	std::cout << "Choices: " << std::endl;

	for (Choice* p_currentChoice{ static_cast<Choice*>(p_choices->getHead()) }; p_currentChoice != nullptr; p_currentChoice = static_cast<Choice*>(p_currentChoice->getNext())) //!!!!
		std::cout << p_currentChoice->getID() << ". " << p_currentChoice->getValue(); //!!!!
}

Linked_List* Event::getChoiceList() {
	return p_choices;
}

void Event::replaceValue() {

	std::string command{ "" };
	int numCom{ 0 };

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input. Warning: changes you have made before cancelling will still exist." << std::endl;

	std::cout << std::endl;

	std::cout << "Unique tag (0 for no, 1 for yes): ";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	contents = numCom;

	std::cout << "Event text: ";
	std::cin >> textID;

	std::cout << "Map distress (0 for no, 1 for yes): ";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	distress = numCom;

	std::cout << "Map repair (0 for no, 1 for yes): ";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	repair = numCom;

	std::cout << "Map store (0 for no, 1 for yes): ";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	store = numCom;

	std::cout << "Environmental hazard: ";
	std::cin >> environment;
	std::cout << "PDS target: ";
	std::cin >> target;

	std::cout << "Fleet pursuit modifier (integer): ";
	std::cin >> modifyPursuit;
	std::cout << "Reveal sector (0 for no, 1 for yes):";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	revealMap = numCom;

	std::cout << "Secret sector (0 for no, 1 for yes):";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	secretSector = numCom;

	std::cout << "Unlock ship (0 for no, 1 for yes):";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	unlockShip = numCom;

	std::cout << "Background ships: ";
	std::cin >> fleet;

	reward.replace();
	items.replace();

	std::cout << "Augment: ";
	std::cin >> augment;
	std::cout << "Drone: ";
	std::cin >> drone;
	std::cout << "Weapon: ";
	std::cin >> weapon;
	std::cout << "Remove equipment: ";
	std::cin >> removeEquip;

	damage.replace();
	status.replace();

	//Crew
	boarders.replace();
	crew.replace();

	//Ship
	std::cout << "Ship: ";
	std::cin >> shipID;
	std::cout << "Hostile (0 for no, 1 for yes):";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	hostile = numCom;

	std::cout << "Quest: ";
	std::cin >> questID;
	std::cout << "Forcibly end event: ";
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	returnEvent = numCom;

	std::cout << std::endl;

	std::cout << "Edit choice list (y for yes, otherwise no): ";
	std::cin >> command;

	if (command == "y")
		replaceChoice();

	std::cout << std::endl;
	std::cout << "replaceValue in Event class operation completed." << std::endl;
}

void Event::replaceChoice() {

	std::string command{ "" };

	while (command != "EXIT") { //FROM main

		std::cout << "Editing: " << id << std::endl;
		std::cout << "ID's here don't really matter except for determining event order." << std::endl;
		std::cin >> command;

		if (command == "HELP") {

			std::cout << std::endl << "Valid commands are:" << std::endl << std::endl;
			std::cout << "EXIT  - Exits the event's choice editor." << std::endl;
			std::cout << "PRINT - Prints the current list of choices." << std::endl;
			std::cout << "NEW   - Creates a new choice with the specificed name without duplicates." << std::endl;
			std::cout << "ERASE - Deletes the specified choice and its sub-nodes." << std::endl;
			std::cout << std::endl << "WARNING: You will not be able to cancel an operation once it has begun." << std::endl;

		}
		else if (command == "PRINT")
			p_choices->printList();

		else if (command == "NEW") {

			std::cout << "New ID name: ";
			std::cin >> command;

			if (p_choices->findNode(command) != nullptr)
				std::cout << "An ID with this name already exists." << std::endl;

			else if (!p_choices->emptyList()) {

				if (p_choices->createNode(command, "") == 1)
					std::cout << command << " created successfully." << std::endl;

				else
					std::cout << "ERROR: Invalid return " << p_choices->createNode(command, "") << " on createNode." << std::endl;
			}

		}
		else if (command == "ERASE") {

			std::cout << "ID to delete: ";
			std::cin >> command;

			if (p_choices->findNode(command) == nullptr)
				std::cout << "Not found." << std::endl;

			else {

				if (p_choices->deleteNode(command))
					std::cout << command << " successfully deleted." << std::endl;

				else
					std::cout << "ERROR: Invalid return on deleteNode." << std::endl;
			}
		}
	}

	std::cout << "Replacing ID's with numbers in order..." << std::endl;

	int i{ 0 };
	for (Node* p_currentChoice{ p_choices->getHead() }; p_currentChoice != nullptr; p_currentChoice = p_currentChoice->getNext()) {

		i++;
		p_currentChoice->replaceID(std::to_string(i));
	}

	std::cout << "replaceChoice in Event class operation completed." << std::endl;
}
