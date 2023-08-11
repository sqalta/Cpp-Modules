#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->attackDamage = copy.attackDamage;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap copy assignment constructor called" << std::endl;
    ClapTrap::operator= (copy);
    return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap Guard Gate!" << std::endl;
}
