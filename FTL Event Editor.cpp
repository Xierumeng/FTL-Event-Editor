/*
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.1 //FROM PROGRAM_VERSION
// For FTL: 1.6? The latest, anyway
// Plan:    Adding own, simulating. Later: Import, export.
// Author:  Xierumeng
// Contact: xierumeng <at] hotmail (dot} com
// License: Copyright © 2019
// Notes:   For FTL Faster-than-Light. Use at your own risk; no liability is held to the author of this program.
*/

/*
// Program Conventions
//
// TODO: Things that will need to be modified later
// !!!!: Urgency
// FROM: Matches code(-ish) from other sections
// TEST: For testing
//
// id  : Internal identification
// ID  : External identification
//
// One line separations between categories. Exceptions: One liners, bracket-only lines
// Classes: Constructor/destructor, read functions, write functions
*/

/*
// Program Notes
//
// CURRENT: Add subclasses to Node to handle anything with "name" (event, eventList, [equipment], text, textList, crewMember id, ship, basically anything with an ID).
// TODO   : Handle "[...]List" since they won't have names.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define PROGRAM_VERSION "0.1.1" //FROM Version
#define MAX_CREW_PROP 4 //Crew types
#define ZERONE "(0 for no, 1 for yes): " //Event, Choice
#define TYPE "(-1 for direct string, 0 for id=, 1 for load=): " //Reference or direct
#define CONFIRM "y for yes, otherwise no: " //y confirmation
#define INVALID "Invalid input, operation aborted."
#define NOABORT "(WARNING: You cannot abort this operation once it has begun)" //Cannot abort action once started

class Choice;
class Event;
class Ship;

template <typename T>
class Node;
template <typename T>
class Linked_List;
int main();

//Class templates

template <typename T>
class Node{
public:

    Node(std::string ID, Node<T> *p_next = nullptr, Node<T> *p_head = nullptr);
    ~Node();

	virtual void printSelf(); //Prints the node contents
    std::string getID(); //Returns the ID
    //T getValue(); //Returns the stored value
    Node<T> *getNext(); //Returns next node
    Node<T> *getHead(); //Returns head list

	void replaceID(std::string ID); //Replaces ID //THIS SHOULD ONLY BE USED FOR EVENT CHOICE SORTING
    virtual void replaceValue(T newValue); //Replaces contents
    void replaceNext(Node<T> *p_next); //Updates pointer to next node
    void replaceHead(Node<T> *p_head); //Updates pointer to list head

protected:

    std::string id; //Name of the node
    T contents; //Contents of the node
    Node<T> *p_nextNode; //Points to next node in alphabetical order
    Node<T> *p_listHead; //Points to new list of the type

template <typename S>
friend class Linked_List; //TODO: Do we really want Linked_List to be able to touch Node's privates?
};

template <typename T>
Node<T>::Node(std::string ID, Node<T> *p_next, Node<T> *p_head):
id{ID},
p_nextNode{p_next},
p_listHead{p_head}
{
}

template <typename T>
Node<T>::~Node() //FROM ~Linked_List()
{
    Node<T> *p_next{p_listHead};

    while(p_listHead != nullptr){

        p_next = p_listHead->getNext();
        delete p_listHead;
        p_listHead = p_next;
    }
}

template <typename T>
void Node<T>::printSelf(){

	std::cout << "Name ID: " << id << std::endl;
    std::cout << "Contents: " << contents << std::endl;
	std::cout << "Subnodes:" << std::endl;

    for(Node<T> *p_subNode{p_listHead}; p_subNode != nullptr; p_subNode = p_subNode->getNext()){
        std::cout << " - " <<p_subNode->getID() << std::endl;

        //if (p_subNode == nullptr)
        //    std::cout << std::endl;
    }

}

template <typename T>
std::string Node<T>::getID(){
    return id;
}

/*template <typename T>
T Node<T>::getValue(){
    return contents;
}*/

template <typename T>
Node<T> *Node<T>::getNext(){
    return p_nextNode;
}

template <typename T>
Node<T> *Node<T>::getHead(){
    return p_listHead;
}

