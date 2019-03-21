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

/*
//Program Conventions
//
//TODO: Things that will need to be modified later
//FROM: Matches code from other sections
//TEST: std::cout << "TEST#" << std::endl; for testing
//
//One line separations between categories. Exceptions: One liners, bracket-only lines
//Classes: Constructor/destructor, read functions, write functions
//
//Program Notes
//
//CURRENT: Linked_List supporting Node lists, starting findNode->create and deleteNode functions
//TODO: Event class and other FTL-specific lists
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define PROGRAM_VERSION "0.0.6" //FROM Version
#define MAX_NUM_CHOICES 12

template <typename T>
class Node;
template <typename T>
class Linked_List;
int main();

//TODO

typedef struct Choice{

    std::string choiceText;
    std::string choiceID;
};

class Event: public Node{
public:

    Event(std::string ID);
    ~Event();

private:

    std::string shipID;
    choice choices[10];
}; //TODO

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
Node<T>::Node(std::string ID, Node<T> *p_next, Node<T> *p_head){

    id{ID};
    p_nextNode{p_next};
    p_listHead{p_head};
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
void Node<T>::replaceNext(Node<T> *p_head){
    p_headList = p_head;
}

template <typename T>
class Linked_List{
public:

    Linked_List(); //Constructor
    ~Linked_List(); //Destructor

    bool emptyList(); //Checks if list is empty
    void printList(); //Prints all list ID's (by all, we mean ALL)
    Node<T> *findNode(std::string findID); //Finds the node matching ID
    void printNode(Node<T> *p_next); //Prints value of a node, and subnode ID's

    int createNode(std::string createID); //Creates a new node with corresponding id
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
        
        for(Node<T> *p_subNode{p_currentNode->getHead(); p_subNode != nullptr; p_subNode = p_subNode->getNext()){
            
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
        Node<T> *p_subNode{p_currentNode->getHead};
        //int unMatch{1};

        while(p_currentNode != nullptr){
            
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
    
        /* do{ //Start with list head then increment through matches or passes match point FROM: createNode, deleteNode

            unMatch = findID.compare(p_currentNode->getID());

            if (unMatch) //Skips increment if it matches
                p_currentNode = p_currentNode->getNext();

        }while(p_currentNode != nullptr && unMatch == 1);

        if (!unMatch)
            return p_currentNode; */
    }

    return nullptr;
}

template <typename T>
void Linked_List<T>::printNode(Node<T> *p_next){

    std::cout << p_next->getID() << std::endl;
    std::cout << p_next->getValue() << std::endl;
    
    if (p_currentNode->getHead() != nullptr) //FROM: printList
            std::cout << "Sublist: ";
        
    for(Node<T> *p_subNode{p_currentNode->getHead(); p_subNode != nullptr; p_subNode = p_subNode->getNext()){
            
        std::cout << p_subNode->getID() << " ";
        if (p_subNode == nullptr)
            std::cout << std::endl;
    }
}

template <typename T>
int Linked_List<T>::createNode(std::string createID){

    if (emptyList()){

        p_listHead = new Node<T>(createID, nullptr);
        return 1;
    }
    else{

        Node<T> *p_currentNode{p_listHead};
        Node<T> *p_previousNode{nullptr};
        int unMatch{1};

        do{ //Start with list head then increment through matches or passes match point FROM: findNode

            unMatch = createID.compare(p_currentNode->getID());

            if (unMatch == 1){

                p_previousNode = p_currentNode;
                p_currentNode = p_currentNode->getNext();
            }
        }while(p_currentNode != nullptr && unMatch == 1);

        if (!unMatch)
            return 0;

        if (p_previousNode == nullptr)
            p_listHead = new Node<T>(createID, p_currentNode);

        else
            p_previousNode->replaceNext(new Node<T>(createID, p_currentNode));

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
        Node<T> *p_previousNode{nullptr};
        int unMatch{1};

        do{ //Start with list head then increment through matches or passes match point FROM: findText

            unMatch = deleteID.compare(p_currentNode->getID());

            if (unMatch == 1){

                p_previousNode = p_currentNode;
                p_currentNode = p_currentNode->getNext();
            }
        }while(p_currentNode != nullptr && unMatch == 1);

        if (!unMatch){

            if (p_previousNode != nullptr)
                p_previousNode->replaceNext(p_currentNode->getNext()); //Update previous node's next

            delete p_currentNode;
            return 1;

        }else
            return 0;
    }
}

/* TODO:
class event{
public:
    printEvent(text eventText, event* choices); //Print out all of the event and choice text
    makeChoice(event* choices); //Proceeds to the next event
private:
    text eventChoice; //ID of the event choice text
    text eventTextID; //ID of the event text
    //event choices[MAX_NUM_CHOICES]; //Array of possible choice ID's for this event
    event* p_next; //Points to next event in alphabetical order
};
*/
int main(){

    Linked_List<std::string> textList; //TODO: Make this a pointer?
    Node<std::string> *p_current{nullptr}; //TODO: Get rid of p_current somehow
    bool exit{0};
    std::string command{""};
    //std::string findID{""};

    std::cout << "FTL Event Simulator v" << PROGRAM_VERSION << std::endl;

    do{

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
                std::cout << "DELETE - Deletes the specified node." << std::endl;
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

                    textList.createNode(command);
                    std::cout << command << " created successfully." << std::endl;
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
                        std::cout << "ERROR: deleteNode function in scope Linked_List." << std::endl;
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
