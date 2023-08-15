#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	this->brain = new Brain(*(copy.brain));
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Hav Hav!" << std::endl;
}