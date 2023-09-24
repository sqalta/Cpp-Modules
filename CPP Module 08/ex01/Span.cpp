#include "Span.hpp"

Span::Span()
{
};

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span &copy)
{
	this->numbers = copy.numbers;
	this->N = copy.N;
};

Span& Span::operator=(const Span &copy)
{
	this->numbers = copy.numbers;
	this->N = copy.N;
	return (*this);
};

Span::Span(int N)
{
	this->N = N;
};

void Span::addNumber(int number)
{
	try
	{
		if (this->numbers.size() >= N)
			throw CapacityFullException();
		this->numbers.push_back(number);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
};

void Span::addTestNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator last)
{
	while (begin != last)
	{
		if (this->numbers.size() > this->N)
			throw CapacityFullException();
		this->numbers.push_back(*begin);
		begin++;
	}
};

int Span::longestSpan()
{
	std::vector<int>::iterator maxElements = std::max_element(this->numbers.begin(), this->numbers.end());
	std::vector<int>::iterator minElements = std::min_element(this->numbers.begin(), this->numbers.end());
	if (this->numbers.size() == 1 || this->numbers.size() == 0)
		throw VectorIsEmptyException();
	return (*maxElements - *minElements);
};

int Span::shortestSpan()
{
	if (this->numbers.size() == 1 || this->numbers.size() == 0)
		throw VectorIsEmptyException();
	int min = longestSpan();
	for (int i = 0; (int)this->numbers.size() > i; i++)
	{
		for (int j = i + 1; (int)this->numbers.size() > j; j++)
		{
			if (min > abs(this->numbers[i] - this->numbers[j]))
				min = abs(this->numbers[i] - this->numbers[j]);
		}
	}
	return min;
};

const char* Span::VectorIsEmptyException::what() const throw()
{
	return "Vector is empty!";
};

const char* Span::CapacityFullException::what() const throw()
{
	return "The vector's capacity is full.";
};

int Span::getN()
{
	return this->N;
}

std::vector<int> Span::getNumbers()
{
	return this->numbers;
}

std::ostream& operator << (std::ostream &of, Span &r)
{
	const std::vector<int>& numbers = r.getNumbers();
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
	    of << *it << std::endl;
	}
	return of;
}
