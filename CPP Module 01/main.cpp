#include "zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	Zombie *zombie1;
	randomChump("2"); //stack
	zombie1 = newZombie("serif"); //heap
	delete zombie1;
}