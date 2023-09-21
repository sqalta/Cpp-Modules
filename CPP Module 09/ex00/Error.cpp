#include "Error.hpp"


void Error::fileError()
{
	std::cout << "Error: Failed to open the file. " << std::endl;
	exit(1);
};

void Error::firstLineError()
{
	std::cout << "ValueError: The first line of the file should be 'data | value'." << std::endl;
	exit (1);
};

int Error::negativeNumberError()
{
	std::cout << "Error: not a positive number." << std::endl;
	return 1;
}

int Error::badInputError(std::string &date)
{
	std::cout << "Error: bad input => " << date << std::endl;
	return 1;
}

int Error::tooLargeNumber()
{
	std::cout << "Error: too large a number. " << std::endl;
	return 1;
}


