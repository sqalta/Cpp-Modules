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
	funcArray funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*funcs[i])();
}