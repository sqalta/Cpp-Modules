#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <map>

class Rpn
{
	private:
		std::string &prompt;
		std::stack<int> stackNumber;
		std::map<std::string, std::string> tokens;
	public:
		Rpn(std::string &input);
		~Rpn();
		Rpn& operator=(const Rpn &copy);
		Rpn(const Rpn &copy);

		void start();
		int tokenizer();
		void calculate();
};


#endif