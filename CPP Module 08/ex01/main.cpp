#include "Span.hpp"


int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		Span t(3);

		t.addNumber(1);
		t.addNumber(1);
		t.addNumber(1);
		t.addNumber(1);

		std::cout << t.shortestSpan() << std::endl;
		std::cout << t.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	getchar();
	std::vector<int> vect;

	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		vect.push_back(i);
	}
	Span sp1(10000);

	sp1.addTestNumbers(vect.begin(), vect.end());

	std::cout << sp1 << std::endl;
}