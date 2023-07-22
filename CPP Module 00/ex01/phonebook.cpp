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
	this->contact[this->id] = contact;
	this->id += 1;
	if (this->id == 8)
	{
		this->id = 0;
		this->id_flag = 1;
	}
}

void Phonebook::printAllContact(void)
{
	int flag1;

	flag1 = this->id;
	if (this->id_flag == 1)
		flag1 = 8;
	for(int i = 0; i < flag1; i++)
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

void Phonebook::displayContactInfo(int contactId)
{
	if ((contactId <= 7) && (contactId < this->id || this->id_flag))
	{
		if (this->id >= 10)
			std::cout << std::setw(10) << contactId << "." << "|";
		else
			std::cout << std::setw(10) << contactId << "|";
		if (this->contact[contactId].getFirstName().length() >= 10)
			std::cout << std::setw(10) << this->contact[contactId].getFirstName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[contactId].getFirstName() << "|";
		if (this->contact[contactId].getLastName().length() >= 10)
			std::cout << std::setw(10) << this->contact[contactId].getLastName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[contactId].getLastName() << "|";
		if (this->contact[contactId].getNickName().length() >= 10)
			std::cout << std::setw(10) << this->contact[contactId].getNickName().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[contactId].getNickName() << "|";
		if (this->contact[contactId].getPhoneNumber().length() >= 10)
			std::cout << std::setw(10) << this->contact[contactId].getPhoneNumber().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[contactId].getPhoneNumber() << "|";
		if (this->contact[contactId].getDarkestSecret().length() >= 10)
			std::cout << std::setw(10) << this->contact[contactId].getDarkestSecret().substr(0,9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[contactId].getDarkestSecret() << "|";
		std::cout << std::endl;
	}
	else
		std::cout << "Wrong id number!" << std::endl;

}

void Phonebook::search(void)
{
	std::string	input;

	if (this->id > 0 || this->id_flag == 1)
		printAllContact();
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
			displayContactInfo(atoi(input.c_str()));
	else
		std::cout << "Wrong id number!" << std::endl;
}

