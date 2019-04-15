#include "Public.h"

Auto_Reward::Auto_Reward() :
	level{ "" },
	rewardType{ "" }
{
}

void Auto_Reward::printReward() {
	std::cout << "Reward level: " << level << std::endl;
	std::cout << "Reward type: " << rewardType << std::endl;
}

void Auto_Reward::replace() {
	std::cout << "Reward level: ";
	std::cin >> level;
	std::cout << "Reward type: ";
	std::cin >> rewardType;
}

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

void Item_Modify::printItem() {
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

void Item_Modify::replace() {
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

System_Damage::System_Damage() :
	amount{ 0 },
	system{ "" },
	effect{ "" }
{
}

void System_Damage::printDamage() {
	std::cout << "Damage amount: " << amount << std::endl;
	std::cout << "Damaged system: " << system << std::endl;
	std::cout << "Damage effect: " << effect << std::endl;
}

void System_Damage::replace() {
	std::cout << "Damage amount (integer): ";
	std::cin >> amount;
	std::cout << "Damaged system: ";
	std::cin >> system;
	std::cout << "Damage effect: ";
	std::cin >> effect;
}

System_Status::System_Status() :
	type{ "" },
	target{ "" },
	system{ "" },
	amount{ 0 }
{
}

void System_Status::printStatus() {
	std::cout << "Status type: " << type << std::endl;
	std::cout << "Status target ship: " << target << std::endl;
	std::cout << "Status system: " << system << std::endl;
	std::cout << "Status amount: " << amount << std::endl;
}

void System_Status::replace() {
	std::cout << "Status type: ";
	std::cin >> type;
	std::cout << "Status target ship: ";
	std::cin >> target;
	std::cout << "Status system: ";
	std::cin >> system;
	std::cout << "Status amount: ";
	std::cin >> amount;
}

Crew_Boarder::Crew_Boarder() :
	classRace{ "" },
	breach{ 0 }
{
	for (int i{ 0 }; i < 2; i++)
		num[i] = 0;
}

void Crew_Boarder::printBoarder() {
	std::cout << "Boarder race: " << classRace << std::endl;
	std::cout << "Minimum: " << num[0] << std::endl;
	std::cout << "Maximum: " << num[1] << std::endl;
	std::cout << "Boarder breach: " << breach << std::endl;
}

void Crew_Boarder::replace() {
	std::cout << "Boarder race: ";
	std::cin >> classRace;
	std::cout << "Minimum (positive integer): ";
	std::cin >> num[0];
	std::cout << "Maximum (positive integer): ";
	std::cin >> num[1];
	std::cout << "Boarder breach (positive integer): ";
	std::cin >> breach;
}

Crew_Member::Crew_Member() :
	amount{ 0 },
	skill{ "" },
	level{ 0 },
	classRace{ "" },
	id{ "None" },
	proportion{ 0 }
{
}

void Crew_Member::printCrew() {
	std::cout << "Crew number: " << amount << std::endl;
	std::cout << "Crew skill: " << skill << std::endl;
	std::cout << "Crew skill level: " << level << std::endl;
	std::cout << "Crew name ID: " << id << std::endl;
}

void Crew_Member::replace() {
	std::cout << "Crew number (integer): ";
	std::cin >> amount;
	std::cout << "Crew skill: ";
	std::cin >> skill;
	std::cout << "Crew skill level (positive integer): ";
	std::cin >> level;
	std::cout << "Crew name ID: ";
	std::cin >> id;
}

void Crew_Member::printProp() {
	std::cout << "Crew proportion: " << proportion << std::endl;
}

void Crew_Member::replaceProp() {
	std::cout << "Crew proportion (number): ";
	std::cin >> proportion;
}

Surrender_Escape::Surrender_Escape() :
	chance{ 0 },
	timer{ 0 }
{
	for (int i{ 0 }; i < 2; i++)
		num[i] = 0;
}

void Surrender_Escape::print() {
	std::cout << "Enemy Chance: " << chance << std::endl;
	std::cout << "Enemy Timer: " << timer << std::endl;
	std::cout << "Minimum: " << num[0] << std::endl;
	std::cout << "Maximum: " << num[1] << std::endl;
}

void Surrender_Escape::replace() {
	std::cout << "Enemy Chance (number): ";
	std::cin >> chance;
	std::cout << "Enemy Timer (integer): ";
	std::cin >> timer;
	std::cout << "Minimum (integer): ";
	std::cin >> num[0];
	std::cout << "Maximum (integer): ";
	std::cin >> num[1];
}