template <typename T>
void Node<T>::replaceID(std::string ID){
	id = ID;
}

template <typename T>
void Node<T>::replaceValue(T newValue){
    contents = newValue;
}

template <typename T>
void Node<T>::replaceNext(Node<T> *p_next){
    p_nextNode = p_next;
}

template <typename T>
void Node<T>::replaceHead(Node<T> *p_head){
    p_listHead = p_head;
}

template <typename T>
class Linked_List{
public:

    Linked_List(); //Constructor
    ~Linked_List(); //Destructor

    Node<T> *getHead();
    bool emptyList(); //Checks if list is empty
    void printList(); //Prints all list ID's (by all, we mean ALL)
    Node<T> *findNode(std::string findID); //Finds the node matching ID
	Node<T> *findLinearNode(std::string findID); //Find the node in a single list
    void printNode(Node<T> *p_next); //Prints value of a node, and subnode ID's

    int createNode(std::string createID, std::string parentID); //Creates a new node with corresponding id
    void modifyNode(Node<T> *p_currentNode, T newValue); //Replaces the contents of the found ID
    int deleteNode(std::string deleteID); //Deletes the node with corresponding id

private:

    Node<T> *p_listHead; //Head of list
};

template <typename T>
Linked_List<T>::Linked_List():
    p_listHead{nullptr}
{
}

template <typename T>
Linked_List<T>::~Linked_List() //FROM ~Node()
{
    Node<T> *p_next{p_listHead};

    while(p_listHead != nullptr){

        p_next = p_listHead->getNext();
        delete p_listHead;
        p_listHead = p_next;
    }
}

template <typename T>
Node<T> *Linked_List<T>::getHead(){
    return p_listHead;
}

template <typename T>
bool Linked_List<T>::emptyList(){
    return (p_listHead == nullptr);
}

template <typename T>
void Linked_List<T>::printList(){

    for(Node<T> *p_currentNode{p_listHead}; p_currentNode != nullptr; p_currentNode = p_currentNode->getNext()){
        //Start with list head then increment through until end of list

        std::cout << p_currentNode->getID() << std::endl;
        //if (p_currentNode->getHead() != nullptr) //FROM: printNode
        //   std::cout << "    Sublist: ";

        for(Node<T> *p_subNode{p_currentNode->getHead()}; p_subNode != nullptr; p_subNode = p_subNode->getNext()){

            std::cout << " - " << p_subNode->getID() << std::endl;
            //if (p_subNode == nullptr)
            //    std::cout << std::endl;
        }
    }
}

template <typename T>
Node<T> *Linked_List<T>::findNode(std::string findID){

    if (!emptyList()){

        Node<T> *p_currentNode{p_listHead};
        Node<T> *p_subNode{p_currentNode->getHead()};

        while(p_currentNode != nullptr){ //FROM: deleteNode

			p_subNode = p_currentNode->getHead();

            if (!findID.compare(p_currentNode->getID())) //If ID matches
                    return p_currentNode;

            while(p_subNode != nullptr){ //Skips second bit if p_subNode is nullptr

                if (!findID.compare(p_subNode->getID()))
                    return p_subNode;

                p_subNode = p_subNode->getNext();
            }

            p_currentNode = p_currentNode->getNext();
        }
    }

    return nullptr;
}

template <typename T>
Node<T> *Linked_List<T>::findLinearNode(std::string findID){

    Node<T> *p_currentNode{p_listHead};
    int unMatch{1};

    while(p_currentNode != nullptr && unMatch > 0){ //Start with list head then increment through matches or passes match point FROM: createNode, deleteNode

        unMatch = findID.compare(p_currentNode->getID());

        if (unMatch) //Skips increment if it matches
                p_currentNode = p_currentNode->getNext();
    }

    if (!unMatch)
        return p_currentNode;
}

template <typename T>
void Linked_List<T>::printNode(Node<T> *p_current){
	p_current->printSelf();
}

