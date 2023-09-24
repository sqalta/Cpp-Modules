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

int Rpn::tokenizer()
{
	std::pair<std::string, std::string> element;

	int i = 0;
	while (this->prompt[i])
	{
		if (!std::isdigit(this->prompt[i]) && (!std::strchr( "+-/*", this->prompt[i])))
			return 1;
		element.first = this->prompt[i];
		if (std::strchr( "+-/*", this->prompt[i]))
			element.second = "operator";
		else
			element.second = "digit";
		this->tokens.insert(element);
	}
	return 0;
}

void Rpn::calculate()
{
	for (std::map<std::string, std::string>::iterator a = this->tokens.begin();
				a != this->tokens.end(); a++)
	{
		if (a->second == "digit")
			this->stackNumber.push(std::atoi(a->first.c_str()));
		else
		{
			
		}
	}
}

void Rpn::start()
{
	removeSpaces(this->prompt);
	if (tokenizer())
	{
		std::cout << "Wrong input!" << std::endl;
		return ;
	}
	calculate();
}