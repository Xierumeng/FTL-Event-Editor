/*
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, test, and export events
// Version: 0.0.6 //FROM PROGRAM_VERSION
// For FTL: 1.6? The latest, anyway
// Plan:    Adding own, simulating. Later: Import, export.
// Author:  Xierumeng
// Contact: xierumeng <at] hotmail (dot} com
// License: Copyright © 2019
// Notes:   For FTL Faster-than-Light. Use at your own risk; no liability is held to the author of this program.
*/

//Program Conventions
//
//TODO: Things that will need to be modified later
//!!!!: Urgency
//FROM: Matches code(-ish) from other sections
//TEST: For testing
//
//id  : Internal identification
//ID  : External identification
//
//One line separations between categories. Exceptions: One liners, bracket-only lines
//Classes: Constructor/destructor, read functions, write functions
//
//Program Notes
//
//CURRENT: Subclass crap (Event class, Choice class) headers, Node's privates
//TODO: Add Ship class, other FTL-specific lists

#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define PROGRAM_VERSION "0.0.6" //FROM Version
#define MAX_NUM_CHOICES 12

//class Choice;
//class Event;
template <typename T>
class Node;
template <typename T>
class Linked_List;
int main();

//0.1.0
/*class Choice: public Event{ //TODO: Fix the subclass header definition
public:

	Choice(); //TODO: FIX
	~Choice();

	bool hidden; //Tags TODO: Privatize
	bool blue;
	std::string req;
	unsigned short int lvl;
	unsigned short int maxLvl;
	unsigned short int maxGroup;
	
    std::string eventID;
};

class Event: public Node{ //T value is the unique tag of boolean
public:

    Event(std::string ID); //TODO: FIX
    ~Event();

private:

	std::string textID;
    //std::string shipID;
    std::string choiceID[MAX_NUM_CHOICES]; 
};
*/

template <typename T>
class Node{
public:

    Node(std::string ID, Node<T> *p_next = nullptr, Node<T> *p_head = nullptr);
    ~Node();

    std::string getID(); //Returns the ID
    T getValue(); //Returns the stored value
    Node<T> *getNext(); //Returns next node
    Node<T> *getHead(); //Returns head list

    void replaceValue(T newValue); //Replaces contents
    void replaceNext(Node<T> *p_next); //Updates pointer to next node
    void replaceHead(Node<T> *p_head); //Updates pointer to list head

private:

    std::string id; //Name of the node
    T contents; //Contents of the node
    Node<T> *p_nextNode; //Points to next node in alphabetical order
    Node<T> *p_listHead; //Points to new list of the type

template <typename S>
friend class Linked_List; //TODO: Do we really want Linked_List to be able to touch Node's privates?
};

template <typename T>
Node<T>::Node(std::string ID, Node<T> *p_next, Node<T> *p_head):
id{ID}, //TODO !!!!
p_nextNode{p_next},
p_listHead{p_head}
{
}

template <typename T>
Node<T>::~Node() //FROM ~Linked_List()
{
    Node<T> *p_next{p_listHead};

    while(p_listHead != nullptr){

        p_next = p_listHead->getNext();
        delete p_listHead;
        p_listHead = p_next;
    }
}

template <typename T>
std::string Node<T>::getID(){
    return id;
}

template <typename T>
T Node<T>::getValue(){
    return contents;
}

template <typename T>
Node<T> *Node<T>::getNext(){
    return p_nextNode;
}

template <typename T>
Node<T> *Node<T>::getHead(){
    return p_listHead;
}

template <typename T>
void Node<T>::replaceValue(T newValue){
    contents = newValue;
}

template <typename T>
void Node<T>::replaceNext(Node<T> *p_next){
    p_nextNode = p_next;
}

template <typename T>
void Node<T>::replaceHead(Node<T> *p_head){
    p_listHead = p_head;
}

template <typename T>
class Linked_List{
public:

    Linked_List(); //Constructor
    ~Linked_List(); //Destructor

    bool emptyList(); //Checks if list is empty
    void printList(); //Prints all list ID's (by all, we mean ALL)
    Node<T> *findNode(std::string findID); //Finds the node matching ID
	Node<T> *findLinearNode(std::string findID); //Find the node in a single list
    void printNode(Node<T> *p_next); //Prints value of a node, and subnode ID's

    int createNode(std::string createID, std::string parentID); //Creates a new node with corresponding id
    void modifyNode(Node<T> *p_currentNode, T newValue); //Replaces the contents of the found ID
    int deleteNode(std::string deleteID); //Deletes the node with corresponding id

private:

    Node<T> *p_listHead; //Head of list
};

template <typename T>
Linked_List<T>::Linked_List():
    p_listHead{nullptr}
{
}

template <typename T>
Linked_List<T>::~Linked_List() //FROM ~Node()
{
    Node<T> *p_next{p_listHead};

    while(p_listHead != nullptr){

        p_next = p_listHead->getNext();
        delete p_listHead;
        p_listHead = p_next;
    }
}

