#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat name constructor called " << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Copy assignment is called" << std::endl;
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator <<(std::ostream &os, const Bureaucrat &bure)
{

	os << bure.getName() << " bureaucrat grade " <<  bure.getGrade();
	return (os);
}