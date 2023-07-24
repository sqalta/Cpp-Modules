#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void setName(std::string name);
		std::string getName(void);
		void attack(void);
};

#endif