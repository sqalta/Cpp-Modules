#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>

class PmergeMe
{
	private:
		char **prompt;
		std::vector<int> vct;
		std::list<int> lst;
	public:
		PmergeMe();
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);

		bool startSortVector(int ac);
		bool startSortList(int ac);
		void insertionSortLst(int left, int right);
		void listMergeSort(int left, int right);
		int mergeSortWithInsertionLst(std::list<int> &arr, int left, int right);
};
#endif