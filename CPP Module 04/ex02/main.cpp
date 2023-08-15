#include "Animal.hpp"
#include "Cat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{

	const Animal* animal[4] = {new Dog(),new Cat()};

	for (int i = 0; i < 2; i++) {
		animal[i]->makeSound();
		delete animal[i];
	}
    return 0;

}