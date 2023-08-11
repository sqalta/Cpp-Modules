#include "FragTrap.hpp"

int main()
{
    FragTrap usr1("serif");
    FragTrap usr2("ali");
    FragTrap usr3("murat");   

    usr1.attack("ali");
    usr2.takeDamage(50);
    usr2.attack("murat");
    usr3.takeDamage(80);
    usr2.attack("serif");
    usr1.takeDamage(30);
    usr3.beRepaired(20);
    usr3.attack("serif");
    usr1.takeDamage(40);
    usr2.attack("murat");
    usr3.takeDamage(70);
    usr1.attack("murat");
    usr3.takeDamage(10);
	usr3.highFivesGuys();
}