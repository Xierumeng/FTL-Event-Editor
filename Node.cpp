#include "Node.h"

template <typename T>
Node<T>::Node(std::string ID, Node<T>* p_next, Node<T>* p_head) :
	id{ ID },
	p_nextNode{ p_next },
	p_listHead{ p_head }
{
}

template <typename T>
Node<T>::~Node() //FROM ~Linked_List()
{
	Node<T>* p_next{ p_listHead };

	while (p_listHead != nullptr) {

		p_next = p_listHead->getNext();
		delete p_listHead;
		p_listHead = p_next;
	}
}

template <typename T>
void Node<T>::printSelf() {

	std::cout << "Name ID: " << id << std::endl;
	std::cout << "Subnodes:" << std::endl;

	for (Node<T>* p_subNode{ p_listHead }; p_subNode != nullptr; p_subNode = p_subNode->getNext()) {
		std::cout << " ⮡  " << p_subNode->getID() << std::endl;

		//if (p_subNode == nullptr)
		//    std::cout << std::endl;
	}
}

template <typename T>
std::string Node<T>::getID() {
	return id;
}

template <typename T>
T Node<T>::getValue(){
	return data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return p_nextNode;
}

template <typename T>
Node<T>* Node<T>::getHead() {
	return p_listHead;
}

template <typename T>
void Node<T>::replaceID(std::string ID) {
	id = ID;
}

template <typename T>
void Node<T>::replaceValue(T newValue) {
	data = newValue;
}

template <typename T>
void Node<T>::replaceNext(Node<T>* p_next) {
	p_nextNode = p_next;
}

template <typename T>
void Node<T>::replaceHead(Node<T>* p_head) {
	p_listHead = p_head;
}