#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP


#include <iostream>
#include "AForm.hpp"

#include "Bureaucrat.hpp"



class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &copy);

		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif