#include "humanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void HumanA::setName(std::string name)
{
	this->name = name;
}

std::string HumanA::getName()
{
	return (this->name);
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}