template <typename T>
int Linked_List<T>::createNode(std::string createID, std::string parentID){
	//List is empty - Just create new node.
	//Otherwise, check for duplicate from createID - return 0 if it does.
	//Can't find parentID - return -1.
	//Inserted successfully - return 1.

    if (emptyList()){

        p_listHead = new Node<T>(createID, nullptr);
        return 1;

	}else if (findNode(createID) != nullptr)
		return 0;

    else{

        Node<T> *p_currentNode{p_listHead};
		Node<T> *p_previousNode{nullptr};
        int unMatch{1};

		if (parentID != ""){ //If the parentID exists, find the parentID node

			while(p_currentNode != nullptr && unMatch > 0){
                //Start with list head then increment through until matches FROM: findLinearNode, slightly lower down

				unMatch = parentID.compare(p_currentNode->getID());

				if (unMatch > 0)
					p_currentNode = p_currentNode->getNext();
			}

			if (unMatch)
				return -1; //Could not find parentID

			p_previousNode = p_currentNode;
			p_currentNode = p_currentNode->getHead();
		}

		unMatch = 1;

        while(p_currentNode != nullptr && unMatch > 0){
            //Start with list head then increment through until matches or passes FROM: findLinearNode, slightly higher up

            unMatch = createID.compare(p_currentNode->getID());

            if (unMatch > 0){

                p_previousNode = p_currentNode;
                p_currentNode = p_currentNode->getNext();
            }
        }

        if (p_previousNode != nullptr){

			if (!parentID.compare(p_previousNode->getID())) //If the previous node is the parentID
				p_previousNode->replaceHead(new Node<T>(createID, p_currentNode));

			else
				p_previousNode->replaceNext(new Node<T>(createID, p_currentNode));

		}else
			p_listHead = new Node<T>(createID, p_currentNode);

        return 1;
    }
}

template <typename T>
void Linked_List<T>::modifyNode(Node<T> *p_currentNode, T newValue){
        p_currentNode->replaceValue(newValue);
}

template <typename T>
int Linked_List<T>::deleteNode(std::string deleteID){

    if (emptyList())
        return 0;

    else{

        Node<T> *p_currentNode{p_listHead};
		Node<T> *p_subNode{p_currentNode->getHead()};
        Node<T> *p_previousNode{nullptr};
        int unMatch{1};
		bool subList{0};

        while(p_currentNode != nullptr && unMatch){ //FROM: findNode

			subList = 0;
			unMatch = deleteID.compare(p_currentNode->getID());

			if (unMatch){ //If the ID does not match

				p_subNode = p_currentNode->getHead();
				p_previousNode = p_currentNode;
				unMatch = 1;
				subList = 1;

				while(p_subNode != nullptr && unMatch > 0){
                    //Start with list head then increment through matches or passes match point FROM: findLinearNode, createNode

					unMatch = deleteID.compare(p_subNode->getID());

					if (unMatch){ //Skips increment if it matches
						p_previousNode = p_subNode;
						p_subNode = p_subNode->getNext();

					}
				}
			}

			if (unMatch){
				p_previousNode = p_currentNode;
				p_currentNode = p_currentNode->getNext();

			}
		}

        if (!unMatch){

            if (p_previousNode != nullptr){

				if (subList)
					p_currentNode = p_subNode;

				if (p_previousNode->getHead() != p_currentNode)
					p_previousNode->replaceNext(p_currentNode->getNext()); //Update previous node's next

				else
					p_previousNode->replaceHead(p_currentNode->getNext()); //Update previous node's head

			}else
				p_listHead = nullptr;

            delete p_currentNode;
            return 1;

        }else
            return 0;
    }
}

//Data containers
class Auto_Reward{
public:

    Auto_Reward();
    void printReward(){
        std::cout << "Reward level: " << level << std::endl;
        std::cout << "Reward type: " << rewardType << std::endl;
    }

	void replace(){
		std::cout << "Reward level: ";
		std::cin >> level;
        std::cout << "Reward type: ";
		std::cin >> rewardType;
	}

	std::string level;
	std::string rewardType;
};

Auto_Reward::Auto_Reward():
level{""},
rewardType{""}
{
}

class Item_Modify{
public:

