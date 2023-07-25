#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

int errorCheck(string s1, string s2, string s3)
{
	if (s1.empty() || s2.empty() || s3.empty())
	{
		cout << "Argumans cannot be empty" << endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		cout << "Incomplete input entered." << endl;
		return (1);
	}
	string	fileName = av[1];
	string	search = av[2];
	string	replace = av[3];
	string	line;
	string	newLine;
	size_t	pos;

	if (errorCheck(fileName, search, replace))
		return (1);
	// ifstream sadece dosya okuma işlemleri için kullanılan bir sınıftır.
	std::ifstream oldFile(fileName);
	if (!oldFile.is_open())
	{
		cout << "The file could not be opened." << endl;
		return (1);
	}
	fileName = fileName + ".replace";
	// ofstream sadece dosya yazma işlemleri için kullanılan bir sınıftır.
	//std::ios::trunc bayrağı, bu isimde bir dosya varsa içeriğini silip dosyayı boşaltır ve yeniden oluşturur.
	std::ofstream newFile(fileName ,std::ios::trunc);
	if (!newFile.is_open())
	{
		cout << "The file could not be opened." << endl;
		return (1);
	}
	//std::string::npos -> aranan kelime bulunamazsa döndürülen değer. Max size_t değerine eşit.
	while (std::getline(oldFile, line))
	{
		newLine = line;
		while (true)
		{
			pos = newLine.find(search, pos);
			if (pos == std::string::npos)
			{
				newFile << newLine << endl;
				pos = 0;
				break;
			}
			newLine.erase(pos, search.length());
			newLine.insert(pos, replace);
			pos = 0;
		}
	}
}