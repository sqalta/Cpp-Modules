#include "weapon.hpp"


Weapon::Weapon(std::string &type):type(type)
{
	return ;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType()
{
	return (this->type);
}