#pragma once
#include "Node.h"
#include "Choice.h"
#include <iostream>

//class Node;
template <typename T>
class Linked_List {
public:

	Linked_List(); //Constructor
	~Linked_List(); //Destructor

	Node<T>* getHead();
	bool emptyList(); //Checks if list is empty
	void printList(); //Prints all list ID's (by all, we mean ALL)
	Node<T>* findNode(std::string findID); //Finds the node matching ID
	Node<T>* findLinearNode(std::string findID); //Find the node in a single list
	void printNode(Node<T>* p_next); //Prints value of a node, and subnode ID's

	int createNode(std::string createID, std::string parentID); //Creates a new node with corresponding id
	void modifyNode(Node<T>* p_currentNode, std::string newValue); //Replaces the contents of the found ID
	int deleteNode(std::string deleteID); //Deletes the node with corresponding id

private:

	Node<T>* p_listHead; //Head of list
};