template <typename T>
bool Linked_List<T>::emptyList(){
    return (p_listHead == nullptr);
}

template <typename T>
void Linked_List<T>::printList(){

    for(Node<T> *p_currentNode{p_listHead}; p_currentNode != nullptr; p_currentNode = p_currentNode->getNext()){
        //Start with list head then increment through until end of list

        std::cout << p_currentNode->getID() << std::endl;
      if (p_currentNode->getHead() != nullptr) //FROM: printNode
           std::cout << "Sublist: ";

        for(Node<T> *p_subNode{p_currentNode->getHead()}; p_subNode != nullptr; p_subNode = p_subNode->getNext()){

            std::cout << p_subNode->getID() << " ";
            if (p_subNode == nullptr)
                std::cout << std::endl;
        }
    }
}

template <typename T>
Node<T> *Linked_List<T>::findNode(std::string findID){

    if (!emptyList()){

        Node<T> *p_currentNode{p_listHead};
        Node<T> *p_subNode{p_currentNode->getHead()};

        while(p_currentNode != nullptr){ //FROM: deleteNode

            if (!findID.compare(p_currentNode->getID())) //If ID matches
                    return p_currentNode;

            while(p_subNode != nullptr){ //Skips second bit if p_subNode is nullptr

                if (!findID.compare(p_subNode->getID()))
                    return p_subNode;

                p_subNode = p_subNode->getNext();
            }

            p_currentNode = p_currentNode->getNext();
            p_subNode = p_currentNode->getHead();
        }
    }

    return nullptr;
}

template <typename T>
Node<T> *Linked_List<T>::findLinearNode(std::string findID){

    Node<T> *p_currentNode{p_listHead};
    int unMatch{1};

    while(p_currentNode != nullptr && unMatch == 1){ //Start with list head then increment through matches or passes match point FROM: createNode, deleteNode

        unMatch = findID.compare(p_currentNode->getID());

        if (unMatch) //Skips increment if it matches
                p_currentNode = p_currentNode->getNext();
    }

    if (!unMatch)
        return p_currentNode;
}

template <typename T>
void Linked_List<T>::printNode(Node<T> *p_current){

    std::cout << p_current->getID() << std::endl;
    std::cout << p_current->getValue() << std::endl;

    if (p_current->getHead() != nullptr) //FROM: printList
            std::cout << "Sublist: ";

    for(Node<T> *p_subNode{p_current->getHead()}; p_subNode != nullptr; p_subNode = p_subNode->getNext()){

        std::cout << p_subNode->getID() << " ";
        if (p_subNode == nullptr)
            std::cout << std::endl;
    }
}

template <typename T>
int Linked_List<T>::createNode(std::string createID, std::string parentID){
	//List is empty - Just create new node.
	//Otherwise, check for duplicate from createID - return 0 if it does.
	//Can't find parentID - return -1.
	//Inserted successfully - return 1.

    if (emptyList()){

        p_listHead = new Node<T>(createID, nullptr);
        return 1;

	}else if (findNode(createID) != nullptr)
		return 0;

    else{

        Node<T> *p_currentNode{p_listHead};
		Node<T> *p_previousNode{nullptr};
        int unMatch{1};

		if (parentID != ""){ //If the parentID exists, find the parentID node

			while(p_currentNode != nullptr && unMatch == 1){
                //Start with list head then increment through until matches FROM: findLinearNode, slightly lower down

				unMatch = parentID.compare(p_currentNode->getID());

				if (unMatch == 1)
					p_currentNode = p_currentNode->getNext();
			}

			if (unMatch)
				return -1; //Could not find parentID

			p_previousNode = p_currentNode;
			p_currentNode = p_currentNode->getHead();
		}

		unMatch = 1;

        while(p_currentNode != nullptr && unMatch == 1){
            //Start with list head then increment through until matches or passes FROM: findLinearNode, slightly higher up

            unMatch = createID.compare(p_currentNode->getID());

            if (unMatch == 1){

                p_previousNode = p_currentNode;
                p_currentNode = p_currentNode->getNext();
            }
        }

        if (p_previousNode != nullptr){

			if (parentID.compare(p_previousNode->getID())) //If the previous node is the parentID
				p_previousNode->replaceHead(new Node<T>(createID, p_currentNode));

			else
				p_previousNode->replaceNext(new Node<T>(createID, p_currentNode));

		}else
			p_listHead = new Node<T>(createID, p_currentNode);

        return 1;
    }
}

template <typename T>
void Linked_List<T>::modifyNode(Node<T> *p_currentNode, T newValue){
        p_currentNode->replaceValue(newValue);
}

