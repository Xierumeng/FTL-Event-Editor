#pragma once
#include "Node.h"
#include "Event.h"
#include "Linked_List.h"
#include <iostream>
#include <string>

class Event;
class Choice : public Node<Choice> { //T value is choice string
public:

	Choice(std::string ID, Choice* p_next);
	~Choice();

	void printSelf();
	Event* getEvent(); //Gets the direct event

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
	Event* p_event;
};