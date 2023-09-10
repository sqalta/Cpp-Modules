#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
		MutantStack &operator=(const MutantStack &copy)
		{
			std::stack<T>::operator=(copy);
			return *this;
		}
		~MutantStack() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { 
			return std::stack<T>::c.begin(); 
		}
		iterator end() { 
			return std::stack<T>::c.end(); 
		}
};

#endif