#include "Node.h"
#include <iostream>

//template <typename T>
Node::Node(std::string ID, Node* p_next, Node* p_head) :
	id{ ID },
	p_nextNode{ p_next },
	p_listHead{ p_head }
{
}

//template <typename T>
Node::~Node() //FROM ~Linked_List()
{
	Node* p_next{ p_listHead };

	while (p_listHead != nullptr) {

		p_next = p_listHead->getNext();
		delete p_listHead;
		p_listHead = p_next;
	}
}

//template <typename T>
void Node::printSelf() {

	std::cout << "Name ID: " << id << std::endl;
	std::cout << "Contents: " << contents << std::endl;
	std::cout << "Subnodes:" << std::endl;

	for (Node* p_subNode{ p_listHead }; p_subNode != nullptr; p_subNode = p_subNode->getNext()) {
		std::cout << " - " << p_subNode->getID() << std::endl;

		//if (p_subNode == nullptr)
		//    std::cout << std::endl;
	}

}

//template <typename T>
std::string Node::getID() {
	return id;
}

//template <typename T>
std::string Node::getValue(){
	return contents;
}

//template <typename T>
Node* Node::getNext() {
	return p_nextNode;
}

//template <typename T>
Node* Node::getHead() {
	return p_listHead;
}

//template <typename T>
void Node::replaceID(std::string ID) {
	id = ID;
}

//template <typename T>
void Node::replaceValue(std::string newValue) {
	contents = newValue;
}

//template <typename T>
void Node::replaceNext(Node* p_next) {
	p_nextNode = p_next;
}

//template <typename T>
void Node::replaceHead(Node* p_head) {
	p_listHead = p_head;
}