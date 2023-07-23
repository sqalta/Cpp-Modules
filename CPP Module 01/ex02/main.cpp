#include <iostream>

int main(void)
{
	std::string str = "serif";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Address of the str: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the str: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}