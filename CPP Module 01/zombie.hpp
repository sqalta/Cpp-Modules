#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void announce(void);
};

#endif
