#include "FragTrap.hpp"
#include "ClapTrap.hpp"


FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	ClapTrap::operator= (copy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->name << " says high five buddy!" << std::endl;
}