    Item_Modify();
    void printItem(){
        std::cout << "Item modification:" << std::endl;
        std::cout << " -Scrap min: " << scrap[0] << std::endl;
        std::cout << " -Scrap max: " << scrap[1] << std::endl;
        std::cout << " -Fuel min: " << fuel[0] << std::endl;
        std::cout << " -Fuel max: " << fuel[1] << std::endl;
        std::cout << " -Missiles min: " << missiles[0] << std::endl;
        std::cout << " -Missiles max: " << missiles[1] << std::endl;
        std::cout << " -Drones min: " << drones[0] << std::endl;
        std::cout << " -Drones max: " << drones[1] << std::endl;
		std::cout << " -Steal: " << steal << std::endl;
    }

	void replace(){
        std::cout << "Scrap min (integer): ";
		std::cin >> scrap[0];
        std::cout << "Scrap max (integer): ";
		std::cin >> scrap[1];
        std::cout << "Fuel min (integer): ";
		std::cin >> fuel[0];
        std::cout << "Fuel max (integer): ";
		std::cin >> fuel[1];
        std::cout << "Missiles min (integer): ";
		std::cin >> missiles[0];
        std::cout << "Missiles max (integer): ";
		std::cin >> missiles[1];
        std::cout << "Drones min (integer): ";
		std::cin >> drones[0];
        std::cout << "Drones max (integer): ";
		std::cin >> drones[1];
		std::cout << "Steal (positive integer): ";
		std::cin >> steal;
	}

	int scrap[2]; //min, max
	int fuel[2];
	int missiles[2];
	int drones[2];
	bool steal;
};

Item_Modify::Item_Modify():
steal{0}
{

    for (int i{0}; i < 2; i++){

		scrap[i] = 0;
		fuel[i] = 0;
		missiles[i] = 0;
		drones[i] = 0;
	}
}

class System_Damage{
public:

    System_Damage();
    void printDamage(){
        std::cout << "Damage amount: " << amount << std::endl;
        std::cout << "Damaged system: " << system << std::endl;
        std::cout << "Damage effect: " << effect << std::endl;
    }

	void replace(){
		std::cout << "Damage amount (integer): ";
		std::cin >> amount;
        std::cout << "Damaged system: ";
		std::cin >> system;
        std::cout << "Damage effect: ";
		std::cin >> effect;
	}

	int amount;
	std::string system;
	std::string effect;
};

System_Damage::System_Damage():
amount{0},
system{""},
effect{""}
{
}

class System_Status{
public:

    System_Status();
    void printStatus(){
        std::cout << "Status type: " << type << std::endl;
        std::cout << "Status target ship: " << target << std::endl;
        std::cout << "Status system: " << system << std::endl;
        std::cout << "Status amount: " << amount << std::endl;
    }

	void replace(){
		std::cout << "Status type: ";
		std::cin >> type;
        std::cout << "Status target ship: ";
		std::cin >> target;
        std::cout << "Status system: ";
		std::cin >> system;
        std::cout << "Status amount: ";
		std::cin >> amount;
	}

	std::string type;
	std::string target;
	std::string system;
	unsigned int amount;
};

System_Status::System_Status():
type{""},
target{""},
system{""},
amount{0}
{
}

class Crew_Boarder{
public:

    Crew_Boarder();
    void printBoarder(){
        std::cout << "Boarder race: " << classRace << std::endl;
        std::cout << "Minimum: " << num[0] << std::endl;
        std::cout << "Maximum: " << num[1] << std::endl;
        std::cout << "Boarder breach: " << breach << std::endl;
    }

	void replace(){
		std::cout << "Boarder race: ";
		std::cin >> classRace;
        std::cout << "Minimum (positive integer): ";
		std::cin >> num[0];
        std::cout << "Maximum (positive integer): ";
		std::cin >> num[1];
        std::cout << "Boarder breach (positive integer): ";
		std::cin >> breach;
	}

	std::string classRace;
	unsigned int num[2]; //Max must be below 9
	bool breach;
};

Crew_Boarder::Crew_Boarder():
classRace{""},
breach{0}
{
    for (int i{0}; i < 2; i++)
        num[i] = 0;
}

class Crew_Member{
public:

