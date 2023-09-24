#include "RPN.hpp"
#include <map>
#include <fstream>


int main (int ac, char **av)
{

	if (ac == 2)
	{
		std::string input = av[1];
		Rpn a(input);

		a.start();
	}
	return 0;
}

