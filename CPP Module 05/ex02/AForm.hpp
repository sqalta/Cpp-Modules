#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool isSigned;
		const int requiredToSign;
		const int requiredToExecute;

	public:
		AForm();
		~AForm();
		AForm(std::string name, int toSign, int toExecute);
		AForm (const AForm &copy);
		AForm &operator = (const AForm &copy);

		bool getIsSigned();
		std::string getName() const;
		virtual int getGradeToSign() const;
		virtual int getGradeToExecute() const;
		virtual void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		class 	FormNotSigned : public std::exception
		{
			const char *what() const throw();
		};

    	virtual void execute(Bureaucrat const & executor) const;
};

#endif