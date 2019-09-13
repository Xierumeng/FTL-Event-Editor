#pragma once
#include <iostream>
#include <string>

template <typename T>
class Node {
public:

	Node(std::string ID, Node<T>* p_next = nullptr, Node<T>* p_head = nullptr);
	~Node();

	virtual void printSelf(); //Prints the node contents
	std::string getID(); //Returns the ID
	T getValue(); //Returns the stored data
	Node<T>* getNext(); //Returns next node
	Node<T>* getHead(); //Returns head list

	void replaceID(std::string ID); //Replaces ID //NodeHIS SHOULD ONLY BE USED FOR EVENNode CHOICE SORNodeING
	void replaceValue(T newValue); //Replaces data
	void replaceNext(Node<T>* p_next); //Updates pointer to next node
	void replaceHead(Node<T>* p_head); //Updates pointer to list head

protected:

	std::string id; //Name of the node
	T data; //Contents of the node
	Node<T>* p_nextNode; //Points to next node in alphabetical order
	Node<T>* p_listHead; //Points to new list of the type

	//template <typename S>
	//friend class Linked_List; //NodeODO: Do we need this or not?
};