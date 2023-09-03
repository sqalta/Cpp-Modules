#include "Form.hpp"

Form::Form() : name("Default Form Name"), requiredToSign(150), requiredToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	this->isSigned = false;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int toSign, int toExecute) : name(name), requiredToSign(toSign), requiredToExecute(toExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	this->isSigned = false;
}

Form &Form::operator=(const Form &r)
{
	this->isSigned = r.isSigned;
	std::cout << "Form copy assignment called" << std::endl;
	return (*this);
}

Form::Form(const Form &copy) : name(copy.name), requiredToSign(copy.requiredToSign), requiredToExecute(copy.requiredToExecute)
{
	*this = copy;
}


bool Form::getIsSigned()
{
	return this->isSigned;
}

 std::string Form::getName() const
{
	return (this->name);
}

 int Form::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

 int Form::getGradeToSign() const
{
	return (this->requiredToSign);
}

void Form::beSigned (const Bureaucrat &b)
{
	if (b.getGrade() > this->requiredToSign)
		throw GradeTooLowException();
	std::cout << "The form has been signed." << std::endl;
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

