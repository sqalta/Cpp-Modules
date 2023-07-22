#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
		int				id_flag;
		int				id;
	public:
		Phonebook();
		void add(Contact contact);
		void search(void);
		void exit(void);
		void printAllContact(void);
		void displayContactInfo(int contactId);
};

#endif