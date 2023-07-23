#include "zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	Zombie* zombie1;
	Zombie* zombie2;

	zombie1 = newZombie("heap1");
	zombie2 = newZombie("heap2");

	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;

	randomChump("stack");
}
