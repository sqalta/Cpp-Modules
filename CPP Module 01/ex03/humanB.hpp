#ifndef HUMAN_B
#define HUMAN_B

#include "weapon.hpp"

class HumanB 
{
	private:
		std::string name;
		Weapon weapon;
	public:
		HumanB(std::string name);
		void setName(std::string name);
		std::string getName(void);
		void attack(void);
		void setWeapon(Weapon weapon);
};

#endif