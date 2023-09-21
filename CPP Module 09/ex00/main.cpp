#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{

	(void)(ac);
	BitcoinExchange test;
	test.readData("data.csv");
	test.startExchange(av[1]);
}