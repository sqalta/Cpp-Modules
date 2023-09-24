#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span();
		Span(int N);
		Span(const Span &copy);
		Span& operator=(const Span &copy);
		~Span();

		class CapacityFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class VectorIsEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		int getN();
		std::vector<int> getNumbers();
		int longestSpan();
		int shortestSpan();

		void addNumber(int number);
		void addTestNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator last);
};

std::ostream& operator << (std::ostream &of, Span &r);
#endif