    Crew_Member();
    void printCrew(){
        std::cout << "Crew number: " << amount << std::endl;
        std::cout << "Crew skill: " << skill << std::endl;
        std::cout << "Crew skill level: " << level << std::endl;
        std::cout << "Crew name ID: " << id << std::endl;
    }

	void replace(){
		std::cout << "Crew number (integer): ";
		std::cin >> amount;
        std::cout << "Crew skill: ";
		std::cin >> skill;
        std::cout << "Crew skill level (positive integer): ";
		std::cin >> level;
        std::cout << "Crew name ID: ";
		std::cin >> id;
	}

	void printProp(){
		std::cout << "Crew proportion: " << proportion << std::endl;
	}

	void replaceProp(){
		std::cout << "Crew proportion (number): ";
		std::cin >> proportion;
	}

	int amount;
	std::string skill; //all_skills, pilot, etc.
	unsigned int level; //1 or 2
	std::string classRace;
	std::string id; //Force name

	double proportion; //For Ship class crew proportion
};

Crew_Member::Crew_Member():
amount{0},
skill{""},
level{0},
classRace{""},
id{"None"},
proportion{0}
{
}

class Surrender_Escape{
public:

    Surrender_Escape();
    void print(){
        std::cout << "Enemy Chance: " << chance << std::endl;
        std::cout << "Enemy Timer: " << timer << std::endl;
        std::cout << "Minimum: " << num[0] << std::endl;
        std::cout << "Maximum: " << num[1] << std::endl;
    }

	void replace(){
		std::cout << "Enemy Chance (number): ";
		std::cin >> chance;
        std::cout << "Enemy Timer (integer): ";
		std::cin >> timer;
        std::cout << "Minimum (integer): ";
		std::cin >> num[0];
        std::cout << "Maximum (integer): ";
		std::cin >> num[1];
	}

	double chance;
	int timer;
	int num[2];
};

Surrender_Escape::Surrender_Escape():
chance{0},
timer{0}
{
    for (int i{0}; i < 2; i++)
        num[i] = 0;
}

class Event: public Node<bool>{ //T value is unique tag
public:

	Event(std::string ID, Event *p_next);
	~Event();

	void printSelf(); //TODO

	void replaceValue();
	void replaceChoice();

protected:

	//bool Unique;

	//Event text
	int textType; //FROM Choice -1 for direct string, 0 for id=, 1 for load=
	std::string textID;

	//Beacon appearance only
	bool distress;
	bool repair;
	bool store;
	std::string environment;
	std::string target;

	//Single-line things
	int modifyPursuit;
	bool revealMap;
	bool secretSector;
	std::string unlockShip;
	std::string fleet; //Background ships

	//Resources
	Auto_Reward reward;
	Item_Modify items;
	std::string augment;
	std::string drone;
	std::string weapon;
	std::string removeEquip;

	//System
	System_Damage damage;
	System_Status status;

	//Crew
	Crew_Boarder boarders;
	Crew_Member crew;

	//Ship
	std::string shipID;
	bool hostile;

    std::string questID;
	bool returnEvent; //Ending the event early with <event/>

	Linked_List<std::string> *p_choices;
};

Event::Event(std::string ID, Event *p_next):
Node<bool>(ID, p_next, nullptr),
//Unique{0},
textType{-1},
textID{""},

distress{0},
repair{0},
store{0},
environment{""},
target{""},

modifyPursuit{0},
revealMap{0},
secretSector{0},
unlockShip{""},
fleet{""},

augment{""},
drone{""},
weapon{""},
removeEquip{""},

shipID{""},
hostile{0},

questID{""},
returnEvent{0},
p_choices{new Linked_List<std::string>}
{
}

Event::~Event()
{
    delete p_choices;
    p_choices = nullptr;
}

void Event::printSelf(){

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
	std::cout << "New weapon: " << weapon<< std::endl;
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

	for (Choice *p_currentChoice{p_choices->getHead()}; p_currentChoice != nullptr; p_currentChoice = p_currentChoice->getNext())
		std::cout << p_currentChoice->getID << ". " << p_currentChoice->getValue;
}

