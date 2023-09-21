#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>

class Error
{
	public:
		static void fileError();
		static void firstLineError();
		static int negativeNumberError();
		static int badInputError(std::string &date);
		static int tooLargeNumber();
};

#endif