#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include "Error.hpp"
#include <sstream>

class Error;

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void readData(std::string fileName);
		void startExchange(std::string inputFileName);
		void printData();

		class fileException : std::exception
		{
			public:
				const char *what() const throw();
		};

};


#endif