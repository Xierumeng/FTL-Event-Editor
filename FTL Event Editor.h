#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Linked_List.h"
#include "Node.h"
#include "Event.h"

void textMenu(Linked_List<std::string>* textList);
void eventMenu(Linked_List<Event>* eventList);
void findEvent(Event* p_event) { //!!!!