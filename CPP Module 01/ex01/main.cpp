#include "zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* zombie;

	zombie = zombieHorde(5, "zombie1");
	for(int i = 0; i < 5; i++)
		zombie[i].announce();
	delete[] zombie;
}
