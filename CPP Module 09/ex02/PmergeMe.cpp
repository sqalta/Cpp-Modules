#include "PmergeMe.hpp"



PmergeMe::PmergeMe()
{
};

PmergeMe::PmergeMe(char **prompt)
{
	this->prompt = prompt;
};


PmergeMe::~PmergeMe()
{
};

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->vct = copy.vct;
	this->dqe = copy.dqe;
};

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
	this->vct = copy.vct;
	this->dqe = copy.dqe;
	return (*this);
};

bool checkArg(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
	{
        std::string str = av[i];
        char* end;
        long int result = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0')
            return false;
        if (result <= 0)
            return false;
    }
    return true;
}

int initList(char **av, int ac, std::deque<int> &dqe)
{
    for (int i = 1; i < ac; i++)
    {
        try
        {
            int nbr = std::stoi(av[i]);
            dqe.push_back(nbr);
        }
        catch (const std::invalid_argument &)
        {
            std::cerr << "Dönüşüm başarısız: " << av[i] << std::endl;
            return -1;
        }
        catch (const std::out_of_range &)
        {
            std::cerr << "Dönüşüm başarısız (taşma): " << av[i] << std::endl;
            return -2;
        }
    }
    return 0;
}

int initVector(char **av, int ac, std::vector<int> &vct)
{
    for (int i = 1; i < ac; i++)
    {
        try
        {
            int nbr = std::stoi(av[i]);
            vct.push_back(nbr);
        }
        catch (const std::invalid_argument &)
        {
            std::cerr << "Dönüşüm başarısız: " << av[i] << std::endl;
            return -1;
        }
        catch (const std::out_of_range &)
        {
            std::cerr << "Dönüşüm başarısız (taşma): " << av[i] << std::endl;
            return -2;
        }
    }
    return 0;
}

void printVect(std::vector<int> vct)
{
	for (std::vector<int>::iterator a = vct.begin(); a != vct.end(); a++)
		std::cout << *a << std::endl;
}

void insertionSortVct(std::vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeVct(std::vector<int> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
	{
        if (leftArray[i] <= rightArray[j])
		{
            arr[k] = leftArray[i];
            i++;
        }
		else
		{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
	{
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

int mergeSortWithInsertionVct(std::vector<int> &arr, int left, int right) {
    int n = right - left + 1;
    if (n >= 3)
	{
        int third = n / 3;
        int leftThird = left + third - 1;
        int rightThird = left + 2 * third - 1;
	 	mergeSortWithInsertionVct(arr, left, leftThird);
        mergeSortWithInsertionVct(arr, leftThird + 1, rightThird);
        mergeSortWithInsertionVct(arr, rightThird + 1, right);
        mergeVct(arr, left, leftThird, rightThird);
        mergeVct(arr, left, rightThird, right);
    }
	else
        insertionSortVct(arr, left, right);
	return 0;
}

bool PmergeMe::startSortVector(int ac)
{
	if (!checkArg(ac, this->prompt))
	{
		std::cout << "Error" << std::endl;
		return false;
	}
	if (initVector(this->prompt, ac, this->vct))
		return false;
	// if (mergeSortWithInsertionVct(this->vct, 0, this->vct.size() - 1))
	// 	return false;
	return true;
}

void insertionSortDeque(std::deque<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeDeque(std::deque<int> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::deque<int> leftDeque, rightDeque;
    for (int i = 0; i < n1; i++)
        leftDeque.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++)
        rightDeque.push_back(arr[middle + 1 + j]);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftDeque[i] <= rightDeque[j]) {
            arr[k] = leftDeque[i];
            i++;
        } else {
            arr[k] = rightDeque[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftDeque[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightDeque[j];
        j++;
        k++;
    }
}

int mergeSortWithInsertionDeque(std::deque<int> &arr, int left, int right) {
    int n = right - left + 1;
    if (n >= 3) {
        int third = n / 3;
        int leftThird = left + third - 1;
        int rightThird = left + 2 * third - 1;
        mergeSortWithInsertionDeque(arr, left, leftThird);
        mergeSortWithInsertionDeque(arr, leftThird + 1, rightThird);
        mergeSortWithInsertionDeque(arr, rightThird + 1, right);
        mergeDeque(arr, left, leftThird, rightThird);
        mergeDeque(arr, left, rightThird, right);
    } else
        insertionSortDeque(arr, left, right);
	return 0;
}

bool PmergeMe::startSortDeque(int ac)
{
	if (!checkArg(ac, this->prompt))
	{
		std::cout << "Error" << std::endl;
		return false;
	}
	if (initList(this->prompt, ac, dqe))
		return false;
	if (mergeSortWithInsertionDeque(dqe, 0, this->dqe.size() - 1))
		return false;
	// for (std::deque<int>::iterator a = dqe.begin(); a != dqe.end(); a++)
	// 	std::cout << *a << std::endl;
	return true;
}