void Event::replaceValue(){

	std::string command{""};
	int numCom{0};

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input. Warning: changes you have made before cancelling will still exist." << std::endl;

	std::cout << std::endl;

	std::cout << "Unique tag: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	contents = numCom;

	std::cout << "Event text: ";
	std::cin >> textID;

	std::cout << "Map distress: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	distress = numCom;

	std::cout << "Map repair: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	repair = numCom;

	std::cout << "Map store: " << ZERONE;
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
	std::cout << "Reveal sector: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	revealMap = numCom;

	std::cout << "Secret sector: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	secretSector = numCom;

	std::cout << "Unlock ship: " << ZERONE;
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
	std::cout << "Remove equipment: "
	std::cin >> removeEquip;

	damage.replace();
	status.replace();

	//Crew
	boarders.replace();
	crew.replace();

	//Ship
	std::cout << "Ship: "
	std::cin >> shipID;
	std::cout << "Hostile: " << ZERONE;
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	hostile = numCom;

	std::cout << "Quest: ";
	std::cin >> questID;
	std::cout << "Forcibly end event: "
	std::cin >> numCom;

	if (numCom < 0 || numCom > 1)
		return;

	returnEvent = numCom;

	std::cout << std::endl;

	std::cout << "Edit choice list? " << CONFIRM;
	std::cin >> command;

	if (command == "y")
		replaceChoice();

	std::cout << std::endl;
	std::cout << "replaceValue in Event class operation completed." << std::endl;
}

void Event::replaceChoice(){

	std::string command{""};

	while(command != "EXIT"){ //FROM main

		std::cout << "Editing: " << id << std::endl;
		std::cout << "ID's here don't really matter except for determining event order." << std::endl;
		std::cin >> command;

		if (command == "HELP"){

                std::cout << std::endl << "Valid commands are:" << std::endl << std::endl;
                std::cout << "EXIT  - Exits the event's choice editor." << std::endl;
                std::cout << "PRINT - Prints the current list of choices." << std::endl;
                std::cout << "NEW   - Creates a new choice with the specificed name without duplicates." << std::endl;
                std::cout << "ERASE - Deletes the specified choice and its sub-nodes." << std::endl;
                std::cout << std::endl << "WARNING: You will not be able to cancel an operation once it has begun." << std::endl;

		}else if (command == "PRINT")
			p_choices->printList();

		else if (command == "NEW"){

			std::cout << "New ID name: ";
            std::cin >> command;

            if (p_choices->findNode(command) != nullptr)
                std::cout << "An ID with this name already exists." << std::endl;

            else if (!p_choices->emptyList()){

                if (p_choices->createNode(command, "") == 1)
                        std::cout << command << " created successfully." << std::endl;

                else
                    std::cout << "ERROR: Invalid return " << textList.createNode(command, parent) << " on createNode." << std::endl;
            }

		}else if (command == "ERASE"){

			std::cout << "ID to delete: ";
            std::cin >> command;

            if (p_choices->findNode(command) == nullptr)
                std::cout << "Not found." << std::endl;

            else{

                if (p_choices->deleteNode(command))
                    std::cout << command << " successfully deleted." << std::endl;

                else
                    std::cout << "ERROR: Invalid return on deleteNode." << std::endl;
			}
		}
	}

	std::cout << "Replacing ID's with numbers in order..." << std::endl;

	int i{0};
	for (Choice *p_currentChoice{p_choice->getHead()}; p_currentChoice != nullptr; p_currentChoice = p_currentChoice->getNext()){

		i++;
		p_currentChoice->replaceID(std::to_string(i));
	}

	std::cout << "replaceChoice in Event class operation completed." << std::endl;
}

class Choice: public Node<std::string>{ //T value is choice text
public:

    Choice(std::string ID, Choice *p_next);
    ~Choice();

	void printSelf();
	Event *getEvent(); //Gets the direct event

	void replaceValue();
	void replaceEvent();

protected:

	//std::string choice;

	//Tags
	bool hidden; //Result hidden
	bool blue;
	std::string req;
	unsigned int lvl;
	unsigned int maxLvl;
	unsigned int maxGroup;

	//Contents
	int textType; //FROM Event -1 for direct string, 0 for id=, 1 for load=
	std::string textID;

