#include "easyfind.hpp"

#include <vector>
#include <array>

int main()
{
	std::vector<int> vect;
	std::array<int, 4> arr2 = {4, 5, 6, 7};

	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);

	std::cout << *easyfind(arr2, 4) << std::endl;
	std::cout << *easyfind(vect, 2) << std::endl;
	try
	{
		std::cout << *easyfind(vect, 1231);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}