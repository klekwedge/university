//В соответствии с индивидуальным вариантом написать и выполнить программу: 
//Задан текст. Вычислить количество слов в нем и распечатать эти слова (по одному в строке).

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <windows.h>
#include <experimental/filesystem>
using namespace std;
using namespace std::experimental::filesystem;
int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file;
	string filename;
	cout << "Enter the path to the file: ";
	getline(cin, filename);
	if (!is_regular_file(filename))
	{
		cout << "Wrong file path.Please try again.";
		return 999;
	}
	file.open(filename.c_str());
	string text;
	getline(file, text);
	if (text.empty())
	{
		cout << "You need a file that will import text into the program!";
	}
	else
	{
		cout << endl << "Your text: " << text << endl << endl;
		istringstream ist(text);
		int word = 0;
		while (ist >> text)
		{
			if (text.find_first_not_of("01234/56789!@#$%^&*();%:?*\\.><,`~'{[]}|-=+"))
			{
				continue;
			}
			else
			{
				word++;
				cout << text << endl;
			}
		}
		cout << endl << word++ << " words." << endl;
	}
}