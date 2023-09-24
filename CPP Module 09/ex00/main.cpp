#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include "BitcoinExchange.hpp"

#include <iostream>
#include <string>

#include <iostream>
#include <string>

#include <ctime>


int main (int ac, char **av)
{
	if (ac != 2)
		return 1;
	BitcoinExchange test;
	test.readData("data.csv");
	test.startExchange(av[1]);
}