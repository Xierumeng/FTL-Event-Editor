/*
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.1.0 //FROM PROGRAM_VERSION
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

#define PROGRAM_VERSION "0.1.0" //FROM Version
#define MAX_CREW_PROP 4 //Crew types
#define ZERONE "(0 for no, 1 for yes): " //Event, Choice
#define TYPE "(-1 for direct string, 0 for id=, 1 for load=): " //Reference or direct
#define CONFIRM "y for yes, otherwise no: " //y confirmation
#define INVALID "Invalid input, operation aborted."
#deinfe NOABORT "(WARNING: You cannot abort this operation once it has begun)" //Cannot abort action once started


class Choice;
class Event;

template <typename T>
class Node;
template <typename T>
class Linked_List;
int main();

//Data containers
class Auto_Reward{
public:

    Auto_Reward();

	std::string level;
	std::string rewardType;
};

Auto_Reward::Auto_Reward():
level{""},
rewardType{""}
{
}

class Item_Modify{ //TODO: Implement steal
public:

    Item_Modify();

	int scrap[2]; //min, max
	int fuel[2];
	int missiles[2];
	int drones[2];
};

Item_Modify::Item_Modify(){

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
id{""},
proportion{0}
{
}

class Surrender_Escape{
public:

    Surrender_Escape();

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

class Choice: public Node{ //T value is choice text
public:

    Choice(); //TODO
    ~Choice();
	
	void printSelf(); //TODO
	Event *getEvent(); //Gets the direct event
	
	void replaceValue();
	void replaceEvent();
	
private:

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

Choice::Choice(
std::string ID,
Choice *p_next,
):

Node(ID, p_next, nullptr):
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
	std::cout << "Minimum level (positive integer): "
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
	std::cin command;
	
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
		std::cout << "Operation aborted." std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Edit event ID? " << NOABORT << " " << CONFIRM;
	std::cin >> command;
	
	if (command == "y")
		replaceEvent();
	
	std::cout << std::endl;
	std::cout << "replaceValue in Choice class operation completed." << std::endl;
}

void Choice::replaceEvent(){
	
	std::cout << "
	
}

class Event{
public:

	Event();
	~Event();

	bool Unique;

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

    Linked_List<Choice> *p_choices;

	bool returnEvent; //Ending the event early with <event/>
};

Event::Event():
Unique{0},
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

p_choices{nullptr},
returnEvent{0}
{
}

Event::~Event()
{
    delete p_choices;
    p_choices = nullptr;
}

class Ship{
public:

    Ship();
    ~Ship();
	
protected:

	bool autoB; //auto_blueprint?
	std::string blueprint;

	//Surrender_Escape ; TODO

	Event destroyed;
	Event deadCrew;
	Event surrender;
	Event escape;
	Event gotaway;

	Crew_Member crew[MAX_CREW_PROP];
};

Ship::Ship():
autoB{0},
blueprint{""}
{
}

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

    virtual void replaceValue(T newValue); //Replaces contents
    void replaceNext(Node<T> *p_next); //Updates pointer to next node
    void replaceHead(Node<T> *p_head); //Updates pointer to list head

private:

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

        std::cout << std::endl << "Waiting for user command: ";
        std::cin >> command;

        if (command == "EXIT")
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
                std::cout << std::endl << "WARNING: You will not be able to cancel an operation once it has begun." << std::endl;

            }else if (command == "PRINT"){

                std::cout << "Printing:" << std::endl << std::endl;
                textList.printList();

            }else if (command == "FIND"){

                std::cout << "Text ID to find: ";
                std::cin >> command;
                p_current = textList.findNode(command);

                if (p_current == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    std::cout << std::endl;
                    textList.printNode(p_current); //Finds the node, then prints its ID and contents
                    p_current = nullptr;
                }

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
