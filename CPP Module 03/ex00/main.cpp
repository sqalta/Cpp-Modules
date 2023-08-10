#include "ClapTrap.hpp"

int main ()
{
    ClapTrap usr1("serif");
    ClapTrap usr2("ali");
    ClapTrap usr3("palta");    

    usr1.attack("ali");
    usr2.takeDamage(4);
    usr2.attack("palta");
    usr3.takeDamage(6);
    usr2.attack("serif");
    usr1.takeDamage(8);
    usr3.beRepaired(3);
    usr3.attack("serif");
    usr1.takeDamage(5);
    usr2.attack("serif");
    usr1.takeDamage(3);
}