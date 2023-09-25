#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		char **prompt;
		std::vector<int> vct;
		std::deque<int> dqe;
	public:
		PmergeMe();
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);

		bool startSortVector(int ac);
		bool startSortDeque(int ac);
		void listMergeSort(int left, int right);
		int	mergeSortWithInsertionLst(std::list<int> &arr, int left, int right);
};
#endif