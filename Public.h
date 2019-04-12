#pragma once
#include <iostream>

class Auto_Reward {
public:

	Auto_Reward();
	void printReward() {
		std::cout << "Reward level: " << level << std::endl;
		std::cout << "Reward type: " << rewardType << std::endl;
	}

	void replace() {
		std::cout << "Reward level: ";
		std::cin >> level;
		std::cout << "Reward type: ";
		std::cin >> rewardType;
	}

	std::string level;
	std::string rewardType;
};

Auto_Reward::Auto_Reward() :
	level{ "" },
	rewardType{ "" }
{
}

class Item_Modify {
public:

	Item_Modify();
	void printItem() {
		std::cout << "Item modification:" << std::endl;
		std::cout << " -Scrap min: " << scrap[0] << std::endl;
		std::cout << " -Scrap max: " << scrap[1] << std::endl;
		std::cout << " -Fuel min: " << fuel[0] << std::endl;
		std::cout << " -Fuel max: " << fuel[1] << std::endl;
		std::cout << " -Missiles min: " << missiles[0] << std::endl;
		std::cout << " -Missiles max: " << missiles[1] << std::endl;
		std::cout << " -Drones min: " << drones[0] << std::endl;
		std::cout << " -Drones max: " << drones[1] << std::endl;
		std::cout << " -Steal: " << steal << std::endl;
	}

	void replace() {
		std::cout << "Scrap min (integer): ";
		std::cin >> scrap[0];
		std::cout << "Scrap max (integer): ";
		std::cin >> scrap[1];
		std::cout << "Fuel min (integer): ";
		std::cin >> fuel[0];
		std::cout << "Fuel max (integer): ";
		std::cin >> fuel[1];
		std::cout << "Missiles min (integer): ";
		std::cin >> missiles[0];
		std::cout << "Missiles max (integer): ";
		std::cin >> missiles[1];
		std::cout << "Drones min (integer): ";
		std::cin >> drones[0];
		std::cout << "Drones max (integer): ";
		std::cin >> drones[1];
		std::cout << "Steal (positive integer): ";
		std::cin >> steal;
	}

	int scrap[2]; //min, max
	int fuel[2];
	int missiles[2];
	int drones[2];
	bool steal;
};

Item_Modify::Item_Modify() :
	steal{ 0 }
{

	for (int i{ 0 }; i < 2; i++) {

		scrap[i] = 0;
		fuel[i] = 0;
		missiles[i] = 0;
		drones[i] = 0;
	}
}

class System_Damage {
public:

	System_Damage();
	void printDamage() {
		std::cout << "Damage amount: " << amount << std::endl;
		std::cout << "Damaged system: " << system << std::endl;
		std::cout << "Damage effect: " << effect << std::endl;
	}

	void replace() {
		std::cout << "Damage amount (integer): ";
		std::cin >> amount;
		std::cout << "Damaged system: ";
		std::cin >> system;
		std::cout << "Damage effect: ";
		std::cin >> effect;
	}

	int amount;
	std::string system;
	std::string effect;
};

System_Damage::System_Damage() :
	amount{ 0 },
	system{ "" },
	effect{ "" }
{
}

class System_Status {
public:

	System_Status();
	void printStatus() {
		std::cout << "Status type: " << type << std::endl;
		std::cout << "Status target ship: " << target << std::endl;
		std::cout << "Status system: " << system << std::endl;
		std::cout << "Status amount: " << amount << std::endl;
	}

	void replace() {
		std::cout << "Status type: ";
		std::cin >> type;
		std::cout << "Status target ship: ";
		std::cin >> target;
		std::cout << "Status system: ";
		std::cin >> system;
		std::cout << "Status amount: ";
		std::cin >> amount;
	}

	std::string type;
	std::string target;
	std::string system;
	unsigned int amount;
};

System_Status::System_Status() :
	type{ "" },
	target{ "" },
	system{ "" },
	amount{ 0 }
{
}

class Crew_Boarder {
public:

	Crew_Boarder();
	void printBoarder() {
		std::cout << "Boarder race: " << classRace << std::endl;
		std::cout << "Minimum: " << num[0] << std::endl;
		std::cout << "Maximum: " << num[1] << std::endl;
		std::cout << "Boarder breach: " << breach << std::endl;
	}

	void replace() {
		std::cout << "Boarder race: ";
		std::cin >> classRace;
		std::cout << "Minimum (positive integer): ";
		std::cin >> num[0];
		std::cout << "Maximum (positive integer): ";
		std::cin >> num[1];
		std::cout << "Boarder breach (positive integer): ";
		std::cin >> breach;
	}

	std::string classRace;
	unsigned int num[2]; //Max must be below 9
	bool breach;
};

Crew_Boarder::Crew_Boarder() :
	classRace{ "" },
	breach{ 0 }
{
	for (int i{ 0 }; i < 2; i++)
		num[i] = 0;
}

class Crew_Member {
public:

	Crew_Member();
	void printCrew() {
		std::cout << "Crew number: " << amount << std::endl;
		std::cout << "Crew skill: " << skill << std::endl;
		std::cout << "Crew skill level: " << level << std::endl;
		std::cout << "Crew name ID: " << id << std::endl;
	}

	void replace() {
		std::cout << "Crew number (integer): ";
		std::cin >> amount;
		std::cout << "Crew skill: ";
		std::cin >> skill;
		std::cout << "Crew skill level (positive integer): ";
		std::cin >> level;
		std::cout << "Crew name ID: ";
		std::cin >> id;
	}

	void printProp() {
		std::cout << "Crew proportion: " << proportion << std::endl;
	}

	void replaceProp() {
		std::cout << "Crew proportion (number): ";
		std::cin >> proportion;
	}

	int amount;
	std::string skill; //all_skills, pilot, etc.
	unsigned int level; //1 or 2
	std::string classRace;
	std::string id; //Force name

	double proportion; //For Ship class crew proportion
};

Crew_Member::Crew_Member() :
	amount{ 0 },
	skill{ "" },
	level{ 0 },
	classRace{ "" },
	id{ "None" },
	proportion{ 0 }
{
}

class Surrender_Escape {
public:

	Surrender_Escape();
	void print() {
		std::cout << "Enemy Chance: " << chance << std::endl;
		std::cout << "Enemy Timer: " << timer << std::endl;
		std::cout << "Minimum: " << num[0] << std::endl;
		std::cout << "Maximum: " << num[1] << std::endl;
	}

	void replace() {
		std::cout << "Enemy Chance (number): ";
		std::cin >> chance;
		std::cout << "Enemy Timer (integer): ";
		std::cin >> timer;
		std::cout << "Minimum (integer): ";
		std::cin >> num[0];
		std::cout << "Maximum (integer): ";
		std::cin >> num[1];
	}

	double chance;
	int timer;
	int num[2];
};

Surrender_Escape::Surrender_Escape() :
	chance{ 0 },
	timer{ 0 }
{
	for (int i{ 0 }; i < 2; i++)
		num[i] = 0;
}