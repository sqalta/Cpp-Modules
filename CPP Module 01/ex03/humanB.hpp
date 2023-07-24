#ifndef HUMAN_B
#define HUMAN_B

#include "weapon.hpp"

class HumanB 
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void setName(std::string name);
		std::string getName(void);
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif