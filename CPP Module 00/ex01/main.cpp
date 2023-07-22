#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	Contact contact;
	std::string	command;

	while (true)
	{
		std::cout << "Please enter a command. " << std::endl;
		std::cout << "Commands" << std::endl;
		std::cout << "ADD   :Registers a new contact." << std::endl;
		std::cout << "SEARCH:Displays a specific contact." << std::endl;
		std::cout << "EXİT  :The program closes and the contacts are lost forever." << std::endl;
		getline(std::cin, command);
		if (command == "EXİT")
			return (0);
		else if (command == "ADD")
			phonebook.add(contact);
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Wrong command. Please try again. " << std::endl; 
	}
	return (0);
}