#include "AForm.hpp"

AForm::AForm() : name("Default AForm Name"), requiredToSign(150), requiredToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
	this->isSigned = false;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, int toSign, int toExecute) : name(name), requiredToSign(toSign), requiredToExecute(toExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	this->isSigned = false;
}

AForm &AForm::operator=(const AForm &r)
{
	this->isSigned = r.isSigned;
	std::cout << "AForm copy assignment called" << std::endl;
	return (*this);
}

AForm::AForm(const AForm &copy) : name(copy.name), requiredToSign(copy.requiredToSign), requiredToExecute(copy.requiredToExecute)
{
	*this = copy;
}


bool AForm::getIsSigned()
{
	return this->isSigned;
}

 std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

int AForm::getGradeToSign() const
{
	return (this->requiredToSign);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "Form not signed";
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (this->isSigned == false)
		throw FormNotSigned();
	if (this->requiredToExecute < executor.getGrade())
		throw GradeTooLowException();
}