#include "humanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->weapon = &weapon;
	this->name = name;
}

HumanB::~HumanB()
{
	std::cout << "The destructor method executed" << std::endl;
}

void HumanB::setName(std::string name)
{
	this->name = name;
}

std::string HumanB::getName()
{
	return (this->name);
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

