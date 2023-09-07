#include "ScalarConversion.hpp"


ScalarConversion::ScalarConversion()
{
}

ScalarConversion::~ScalarConversion()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConversion::ScalarConversion(ScalarConversion &copy)
{
	(void)copy;
}

ScalarConversion &ScalarConversion::operator=(ScalarConversion &copy)
{
	(void)copy;
	return (copy);
}


bool ScalarConversion::isChar(std::string &arg)
{
	char *ptr;

	strtol(&arg[0], &ptr, 10);
	if (arg.length() == 1)
	{
		if (isnumber(arg[0]))
			return false;
		else
			return true;
	}
	return false;
}

bool ScalarConversion::isInt(std::string &arg)
{
	char *ptr;

	strtol(&arg[0], &ptr, 10);
	if (*ptr == '\0')
		return true;
	return false;
}

bool ScalarConversion::isFloat(std::string &arg)
{
	char *ptr;

	strtof(&arg[0], &ptr);
	if (*ptr == 'f')
		if (*(ptr + 1) == '\0')
			return true;
	return false;
}

bool ScalarConversion::isDouble(std::string &arg)
{
	char *ptr;

	strtol(&arg[0], &ptr, 10);
	if (*ptr == '.')
		if (strtod(&arg[0], &ptr))
			if (!*ptr)
				return true;
	return false;
}

std::string ScalarConversion::findType(std::string &arg)
{
	if (isChar(arg))
		return "char";
	else if (isFloat(arg))
		return "float";
	else if (isDouble(arg))
		return "double";
	else if (isInt(arg))
		return "int";
	else
		return "string";
}

void ScalarConversion::convertType(std::string &arg)
{
	float	number = 0;
	int		intNumber = 0;
	int		flag = 0;
	int		flag1 = 1;
	std::string type = findType(arg);
	if (type == "string" && arg != "nan" && arg != "nanf")
	{
		std::cout << arg << " is not convartable!" << std::endl;
		return ;
	}
	if (type != "char")
	{
		number = atof(&(arg[0]));
		intNumber = atoi(&(arg[0]));
		if (number == intNumber)
			flag = 1;
		flag1 = 0;
	}
	printChar(number, arg[0], flag1);
	printInt(number, arg[0], flag1);
	printFloat(number, arg[0], flag, flag1);
	printDouble(number, arg[0], flag, flag1);
}

void ScalarConversion::printChar(float arg, char s, int flag1)
{
	std::cout << "char: ";
	if (flag1 == 1)
	{
		std::cout << "'" << s << "'" << std::endl;
		return ;
	}
	if (isnan(arg))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (!std::isprint((int)arg))
	{
		std::cout << "Non displayeble" << std::endl;
		return;
	}
	std::cout << "'" << static_cast<char>(arg) << "'" << std::endl;
}

void ScalarConversion::printFloat(float arg, char s, int flag, int flag1)
{
	std::cout << "float: ";
	if (flag1 == 1)
	{
		std::cout << static_cast<float>(s);
	}
	else
		std::cout << arg;
	if (flag == 1)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConversion::printInt(float arg, char s, int flag1)
{
	long int k = static_cast<long int>(arg);
	std::cout << "int: ";
	if (flag1 == 1)
	{
		std::cout << static_cast<int>(s) << std::endl;
		return; 
	}
	if (k > INT_MAX || k < INT_MIN || isnan(arg))
		std::cout << "impossible" << std::endl;
	else
		std::cout << k << std::endl;
}

void ScalarConversion::printDouble(float arg, char s, int flag, int flag1)
{
	std::cout << "double: ";
	if (flag1 == 1)
	{
		std::cout << static_cast<double>(s);
	}
	else
		std::cout << static_cast<double>(arg);
	if (flag == 1)
		std::cout << ".0";
	std::cout << std::endl;
}
