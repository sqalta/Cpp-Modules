#include "humanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
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
	std::cout << this->name << "attacks with their" << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

