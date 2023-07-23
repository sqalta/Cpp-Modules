#include "humanA.hpp"
#include "humanB.hpp"

int main()
{
	std::string s = "serif";
	Weapon club = Weapon(s);
	HumanA bob("Bob", club);
	bob.attack();
	s = "ali";
	bob.attack();
}