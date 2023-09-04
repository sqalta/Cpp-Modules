#include "RobotomyRequestForm.hpp"

#include <fstream>

RobotoMyRequestForm::RobotoMyRequestForm() : AForm("RobotoMyRequestForm", 72, 45)
{
	this->target = "Default";
}

RobotoMyRequestForm::RobotoMyRequestForm(std::string target) : AForm("RobotoMyRequestForm", 72, 45)
{
	this->target = target;
}

RobotoMyRequestForm::~RobotoMyRequestForm()
{
}

RobotoMyRequestForm::RobotoMyRequestForm(const RobotoMyRequestForm &copy) : AForm(copy)
{
}

RobotoMyRequestForm &RobotoMyRequestForm::operator =(const RobotoMyRequestForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

int RobotoMyRequestForm::getGradeToSign() const
{
	return (this->requiredToSign);
}

int RobotoMyRequestForm::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

void RobotoMyRequestForm::beSigned (const Bureaucrat &b) 
{
	if (b.getGrade() > this->requiredToSign)
		throw GradeTooLowException();
	std::cout << "The form has been signed." << std::endl;
	this->isSigned = true;
}

void RobotoMyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << "xxxxxxx noises" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}