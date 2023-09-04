#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include "AForm.hpp"

#include "Bureaucrat.hpp"


class RobotoMyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotoMyRequestForm();
		~RobotoMyRequestForm();
		RobotoMyRequestForm(std::string target);
		RobotoMyRequestForm(const RobotoMyRequestForm &copy);
		RobotoMyRequestForm &operator =(const RobotoMyRequestForm &copy);

		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;
};

#endif