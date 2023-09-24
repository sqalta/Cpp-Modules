#include "RPN.hpp"

Rpn::Rpn(std::string &input) : prompt(input)
{
};

Rpn::~Rpn()
{
	std::cout << "Rpn destructor called." << std::endl;
};

Rpn::Rpn(const Rpn &copy) : prompt(copy.prompt)
{
	this->stackNumber = copy.stackNumber;
};

Rpn& Rpn::operator=(const Rpn &copy)
{
	this->stackNumber = copy.stackNumber;
	return (*this);
};

void removeSpaces(std::string &str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}

int Rpn::checkArg(std::string &prompt)
{
	int i = -1;
	while (prompt[++i])
	{
		if (std::isdigit(prompt[i]) || std::strchr("+ - / *", prompt[i]))
			continue;
		return (1);
	}
	return(0);
}

//stack boş ise kontrol et!!!
int Rpn::updateStack(char c)
{
	int num1;
	int num2;

	if (this->stackNumber.size() < 2)
	{
		std::cout << "There are not enough operands for the operator." << std::endl;
		return -1;
	}
	num1 = this->stackNumber.top();
	this->stackNumber.pop();
	num2 = this->stackNumber.top();
	this->stackNumber.pop();
    if (c == '+')
        this->stackNumber.push(num2 + num1);
    else if (c == '-')
        this->stackNumber.push(num2 - num1);
    else if (c == '*')
        this->stackNumber.push(num2 * num1);
    else
        this->stackNumber.push(num2 / num1);
	return 0;
}

int Rpn::calculate()
{
	int i = -1;
	while (prompt[++i])
	{
		if (std::strchr("+ - / *", prompt[i]))
		{
			if (updateStack(prompt[i]))
				return -1;
		}
		else
			this->stackNumber.push(prompt[i] - '0');
	}
	return 0;
}

void Rpn::start()
{
	removeSpaces(this->prompt);
	if (checkArg(this->prompt))
	{
		std::cout << "Error!" << std::endl;
		return ;
	}
	if (calculate())
		return ;
	if (this->stackNumber.size() >= 2)
	{
		while (this->stackNumber.size() != 0)
		{
			std::cout << this->stackNumber.top() << " ";
			this->stackNumber.pop();
		}
		std::cout << std::endl;
	}
	else
		std::cout << this->stackNumber.top() << std::endl;
}