#pragma once
#include "Node.h"
#include "Choice.h"
#include "Public.h"
#include <string>

class Event : public Node { //T value is tag unique boolean
public:

	Event(std::string ID, Event* p_next);
	~Event();

	void printSelf();
	Linked_List* getChoiceList();

	void replaceValue();
	void replaceChoice();

protected:

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
	bool returnEvent; //Ending the event early with <event/>

	Linked_List* p_choices;
};