#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
		int				id;
		int				id_flag;
	public:
		Phonebook();
		void add(Contact contact);
		void search(void);
		void exit(void);
		void printContact(int flag);
		void rotateId(void);
};

#endif