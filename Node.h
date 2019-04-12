#pragma once
#include <string>

//template <typename T>
class Node {
public:

	Node(std::string ID, Node* p_next = nullptr, Node* p_head = nullptr);
	~Node();

	virtual void printSelf(); //Prints the node contents
	std::string getID(); //Returns the ID
	std::string getValue(); //Returns the stored value
	Node* getNext(); //Returns next node
	Node* getHead(); //Returns head list

	void replaceID(std::string ID); //Replaces ID //THIS SHOULD ONLY BE USED FOR EVENT CHOICE SORTING
	virtual void replaceValue(std::string newValue); //Replaces contents
	void replaceNext(Node* p_next); //Updates pointer to next node
	void replaceHead(Node* p_head); //Updates pointer to list head

protected:

	std::string id; //Name of the node
	std::string contents; //Contents of the node
	Node* p_nextNode; //Points to next node in alphabetical order
	Node* p_listHead; //Points to new list of the type

	//template <typename S>
	//friend class Linked_List; //TODO: Do we need this or not?
};