#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern1;

	AForm *form;


	Bureaucrat s("murat", 15);
	try
	{
		form = intern1.makeForm("presidential pardon", "Serif");
		s.signForm(*form);
		form->execute(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}