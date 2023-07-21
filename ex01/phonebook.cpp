#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->id = 0;
	this->id_flag = 0;
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
	std::cout << this->id << std::endl;
	this->contact[this->id] = contact;
	this->id += 1;
	if (this->id == 8)
	{
		this->id = 0;
		this->id_flag = 1;
	}
}

void Phonebook::printContact(int flag)
{
	if (flag == -1)
	{
		if (this->id_flag == 1)
			this->id = 8;
		for(int i = 0; i < this->id; i++)
		{
			if (i >= 10)
				std::cout << std::setw(10) << i << "." << "|";
			else
				std::cout << std::setw(10) << i << "|";
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
			std::cout << std::endl;
		}
	}
	else
	{
		if (flag < this->id)
		{
			if (this->id >= 10)
				std::cout << std::setw(10) << flag << "." << "|";
			else
				std::cout << std::setw(10) << flag << "|";
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
			std::cout << std::endl;
		}
		else
			std::cout << "Wrong ID. " << std::endl;
	}
}

void Phonebook::search(void)
{
	std::string	input;

	if (id > 0)
		printContact(-1);
	else
	{
		std::cout << "Phonebook is empty !" << std::endl;
		std::cout << "Press enter to continue. " << std::endl;
		getline(std::cin, input);
		return ;
	}
	std::cout << "Please enter the contact id. " << std::endl;
	getline(std::cin, input);
	if (input != "")
		printContact(atoi(input.c_str()));
	else
		std::cout << "Wrong id number!" << std::endl;
}

