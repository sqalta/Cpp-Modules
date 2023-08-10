#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage()
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &r)
{
	std::cout << "Copy assigment constructor called" << std::endl;
	this->name = r.name;
	this->energyPoints = r.energyPoints;
	this->attackDamage = r.attackDamage;
	this->hitPoints = r.hitPoints;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		std::cout << "No energy or hit points" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << "attacks " << target
			<< ", causing " << this->attackDamage << " points of damage!"
				<< std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "No energy or hit points" << std::endl;
	else if ((int)amount > this->hitPoints)
	{
		this->hitPoints -= int(amount);
		std::cout << "ClapTrap " << this->name << "takes " << amount
			<< " damage and died" << std::endl;
	}
	else if((int)amount < this->hitPoints)
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount
			<< " damage and " << this->hitPoints << " hit points remaining"
				<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "No energy or hit points" << std::endl;
		return ;
	}
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount
		<< " repaired and " << this->name << " has " << this->hitPoints
			<< " hit points" << std::endl;
	this->energyPoints--;
}