#include "ScavTrap.hpp"

int main ()
{
	ScavTrap serif("serif");
	ScavTrap cagri("cagri");

	serif.attack("güllü");
	serif.takeDamage(20);
	cagri = serif;
	std::cout << cagri.getHitPoints() << std::endl;
	std::cout << serif.getHitPoints() << std::endl;
	serif.beRepaired(10);
	std::cout << serif.getHitPoints() << std::endl;
}