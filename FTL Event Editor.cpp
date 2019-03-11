/*
// Name:    FTL Event Editor
// Goal:    To allow users to import, modify, create, text, and export events
// Version: 0.0.1
// FTL ver: 1.6
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
//
//One line separations between categories. Exceptions: One liners, bracket-only lines
//Classes: Constructor/destructor, read functions, write functions
//
//Program Notes
//
//
//Linked list construction successful, TODO: modification, deletion, and destruction
//CURRENT: createText and findText are having problems
//TODO: Linked list AND Text is templated
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define MAX_NUM_CHOICES 12

class Text;
class Linked_List;
int main();

class Text{
public:

    Text(std::string ID, Text *p_next = nullptr);
    ~Text();

    std::string getText(); //Returns the text
    std::string getID(); //Returns the ID
    Text *getNext(); //Returns next text node

    void replaceText(std::string replaceText); //Replaces contents of event text
    void changeNext(Text *p_Next);

private:

    std::string id; //Name of the text
    std::string contents; //Contents of the text
	Text *p_nextText; //Points to next text in alphabetical order
};

Text::Text(std::string ID, Text *p_next){

    id = ID;
    p_nextText = p_next;
}

std::string Text::getText(){
    return contents;
}

std::string Text::getID(){
    return id;
}

Text *Text::getNext(){
    return p_nextText;
}

void Text::replaceText(std::string replaceText){
    contents = replaceText;
}

void Text::changeNext(Text *p_next){
    p_nextText = p_next;
}

class Linked_List{
public:

    Linked_List(); //Constructor
    //TODO: ~Linked_List(); //Destructor

    bool emptyList(); //Checks if list is empty
    void printList(); //Prints the list ID's
    Text *findText(std::string findID); //Finds the node matching ID TODO: Change type, test
    void printText(Text *p_text); //Prints text

    int createText(std::string createID); //Creates a new node with corresponding id

private:

    Text *p_listHead; //Head of list //TODO: Change type
};

Linked_List::Linked_List():
    p_listHead{nullptr}
{
}

bool Linked_List::emptyList(){
    return (p_listHead == nullptr);
}

void Linked_List::printList(){

    std::cout << "p_listHead -> ";

    for(Text *p_currentNode{p_listHead}; p_currentNode != nullptr; p_currentNode = p_currentNode->getNext()){
        //Start with list head then increment through until end of list

        std::cout << "(" << p_currentNode->getID() << ") -> ";
    }

    std::cout << "0" << std::endl;
}

Text *Linked_List::findText(std::string findID){

    if (!emptyList()){

        Text *p_currentNode{p_listHead};
        int unMatch{1};

        do{ //Start with list head then increment through matches or passes match point

            unMatch = findID.compare(p_currentNode->getID());

            if (!unMatch) //Skips increment if it matches
                p_currentNode = p_currentNode->getNext();

        }while(p_currentNode != nullptr && unMatch == 1);

        if (!unMatch)
            return p_currentNode;
    }

    return nullptr;
}

void Linked_List::printText(Text *p_text){

    std::cout << p_text->getID() << std::endl;
    std::cout << p_text->getText() << std::endl;
}

int Linked_List::createText(std::string createID){

    if (emptyList()){

        p_listHead = new Text(createID, nullptr);
        return 1;
    }
    else{

        Text *p_currentNode{p_listHead};
        Text *p_previousNode{nullptr};
        int unMatch{1};

        do{ //Start with list head then increment through matches or passes match point FROM findText

            unMatch = createID.compare(p_currentNode->getID());

            if (unMatch == 1){

                p_previousNode = p_currentNode;
                p_currentNode = p_currentNode->getNext();
            }
        }while(p_currentNode != nullptr && unMatch == 1);

        if (!unMatch)
            return 0;

        if (p_previousNode == nullptr)
            p_listHead = new Text(createID, p_currentNode);

        else
            p_previousNode->changeNext(new Text(createID, p_currentNode));

        return 1;
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

    Linked_List textList;
    bool exit{0};
    std::string command{""};
    std::string findID{""};
    std::cout << "FTL Event Simulator v0.0.1" << std::endl;

    do{

        std::cout << std::endl << "Waiting for user command: ";
        std::cin >> command;

        if (command == "EXIT")
            exit = 1;

        else{

            if (command == "PRINT"){

                std::cout << "Printing:" << std::endl;
                textList.printList();
                std::cout << std::endl;

            }else if (command == "FIND"){

                std::cout << "Text ID to find: ";
                std::cin >> command;
                if (textList.findText(command) == nullptr)
                    std::cout << "Not found." << std::endl;

                else
                    textList.printText(textList.findText(command)); //Finds the text, then prints it

            }else if (command == "CREATE"){

                std::cout << "New ID name: ";
                std::cin >> command;

                if (textList.createText(command))
                    std::cout << "There is already an ID with this name." << std::endl;

                else
                    textList.createText(command);

            }else
                std::cout << "Invalid command." << std::endl;
        }

    }while(!exit);

    //TEST
    //command = "BBBB";
    //findID = "Hello";
    //std::cout << findID.compare(command);

    return 0;
}
