#include "Linked_List.h"

template <typename T>
Linked_List<T>::Linked_List() :
	p_listHead{ nullptr }
{
}

template <typename T>
Linked_List<T>::~Linked_List() //FROM ~Node()
{
	Node<T>* p_next{ p_listHead };

	while (p_listHead != nullptr) {

		p_next = p_listHead->getNext();
		delete p_listHead;
		p_listHead = p_next;
	}
}

template <typename T>
Node<T>* Linked_List<T>::getHead() {
	return p_listHead;
}

template <typename T>
bool Linked_List<T>::emptyList() {
	return (p_listHead == nullptr);
}

template <typename T>
void Linked_List<T>::printList() {

	for (Node<T>* p_currentNode{ p_listHead }; p_currentNode != nullptr; p_currentNode = p_currentNode->getNext()) {
		//Start with list head then increment through until end of list

		std::cout << p_currentNode->getID() << std::endl;
		//if (p_currentNode->getHead() != nullptr) //FROM: printNode
		//   std::cout << "    Sublist: ";

		for (Node<T>* p_subNode{ p_currentNode->getHead() }; p_subNode != nullptr; p_subNode = p_subNode->getNext()) {

			std::cout << " - " << p_subNode->getID() << std::endl;
			//if (p_subNode == nullptr)
			//    std::cout << std::endl;
		}
	}
}

template <typename T>
Node<T>* Linked_List<T>::findNode(std::string findID) {

	if (!emptyList()) {

		Node<T>* p_currentNode{ p_listHead };
		Node<T>* p_subNode{ p_currentNode->getHead() };

		while (p_currentNode != nullptr) { //FROM: deleteNode

			p_subNode = p_currentNode->getHead();

			if (!findID.compare(p_currentNode->getID())) //If ID matches
				return p_currentNode;

			while (p_subNode != nullptr) { //Skips second bit if p_subNode is nullptr

				if (!findID.compare(p_subNode->getID()))
					return p_subNode;

				p_subNode = p_subNode->getNext();
			}

			p_currentNode = p_currentNode->getNext();
		}
	}

	return nullptr;
}

template <typename T>
Node<T>* Linked_List<T>::findLinearNode(std::string findID) {

	Node<T>* p_currentNode{ p_listHead };
	int unMatch{ 1 };

	while (p_currentNode != nullptr && unMatch > 0) {
		//Start with list head then increment through matches or passes match point FROM: createNode, deleteNode

		unMatch = findID.compare(p_currentNode->getID());

		if (unMatch) //Skips increment if it matches
			p_currentNode = p_currentNode->getNext();
	}

	if (!unMatch)
		return p_currentNode;

	else
		return nullptr;
}

template <typename T>
void Linked_List<T>::printNode(Node<T>* p_current) {
	p_current->printSelf();
}

template <typename T>
int Linked_List<T>::createNode(std::string createID, std::string parentID) {
	//List is empty - Just create new node.
	//Otherwise, check for duplicate from createID - return 0 if it does.
	//Can't find parentID - return -1.
	//Inserted successfully - return 1.

	if (emptyList()) {

		p_listHead = new Node(createID, nullptr);
		return 1;

	}
	else if (findNode(createID) != nullptr)
		return 0;

	else {

		Node<T>* p_currentNode{ p_listHead };
		Node<T>* p_previousNode{ nullptr };
		int unMatch{ 1 };

		if (parentID != "") { //If the parentID exists, find the parentID node

			while (p_currentNode != nullptr && unMatch > 0) {
				//Start with list head then increment through until matches FROM: findLinearNode, slightly lower down

				unMatch = parentID.compare(p_currentNode->getID());

				if (unMatch > 0)
					p_currentNode = p_currentNode->getNext();
			}

			if (unMatch)
				return -1; //Could not find parentID

			p_previousNode = p_currentNode;
			p_currentNode = p_currentNode->getHead();
		}

		unMatch = 1;

		while (p_currentNode != nullptr && unMatch > 0) {
			//Start with list head then increment through until matches or passes FROM: findLinearNode, slightly higher up

			unMatch = createID.compare(p_currentNode->getID());

			if (unMatch > 0) {

				p_previousNode = p_currentNode;
				p_currentNode = p_currentNode->getNext();
			}
		}

		if (p_previousNode != nullptr) {

			if (!parentID.compare(p_previousNode->getID())) //If the previous node is the parentID
				p_previousNode->replaceHead(new Node(createID, p_currentNode));

			else
				p_previousNode->replaceNext(new Node(createID, p_currentNode));

		}
		else
			p_listHead = new Node(createID, p_currentNode);

		return 1;
	}
}

template <typename T>
void Linked_List<T>::modifyNode(Node<T>* p_currentNode, std::string newValue) {
	p_currentNode->replaceValue(newValue);
}

template <typename T>
int Linked_List<T>::deleteNode(std::string deleteID) {

	if (emptyList())
		return 0;

	else {

		Node<T>* p_currentNode{ p_listHead };
		Node<T>* p_subNode{ p_currentNode->getHead() };
		Node<T>* p_previousNode{ nullptr };
		int unMatch{ 1 };
		bool subList{ 0 };

		while (p_currentNode != nullptr && unMatch) { //FROM: findNode

			subList = 0;
			unMatch = deleteID.compare(p_currentNode->getID());

			if (unMatch) { //If the ID does not match

				p_subNode = p_currentNode->getHead();
				p_previousNode = p_currentNode;
				unMatch = 1;
				subList = 1;

				while (p_subNode != nullptr && unMatch > 0) {
					//Start with list head then increment through matches or passes match point FROM: findLinearNode, createNode

					unMatch = deleteID.compare(p_subNode->getID());

					if (unMatch) { //Skips increment if it matches
						p_previousNode = p_subNode;
						p_subNode = p_subNode->getNext();

					}
				}
			}

			if (unMatch) {
				p_previousNode = p_currentNode;
				p_currentNode = p_currentNode->getNext();

			}
		}

		if (!unMatch) {

			if (p_previousNode != nullptr) { //Checks for the start of the list

				if (subList)
					p_currentNode = p_subNode;

				if (p_previousNode->getHead() != p_currentNode)
					p_previousNode->replaceNext(p_currentNode->getNext()); //Update previous node's next

				else
					p_previousNode->replaceHead(p_currentNode->getNext()); //Update previous node's head

			}
			else
				p_listHead = p_currentNode->getNext();

			delete p_currentNode;
			return 1;

		}
		else
			return 0;
	}
}