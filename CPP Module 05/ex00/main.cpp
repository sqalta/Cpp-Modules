#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat b1("serif", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("ali", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat b3("palta", 150);
	try
	{
		b3.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b3 << std::endl;
	b3.incrementGrade();
	std::cout << b3 << std::endl;
}