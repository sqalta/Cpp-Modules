#include "ScalarConversion.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		return 1;
	}
	std::string s = av[1];
	ScalarConversion::convertType(s);
	return 0;
}