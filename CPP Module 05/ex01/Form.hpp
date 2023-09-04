#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int requiredToSign;
		const int requiredToExecute;

	public:
		Form();
		~Form();
		Form(std::string name, int toSign, int toExecute);
		Form (const Form &copy);
		Form &operator = (const Form &copy);

		bool getIsSigned();
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

#endif