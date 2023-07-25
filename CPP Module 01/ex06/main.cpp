#include "harl.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong Input" << std::endl;
		return (1);
	}
	Harl harl;

	harl.complain(av[1]);
}