	int eventType; //-1 for direct event, 0 for id=, 1 for load=
	std::string eventID;
    Event *p_event;
};

Choice::Choice(std::string ID, Choice *p_next):
Node<std::string>(ID, p_next, nullptr),
//choice{""},
hidden{0},
blue{0},
req{"None"},
lvl{0},
maxLvl{0},
maxGroup{0},
textType{-1},
textID{""},
eventType{-1},
eventID{""},
p_event{nullptr}
{
}

Choice::~Choice()
{
    delete p_event;
    p_event = nullptr;
}

void Choice::printSelf(){

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

Event *Choice::getEvent(){
	return p_event;
}

void Choice::replaceValue(){

	std::string command{""};

	std::string choice{""};
	std::string result{""};
	int resultType{-1};
	bool hide{0};
	bool bloo{0};
	std::string required{"None"};
	int level{0};
	int maxLevel{0};
	int maxGroups{0};

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input or decline at end." << std::endl;

	std::cout << std::endl;

	std::cout << "Choice text: ";
	std::cin >> choice;
	std::cout << "Results text type " << TYPE;
	std::cin >> resultType;

	if (resultType < -1 || resultType > 1){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "Results text: ";
	std::cin >> result;

	std::cout << "Results hidden " << ZERONE;
	std::cin >> hide;

	if (hide < 0 || hide > 1){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "Blue text " << ZERONE;
	std::cin >> bloo;

	if (bloo < 0 || bloo > 1){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "System required text: ";
	std::cin >> required;
	std::cout << "Minimum level (positive integer): ";
	std::cin >> level;

	if (level < 0){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "Maximum level (positive integer): ";
	std::cin >> maxLevel;

	if (maxLevel < 0){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "Maximum group (positive integer): ";
	std::cin >> maxGroups;

	if (maxGroups < 0){

		std::cout << INVALID << std::endl;
		return;
	}

	std::cout << "Confirm changes? " << CONFIRM;
	std::cin >> command;

	if (command == "y"){

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

	}else
		std::cout << "Operation aborted." << std::endl;

	std::cout << std::endl;

	std::cout << "Edit event ID? " << CONFIRM;
	std::cin >> command;

	if (command == "y")
		replaceEvent();

	std::cout << std::endl;
	std::cout << "replaceValue in Choice class operation completed." << std::endl;
}

void Choice::replaceEvent(){

	std::cout << "Editing: " << id << std::endl;
	std::cout << "To cancel, give invalid input. Otherwise, the event will be erased." << std::endl;

	int command{0};

	std::cout << "Choice event type " << TYPE;
	std::cin >> command;

	if (command < -1 || command > 1){

		std::cout << INVALID << std::endl;
		return;
	}

	eventType = command;
	delete p_event;
    p_event = nullptr;

	if (eventType == -1){
        p_event = new Event();

	}else{

        std::cout << "event ID: ";
        std::cin >> eventID;
	}
	std::cout << "replaceEvent in Choice class operation completed." << std::endl;
}

class Ship: public Node<bool>{ //T value is autoB
public:

    Ship(std::string ID, Event *p_next = nullptr);

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

Ship::Ship(std::string ID, Event *p_next):
Node<bool>(ID, p_next, nullptr),
//autoB{0},
blueprint{""}
{
}

//Global

void loadEvent(Event *p_event){ //!!!!

	int command{1};
    Choice *p_choice{nullptr};

    std::cout << std::endl;

    while (command >= 0){

		while (command == 1){

			p_event->printSelf();

			std::cout << std::endl;
			std::cout << "Enter an integer (0 to edit event and choice list, # to continue to choice, invalid to return to menu): ";
			std::cin >> command;
			std::cout << std::endl;

			if (command == 0)
				p_event->replaceValue();
		}

		p_choice = p_event->p_choices->findNode(std::to_string(command)) //Converts command to string and then searches p_event's
		if (p_choice == nullptr)
			command = -1;

		else
			command == 0;

		while (command == 0){

			p_choice->printSelf();
			std::cout << "Enter an integer (0 to edit choice and event type, 1 to continue to event, invalid to return to menu)" << std::endl;
			std::cout << "Note: If the event is referenced you will be returned to menu. If you want edit the referenced event do it from there." << std::endl;
			std::cin >> command;
			std::cout << std::endl;

			if (command == 0)
				p_choice->replaceValue();

		}

		p_event = p_choice->getEvent;
		if (p_event == nullptr)
			command = -1;
	}
}

int main(){

    Linked_List<std::string> textList; //TODO: Make this a pointer?
    Node<std::string> *p_current{nullptr}; //Keep for load functions
    bool exit{0};
    std::string command{""};
    std::string parent{""};
    //std::string findID{""};

    std::cout << "FTL Event Simulator v" << PROGRAM_VERSION << std::endl;

    do{

        command = "";
        parent = "";
        p_current = nullptr;

        std::cout << std::endl << "Waiting for user command: ";
        std::cin >> command;

        if (command == "EXIT") //FROM replaceChoice
            exit = 1;

        else{

            if (command == "HELP"){

                std::cout << std::endl << "Valid commands are:" << std::endl << std::endl;
                std::cout << "EXIT   - Exits the program." << std::endl;
                std::cout << "PRINT  - Prints the current list of nodes." << std::endl;
                std::cout << "FIND   - Searches for the node specificed and prints its contents." << std::endl;
                std::cout << "CREATE - Creates a new node with the specificed name without duplicates." << std::endl;
                std::cout << "EDIT   - Replaces the contents of the node with the specified input." << std::endl;
                std::cout << "DELETE - Deletes the specified node and its sub-nodes." << std::endl;
				//std::cout << "IMPORT - Imports an XML file into the program." << std::endl;
				//std::cout << "EXPORT - Exports program contents into an XML file." << std::endl;
                //std::cout << "DESTROY - (Dangerous) Deletes an entire list." << std::endl;
                std::cout << std::endl << "WARNING: You may not be able to cancel an operation once it has begun." << std::endl;

            }else if (command == "PRINT"){

                std::cout << "Printing:" << std::endl << std::endl;
                textList.printList();

            }else if (command == "FIND"){

				std::cout << "Text ID to find: ";
				std::cin >> command;
				p_current = textList.findNode(command);

				if (p_current == nullptr)
					std::cout << "Not found." << std::endl;

				else
					loadEvent(p_current);

            }else if (command == "CREATE"){

                std::cout << "New ID name: ";
                std::cin >> command;

                if (textList.findNode(command) != nullptr)
                    std::cout << "An ID with this name already exists." << std::endl;

                else{

                    if (!textList.emptyList()){

                        std::cout << "Under parent (if you don't want under parent, type an invalid ID: ";
                        std::cin >> parent;
                    }

                    if (textList.findNode(parent) == nullptr)
                        parent = "";

                    if (textList.createNode(command, parent) == 1){

                        std::cout << command << " created successfully";

                        if (parent != "")
                            std::cout << " under " << parent;

                        std::cout << "." << std::endl;

                    }else
                        std::cout << "ERROR: Invalid return " << textList.createNode(command, parent) << " on createNode." << std::endl;
                }

            }else if (command == "EDIT"){

                std::cout << "Text ID to modify: ";
                std::cin >> command;
                p_current = textList.findNode(command);

                if (p_current == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    std::cout << "Contents of text ID replacement text: ";
                    std::cin >> command;
                    textList.modifyNode(p_current, command);
                    p_current = nullptr;
                    std::cout << command << " replaced successfully." << std::endl;
                }

            }else if (command == "DELETE"){

                std::cout << "Text ID to delete: ";
                std::cin >> command;

                if (textList.findNode(command) == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    if (textList.deleteNode(command))
                        std::cout << command << " successfully deleted." << std::endl;

                    else
                        std::cout << "ERROR: Invalid return on deleteNode." << std::endl;
                }

            }else
                std::cout << "Invalid command, type HELP for help." << std::endl;
        }

    }while(!exit);

    std::cout << "Ending program." << std::endl;

    //TEST
    //command = "BBBB";
    //findID = "Hello";
    //std::cout << findID.compare(command);

    return 0;
}
