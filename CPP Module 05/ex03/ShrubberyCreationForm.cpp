#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

int ShrubberyCreationForm::getGradeToSign() const
{
	return (this->requiredToSign);
}

int ShrubberyCreationForm::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

void ShrubberyCreationForm::beSigned (const Bureaucrat &b) 
{
	if (b.getGrade() > this->requiredToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
    ofs << "       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\"
	<< std::endl;
    ofs.close();
	std::cout << this->getTarget() << " has been created." << std::endl;
}

