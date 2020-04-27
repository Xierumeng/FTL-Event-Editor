#pragma once
#include "tinyxml2.h"

#include "Event.h"
#include "Choice.h"

bool eventNameCheck(tinyxml2::XMLElement* p_XMLEvent);
Event eventBuilder(tinyxml2::XMLElement* p_XMLEvent);
void eventDataBuilder(std::shared_ptr<EventData> currentEventData, tinyxml2::XMLElement* p_XMLEvent);
Choice choiceBuilder(tinyxml2::XMLElement* p_XMLChoice);
Text textBuilder(tinyxml2::XMLElement* p_XMLText);
AttributeType getAttributeTypeFromXMLElement(tinyxml2::XMLElement* p_XMLElement);