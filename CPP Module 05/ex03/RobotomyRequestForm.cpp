#include "RobotomyRequestForm.hpp"

#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &copy)
{
	this->isSigned = copy.isSigned;
	return (*this);
}

int RobotomyRequestForm::getGradeToSign() const
{
	return (this->requiredToSign);
}

int RobotomyRequestForm::getGradeToExecute() const
{
	return (this->requiredToExecute);
}

void RobotomyRequestForm::beSigned (const Bureaucrat &b) 
{
	if (b.getGrade() > this->requiredToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << "zzzzzz noises" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}