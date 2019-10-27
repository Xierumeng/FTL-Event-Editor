#pragma once
#include <iostream>

class Auto_Reward {
public:

	Auto_Reward();
	void printReward();
	void replace();

	std::string level;
	std::string rewardType;
};

class Item_Modify {
public:

	Item_Modify();
	void printItem();
	void replace();

	int scrap[2]; //min, max
	int fuel[2];
	int missiles[2];
	int drones[2];
	bool steal;
};

class System_Damage {
public:

	System_Damage();
	void printDamage();
	void replace();

	int amount;
	std::string system;
	std::string effect;
};

class System_Status {
public:

	System_Status();
	void printStatus();
	void replace();

	std::string type;
	std::string target;
	std::string system;
	unsigned int amount;
};

class Crew_Boarder {
public:

	Crew_Boarder();
	void printBoarder();
	void replace();

	std::string classRace;
	unsigned int num[2]; //Max must be below 9
	bool breach;
};

class Crew_Member {
public:

	Crew_Member();
	void printCrew();
	void replace();
	void printProp();
	void replaceProp();

	int amount;
	std::string skill; //all_skills, pilot, etc.
	unsigned int level; //1 or 2
	std::string classRace;
	std::string id; //Force name

	double proportion; //For Ship class crew proportion
};

class Surrender_Escape {
public:

	Surrender_Escape();
	void print();
	void replace();

	double chance;
	int timer;
	int num[2];
};