template <typename T>
int Linked_List<T>::deleteNode(std::string deleteID){

    if (emptyList())
        return 0;

    else{

        Node<T> *p_currentNode{p_listHead};
		Node<T> *p_subNode{p_currentNode->getHead()};
        Node<T> *p_previousNode{nullptr};
        int unMatch{1};
		bool subList{0};

        while(p_currentNode != nullptr && unMatch){ //FROM: findNode

			subList = 0;
			unMatch = deleteID.compare(p_currentNode->getID());

			if (unMatch){ //If the ID does not match

				p_subNode = p_currentNode->getHead();
				p_previousNode = p_currentNode;
				unMatch = 1;
				subList = 1;

				while(p_subNode != nullptr && unMatch == 1){
                    //Start with list head then increment through matches or passes match point FROM: findLinearNode, createNode

					unMatch = deleteID.compare(p_subNode->getID());

					if (unMatch){ //Skips increment if it matches
						p_previousNode = p_subNode;
						p_subNode = p_subNode->getNext();

					}
				}
			}

			if (unMatch){
				p_previousNode = p_currentNode;
				p_currentNode = p_currentNode->getNext();

			}
		}

        if (!unMatch){ //TODO: Add shit

            if (p_previousNode != nullptr){

				if (subList)
					p_currentNode = p_subNode;

				if (p_previousNode->getHead() == nullptr)
					p_previousNode->replaceNext(p_currentNode->getNext()); //Update previous node's next

				else
					p_previousNode->replaceHead(p_currentNode->getNext()); //Update previous node's head
			}

            delete p_currentNode;
            return 1;

        }else
            return 0;
    }
}

int main(){

    Linked_List<std::string> textList; //TODO: Make this a pointer?
    Node<std::string> *p_current{nullptr}; //Keep for load functions
    bool exit{0};
    std::string command{""};
    std::string parent{""};
    //std::string findID{""};

    std::cout << "FTL Event Simulator v" << PROGRAM_VERSION << std::endl;

    do{

        command = "";
        parent = "";

        std::cout << std::endl << "Waiting for user command: ";
        std::cin >> command;

        if (command == "EXIT")
            exit = 1;

        else{

            if (command == "HELP"){

                std::cout << std::endl << "Valid commands are:" << std::endl << std::endl;
                std::cout << "EXIT - Exits the program." << std::endl;
                std::cout << "PRINT - Prints the current list of nodes." << std::endl;
                std::cout << "FIND - Searches for the node specificed and prints its contents." << std::endl;
                std::cout << "CREATE - Creates a new node with the specificed name without duplicates." << std::endl;
                std::cout << "EDIT - Replaces the contents of the node with the specified input." << std::endl;
                std::cout << "DELETE - Deletes the specified node and its sub-nodes." << std::endl;
                //std::cout << "DESTROY - (Dangerous) Deletes an entire list." << std::endl;
                std::cout << std::endl << "WARNING: You will not be able to cancel an operation once it has begun." << std::endl;

            }else if (command == "PRINT"){

                std::cout << "Printing:" << std::endl << std::endl;
                textList.printList();

            }else if (command == "FIND"){

                std::cout << "Text ID to find: ";
                std::cin >> command;
                p_current = textList.findNode(command);

                if (p_current == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    std::cout << std::endl;
                    textList.printNode(p_current); //Finds the node, then prints its ID and contents
                    p_current = nullptr;
                }

            }else if (command == "CREATE"){

                std::cout << "New ID name: ";
                std::cin >> command;

                if (textList.findNode(command) != nullptr)
                    std::cout << "An ID with this name already exists." << std::endl;

                else{

                    std::cout << "Under parent? y/Y for yes, otherwise no: ";
                    std::cin >> parent;

                    if (parent == "y" || parent == "Y"){

                        std::cout << "Name of parent node: ";
                        std::cin >> parent;
						if (textList.findNode(parent) != nullptr){
							
							std::cout << "GOOD" << std::endl;
							if (textList.createNode(command, parent) == 1)
								std::cout << command << " created successfully." << std::endl;
							
							else
								std::cout << "ERROR: Invalid return on createNode." << std::endl;
							
						}else
							std::cout << "Parent node not found." << std::endl;

                    }else{
                        
						parent = "";

						std::cout << "BAD" << std::endl;
						if (textList.createNode(command, parent) == 1)
							std::cout << command << " created successfully." << std::endl;

						else
							std::cout << "ERROR: Invalid return on createNode." << std::endl;
					}
                }

            }else if (command == "EDIT"){

                std::cout << "Text ID to modify: ";
                std::cin >> command;
                p_current = textList.findNode(command);

                if (p_current == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    std::cout << "Contents of text ID replacement text: ";
                    std::cin >> command;
                    textList.modifyNode(p_current, command);
                    p_current = nullptr;
                }

            }else if (command == "DELETE"){

                std::cout << "Text ID to delete: ";
                std::cin >> command;

                if (textList.findNode(command) == nullptr)
                    std::cout << "Not found." << std::endl;

                else{

                    if (textList.deleteNode(command))
                        std::cout << command << " successfully deleted." << std::endl;

                    else
                        std::cout << "ERROR: Invalid return on deleteNode." << std::endl;
                }

            }else
                std::cout << "Invalid command, type HELP for help." << std::endl;
        }

    }while(!exit);

    //TEST
    //command = "BBBB";
    //findID = "Hello";
    //std::cout << findID.compare(command);

    return 0;
}
