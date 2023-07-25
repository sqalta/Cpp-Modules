#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain(std::string level);
};

// funcArray isminde bir işaretci türü tanımlamayı sağlar. Ve bu tür Harl sınıfına ait metotlara işaret edebilir.
typedef void (Harl::*funcArray) (void);

#endif