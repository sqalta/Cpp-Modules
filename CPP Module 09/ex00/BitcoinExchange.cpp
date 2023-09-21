#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
};

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Bitcoin Exchange destructor called." << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->data = copy.data;
	return *this;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->data = copy.data;
};

const char *BitcoinExchange::fileException::what() const throw()
{
	return "Error: Failed to open the file. ";
};

void appendLine(std::map<std::string, float> &data, std::string line)
{
	std::pair<std::string, float> newLine;

	newLine.first = line.substr(0, line.find(","));
	newLine.second = std::stof(line.substr(line.find(",") + 1));
	data.insert(newLine);
}

void BitcoinExchange::readData(std::string fileName)
{
	std::ifstream file;

	file.open(fileName);

	if (file.fail())
	{
		Error::fileError();
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		appendLine(this->data, line);
	}
	file.close();
};

void BitcoinExchange::printData()
{
	for(std::map<std::string, float>::iterator a = this->data.begin(); a != this->data.end(); a++)
	{
		std::cout << a->first << " ";
		std::cout << a->second << std::endl;
	}
}

int getMonthDays(int year, int month)
{
    if (month < 1 || month > 12)
        return -1;
    if (month == 2)
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
		else
        	return 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

int checkDate(std::string &date, std::string &line)
{
	for (int i = 0; date[i]; i++)
	{
		if ((i == 4 || i == 7))
		{
			if (!(date[i] == '-'))
				return Error::badInputError(line);
			if (!date[++i])
				break;
		}
		if(!std::isdigit(date[i]))
			return Error::badInputError(line);
	}
	int year = std::stoi(date.substr(0,4));
	int month = std::stoi(date.substr(5,2));
	int day	= std::stoi(date.substr(8,2));
	int monthDay = getMonthDays(year, month);
	if (monthDay == -1)
		return Error::badInputError(line);
	if (day > monthDay || day <= 0)
		return Error::badInputError(line);
	return 0;
}

std::string trim(const std::string& str, const std::string& trim)
{
    size_t first = str.find_first_not_of(trim);
    size_t last = str.find_last_not_of(trim);

    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }

    return str.substr(first, last - first + 1);
}

int checkValue(std::string &value, std::string &line)
{
	value = trim(value, "0");
	try
	{
		float fValue = std::stof(value);
		std::stringstream ss;
		ss << fValue;
		if ((ss.str().length() != value.length()))
		{
			for (int i = 0; value[i]; i++)
			{
				if (i == 0 && value[i] == '-')
					continue;
				if (!std::isdigit(value[i]))
				{
					return Error::badInputError(line);
					return 1;
				}
			}
			return Error::tooLargeNumber();
		}
		if (fValue < 0)
			return Error::negativeNumberError();
		if (fValue > 1000)
			return Error::tooLargeNumber();
		return 0;
	}
	catch(const std::exception& e)
	{
		return Error::badInputError(line);
	}
	return 0;
}


int checkLine(std::string &line)
{
	if (line.find("|") == std::string::npos)
		return Error::badInputError(line);
	std::string date = line.substr(0, line.find("|"));
	std::string value = line.substr(line.find("|") + 1);
	date = trim(date, " \t\n\r");
	value = trim(value, " \t\n\r");
	if (checkDate(date, line))
		return 1;
	if (checkValue(value, line))
		return 1;
	return 0;
}
//üst tarihe ayarlanmadı!!!!!!!
std::map<std::string, float>::iterator findTrueDate(std::string &line, std::map<std::string, float> data)
{
	std::map<std::string, float>::iterator trueDate;
	int min = std::numeric_limits<int>::max();
	int diff;
	for (std::map<std::string, float>::iterator a = data.begin(); a != data.end(); a++)
	{
		diff = std::atoi(a->first.substr(0,4).c_str()) - std::atoi(line.substr(0,4).c_str());
		if (diff < min)
		{
			min = diff;
			trueDate = a;
		}
	}
	min = std::numeric_limits<int>::max();
	for (std::map<std::string, float>::iterator a = trueDate;
				!std::strcmp(a->first.substr(0,4).c_str(), trueDate->first.substr(0,4).c_str()); a++)
	{
		diff = std::strcmp(a->first.substr(5,2).c_str(), line.substr(5,2).c_str());
		if (diff < min)
		{
			min = diff;
			trueDate = a;
		}
	}
	for (std::map<std::string, float>::iterator a = trueDate;
				!std::strcmp(a->first.substr(5,2).c_str(), trueDate->first.substr(5,2).c_str()); a++)
	{
		diff = std::strcmp(a->first.substr(8,2).c_str(), line.substr(8,2).c_str());
		if (diff < min)
		{
			min = diff;
			trueDate = a;
		}
	}
	return trueDate;
}

void calculateExchange(std::string &line, std::map<std::string, float> data)
{
	getchar();
	std::cout << findTrueDate(line, data)->first << std::endl;
	exit (1);
}

void BitcoinExchange::startExchange(std::string inputFileName)
{
	std::ifstream file;

	file.open(inputFileName);
	if (file.fail())
		Error::fileError();
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		Error::firstLineError();
	while (std::getline(file, line))
	{
		if(checkLine(line))
			continue;
		calculateExchange(line, this->data);
	}
}