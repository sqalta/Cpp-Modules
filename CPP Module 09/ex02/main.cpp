#include "PmergeMe.hpp"


#include <iostream>
#include <vector>


int main(int ac, char **av)
{
	PmergeMe test(av);

	std::clock_t start = std::clock();
	test.startSortVector(ac);
	std::clock_t end = std::clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << elapsedTime << std::endl;
	std::clock_t startD = std::clock();
	test.startSortDeque(ac);
	std::clock_t endD = std::clock();
	double elapsedTime1 = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000;
	std::cout << elapsedTime1 << std::endl;
}
