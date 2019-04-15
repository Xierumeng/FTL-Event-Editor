#pragma once
#include "Node.h"
#include "Choice.h"
#include <iostream>

//template <typename T>
class Node;
class Linked_List {
public:

	Linked_List(); //Constructor
	~Linked_List(); //Destructor

	Node* getHead();
	bool emptyList(); //Checks if list is empty
	void printList(); //Prints all list ID's (by all, we mean ALL)
	Node* findNode(std::string findID); //Finds the node matching ID
	Node* findLinearNode(std::string findID); //Find the node in a single list
	void printNode(Node* p_next); //Prints value of a node, and subnode ID's

	int createNode(std::string createID, std::string parentID); //Creates a new node with corresponding id
	void modifyNode(Node* p_currentNode, std::string newValue); //Replaces the contents of the found ID
	int deleteNode(std::string deleteID); //Deletes the node with corresponding id

private:

	Node* p_listHead; //Head of list
};
