#include "harl.hpp"

using std::cout;
using std::endl;

void Harl::debug()
{
	cout << "debug" << endl;	
}

void Harl::info()
{
	cout << "info" << endl;
}

void Harl::warning()
{
	cout << "warning" << endl;
}

void Harl::error()
{
	cout << "error" << endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && level != levels[i])
		i++;
	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
			break;
	}
}