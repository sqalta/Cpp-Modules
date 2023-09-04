#include "PresidentialPardonForm.hpp"

#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

int PresidentialPardonForm::getGradeToSign() const
{
	return (this->requiredToSign);
}

int PresidentialPardonForm::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

void PresidentialPardonForm::beSigned (const Bureaucrat &b) 
{
	if (b.getGrade() > this->requiredToSign)
		throw GradeTooLowException();
	std::cout << "The form has been signed." << std::endl;
	this->isSigned = true;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	if (this->requiredToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}