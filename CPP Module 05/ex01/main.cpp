#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat b1("b1", 160);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b2("b2", 1);
	try{
		b2.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b3("b3", 150);
	try{
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Form f1("f1", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}