#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *f = new RobotomyRequestForm("serif");
	AForm *f1 = new ShrubberyCreationForm("ali");
	AForm *f2 = new PresidentialPardonForm("palta");
	Bureaucrat s("Bureaucrat", 3);
	s.signForm(*f);
	s.signForm(*f1);
	s.signForm(*f2);
	getchar();
	try
	{
		f->execute(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	getchar();
	try
	{
		f1->execute(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	getchar();
	try
	{
		f2->execute(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}