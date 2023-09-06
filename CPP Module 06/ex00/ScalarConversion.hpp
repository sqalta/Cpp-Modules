#ifndef	SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include <iostream>
#include <string>

class ScalarConversion
{
	public:
		ScalarConversion();
		~ScalarConversion();
		ScalarConversion(ScalarConversion &copy);
		ScalarConversion &operator=(ScalarConversion &copy);

		static void convertType(std::string &arg);
		static std::string findType(std::string &arg);

		static bool isInt(std::string &arg);
		static bool isChar(std::string &arg);
		static bool isFloat(std::string &arg);
		static bool isDouble(std::string &arg);

		static void printInt(float arg, char s, int flag1);
		static void printChar(float arg, char s, int flag1);
		static void printFloat(float arg, char s, int flag, int flag1);
		static void printDouble(float arg, char s, int flag, int flag1);
};


#endif