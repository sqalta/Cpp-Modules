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
		std::map<int, std::pair<std::string, float> > dataDay;
		std::string inputDate;
		float		inputValue;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void readData(std::string fileName);
		void startExchange(std::string inputFileName);
		int checkLine(std::string &line);
		void calculateExchange(std::map<int, std::pair<std::string, float> > dataDay);
		void printData();

		class fileException : std::exception
		{
			public:
				const char *what() const throw();
		};

};


#endif