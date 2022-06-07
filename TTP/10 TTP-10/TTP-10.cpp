#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

void search(string& text)
{
	string str;
	cout << "Введите символ или символы для поиска:" << endl;
	cin.ignore();
	getline(cin, str);

	if (str.size() != 0)
	{
		int total = 0;
		bool find = false;

		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == str[0])
			{
				int repeat = 0;
				while (i + repeat < text.size() && text[i + repeat] == str[repeat])
				{
					repeat++;
					if (repeat == str.size())
					{
						if (str.size() > 1)
						{
							cout << "Начиная с символа с индексом " << i << " до символа с индексом " << i + str.size() - 1
								<< " все символы совпадают." << endl;
						}
						else if (str.size() == 1)
						{
							cout << "Найден элемент " << str[0] << " : в " << "строке с индексом " << i << endl;
						}
						total++;
						find = true;
					}
				}
			}
		}

		cout << "Всего совпадений в строке:" << total << endl << endl;;
		if (!find)
		{
			if (str.size() > 1)
			{
				cout << "Не удалось найти данные символы." << endl;
			}
			else if (str.size() == 1)
			{
				cout << "Не удалось найти данный символ." << endl;
			}
		}
	}
}

void otbor(string& text)
{
	int start, end, flag = 0, n = 0;

	cout << "Введите индекс начала отбора символов: " << endl;

	while (!(cin >> start) || (start < 0) || (start > text.size() - 1))
	{
		if (!cin)
		{
			cout << "Неправильный индекс начала отбора символов!" << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}
		cout << "Неправильный индекс начала отбора символов!" << endl;
		cout << "Введите индекс начала отбора символов: " << endl;
	}

	cout << "Введите индекс конца отбора символов:" << endl;

	while (!(cin >> end) || (end < start) || (end > text.size() - 1))
	{
		if (!cin)
		{
			cout << "Неправильный индекс конца отбора символов!" << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}
		cout << "Неправильный индекс конца отбора символов!" << endl;
		cout << "Введите индекс конца отбора символов:" << endl;
	}

	if (text.size() != 0)
	{
		text.erase(0, start);
		text.erase(end - start + 1, text.size() + start - 1 - end);
	}
	cout << text << endl;
	cout << "Отбор с символа с индексом " << start << " по символ с индексом " << end << " выполнен:" << endl;
}

void replacement(string& text)
{
	istringstream ist(text);
	text = "";
	string word;
	while (ist >> word)
	{
		for (int i = 0; i < word.size(); i++)
		{
			if (islower(word[i]))
			{
				word[i] = toupper(word[i]);
				break;
			}
		}
		text += word;
		text += " ";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	string line;
	int counter_2 = 0;
	bool flag = true;
	vector<string>text;
	while (true)
	{
		cout << "Введите свой текст с клавиатуры:" << endl;
		cout << "Для завершения ввода строк введите Done" << endl;
		getline(cin, line);
		if (line == "Done")
		{
			if (counter_2 == 0)
			{
				cout << "Вы не ввели ни одной строки!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		text.push_back(line);
		counter_2++;
	}

	cout << "Вы ввели нижеприведенные строки:" << endl;
	for (int i = 0; i < text.size(); i++)
	{
		cout << "[" << i << "] " << text[i] << endl;
	}
	double choice;
	double input;
	while (flag)
	{
		cout << "Введите номер строки , с которой хотите работать:" << endl;
		cin >> choice;
		if (choice - int(choice) != 0)
		{
			cout << "Неверный ввод!" << endl;
			cin.ignore();
			continue;
		}
		if (!cin)
		{
			cout << "Неверный ввод!" << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}
		if (choice<0 || choice>text.size() - 1)
		{
			cout << "Вы ввели неправильный индекс!" << endl;
			continue;
		}
		cout << endl << "Выберите необходимое действие : " << endl <<
			"1-Поиск символа (ов)" << endl <<
			"2-Отбор (с N до M символа)" << endl <<
			"3-Замена всех первых строчных букв слов прописными" << endl <<
			"4-Выход" << endl;


		cin >> input;
		if (input - int(input) != 0)
		{
			cout << "Неверный ввод необходимого действия!" << endl;
			continue;
		}
	

		if (input == 1)
		{
			search(text[choice]);
		}
		else if (input == 2)
		{
			otbor(text[choice]);
		}
		else if (input == 3)
		{
			replacement(text[choice]);
		}
		else if (input == 4)
		{
			flag = false;
		}
		else
		{
			cout << "Вы ввели не то число!" << endl;
		}
		cout << endl << "Ваши строки:" << endl;
		for (int i = 0; i < text.size(); i++)
		{
			cout << "[" << i << "] " << text[i] << endl;
		}
	}
	system("pause");
	return 0;
}