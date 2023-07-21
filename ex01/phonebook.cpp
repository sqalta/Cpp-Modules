#include "phonebook.hpp"

Phonebook::Phonebook()
{
	id = 0;
	for(int i = 0; i < 8; i++)
	{
		this->contact[i] = Contact();
	}
}

void Phonebook::add(Contact contact)
{
	std::string input;
	std::string value;

	for(int i = 0; i <= 4; i++)
	{
		if (i == 0)
			value = "first name";
		else if (i == 1)
			value = "last name";
		else if (i == 2)
			value = "nick name";
		else if (i == 3)
			value = "phone number";
		else if (i == 4)
			value = "darkest Secret";

		while (true)
		{
			std::cout << "Please enter the contact's " << value << std::endl;
			getline(std::cin, input);
			if (input != "")
			{
				if (i == 0)
					contact.setFirstName(input);
				else if (i == 1)
					contact.setLastName(input);
				else if (i == 2)
					contact.setNickName(input);
				else if (i == 3)
					contact.setPhoneNumber(input);
				else if (i == 4)
					contact.setDarkestSecret(input);
				break;
			}
		}
	}
	std::cout << "The contact has been registered." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	getline(std::cin, input);
	if (this->id == 7)
		this->id = 0;
	this->contact[this->id++] = contact;
}

void Phonebook::printContact(int flag)
{
	if (flag == 0)
	{
		for(int i = 0; i <= id; i++)
		{
			if (this->id >= 10)
				std::cout << std::setw(10) << this->id << "." << "|";
			else
				std::cout << std::setw(10) << this->id << "|";
			if (this->contact[i].getFirstName().length() >= 10)
				std::cout << std::setw(10) << this->contact[i].getFirstName().substr(0,9) << "." << "|";
			else
				std::cout << std::setw(10) << this->contact[i].getFirstName() << "|";
			if (this->contact[i].getLastName().length() >= 10)
				std::cout << std::setw(10) << this->contact[i].getLastName().substr(0,9) << "." << "|";
			else
				std::cout << std::setw(10) << this->contact[i].getLastName() << "|";
			if (this->contact[i].getNickName().length() >= 10)
				std::cout << std::setw(10) << this->contact[i].getNickName().substr(0,9) << "." << "|";
			else
				std::cout << std::setw(10) << this->contact[i].getNickName() << "|";
		}
	}
	else
	{
		if (this->id >= 10)
			std::cout << std::setw(10) << this->id << "." << "|";
		else
			std::cout << std::setw(10) << this->id << "|";
		if (this->contact[flag].getFirstName().length() >= 10)
			std::cout << std::setw(10) << this->contact[flag].getFirstName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[flag].getFirstName() << "|";
		if (this->contact[flag].getLastName().length() >= 10)
			std::cout << std::setw(10) << this->contact[flag].getLastName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[flag].getLastName() << "|";
		if (this->contact[flag].getNickName().length() >= 10)
			std::cout << std::setw(10) << this->contact[flag].getNickName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[flag].getNickName() << "|";
		if (this->contact[flag].getPhoneNumber().length() >= 10)
			std::cout << std::setw(10) << this->contact[flag].getPhoneNumber().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[flag].getPhoneNumber() << "|";
		if (this->contact[flag].getDarkestSecret().length() >= 10)
			std::cout << std::setw(10) << this->contact[flag].getDarkestSecret().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[flag].getDarkestSecret() << "|";
	}
}

void Phonebook::search(void)
{
	std::string	input;

	if (id > 0)
		printContact(0);
	else
	{
		std::cout << "Phonebook is empty !" << std::endl;
		return ;
	}
	getline(std::cin, input);
	if (input != "")
		printContact(atoi(input.c_str()));
	else
		std::cout << "Wrong id number!" << std::endl;
}

