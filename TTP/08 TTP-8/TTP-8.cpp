#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

void insertSort(int* arrBuff, int M, int* arrIndex)
{
	for (int j = 0; j < M; j++)
	{
		bool q = true;
		for (int k = j; k > 0; k--)
		{

			if (arrBuff[k] < arrBuff[k - 1])
			{
				if (q)
				{

					q = false;
				}
				swap(arrBuff[k], arrBuff[k - 1]);
				swap(arrIndex[k], arrIndex[k - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

int coincidence = 0;
void binarySearch(int* arrHash, int left, int right, int requireElement, vector <int>& indexVector, int* arrIndex)
{
	int numOfMiddle = (left + right) / 2;
	int middle = arrHash[numOfMiddle];

	if (middle == requireElement)
	{
		coincidence++;
		indexVector.push_back(arrIndex[numOfMiddle]);
	}

	if (middle >= requireElement && left < numOfMiddle)
	{
		if (left < numOfMiddle - 1)
		{
			binarySearch(arrHash, left, numOfMiddle - 1, requireElement, indexVector, arrIndex);
		}
		else
		{
			if (arrHash[numOfMiddle - 1] == requireElement)
			{
				coincidence++;
				indexVector.push_back(arrIndex[numOfMiddle - 1]);
			}
		}
	}

	if (middle <= requireElement && right > numOfMiddle)
	{
		if (numOfMiddle + 1 < right)
		{
			binarySearch(arrHash, numOfMiddle + 1, right, requireElement, indexVector, arrIndex);
		}
		else
		{
			if (arrHash[numOfMiddle + 1] == requireElement)
			{
				coincidence++;
				indexVector.push_back(arrIndex[numOfMiddle + 1]);
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file, file2;
	string filename;
	cout << "Введите путь к файлу:";
	getline(cin, filename);
	file.open(filename.c_str());
	file2.open(filename.c_str());
	string text;
	int counter = 0;

	while (getline(file, text))
	{
		counter++;
	}

	string* arr = new string[counter];
	string Buff, wordBuff;
	cout << "Список студентов из файла:" << endl;
	cout << "======================================" << endl;
	cout << "|" << setw(4) << "№" << "|" << setw(15) << "Фамилия" << "|" << setw(15) << " Имя" << "|" << endl;;
	cout << "======================================" << endl;
	int number = 0;
	for (int i = 0; i < counter; i++)
	{
		getline(file2, arr[i]);
		Buff = arr[i];
		for (size_t i = 0; i < Buff.size(); i++)
		{
			if (Buff[i] != ' ')
			{
				wordBuff += Buff[i];
				if (i == Buff.size() - 1)
				{
					cout << setw(15) << wordBuff << "|";
					wordBuff = "";
				}
			}
			else
			{
				cout << "|" << setw(4) << number << "|" << setw(15) << wordBuff << "|";
				wordBuff = "";
			}
		}
		number++;
		cout << endl << "======================================" << endl;
	}
	cout << endl << endl;

	int* arrHash = new int [counter] {};

	for (int i = 0; i < counter; i++)
	{
		for (size_t j = 0; j < arr[i].size(); j++)
		{
			arrHash[i] += int(arr[i][j]);

		}
		arrHash[i] %= 10000000000;
	}
	cout << "Список студентов из файла с хэш-кодом:" << endl;
	cout << "======================================================" << endl;
	number = 0;
	for (int i = 0; i < counter; i++)
	{
		Buff = arr[i];
		for (size_t j = 0; j < Buff.size(); j++)
		{
			if (Buff[j] != ' ')
			{
				wordBuff += Buff[j];
				if (j == Buff.size() - 1)
				{
					cout << setw(15) << wordBuff << "|" << setw(15) << arrHash[i] << "|";
					wordBuff = "";
				}
			}
			else
			{
				cout << "|" << setw(4) << number << "|" << setw(15) << wordBuff << "|";
				wordBuff = "";
			}
		}
		number++;
		cout << endl << "======================================================" << endl;
	}


	string searchString;
	cout << endl << endl << "Введите данные для поиска: ";
	getline(cin, searchString);
	int hashOfSearchString = 0;
	for (size_t i = 0; i < searchString.length(); i++)
	{

		hashOfSearchString += int(searchString[i]);
	}
	hashOfSearchString %= 10000000000;
	cout << "Хэш-код введенных данных:" << hashOfSearchString << endl;

	int* arrIndex = new int[counter];

	for (int i = 0; i < counter; i++)
	{
		arrIndex[i] = i;
	}

	insertSort(arrHash, counter, arrIndex);

	vector<int> indexVector;

	binarySearch(arrHash, 0, counter - 1, hashOfSearchString, indexVector, arrIndex);

	cout << endl;


	if (coincidence != 0)
	{
		cout << "Найдено совпадений:" << indexVector.size() << endl;
		cout << "Найденные элементы:" << endl;
		for (size_t i = 0; i < indexVector.size(); i++)
		{
			cout << arr[indexVector[i]] << endl;
		}
		cout << endl << "Выполним проверку для того , чтобы убедиться , что это введеный элемент." << endl;

		for (size_t i = 0; i < indexVector.size(); i++)
		{
			int numberOfMatchedItems = 0;
			if (size(arr[indexVector[i]]) == size(searchString))
			{
				for (size_t j = 0; j < size(searchString); j++)
				{
					if ((arr[indexVector[i]][j]) == searchString[j])
					{
						numberOfMatchedItems;

					}
					else
					{
						cout << "Элемент " << arr[indexVector[i]] << " и введенный элемент " << searchString << " не совпадают!" << endl;
						coincidence--;
						break;
					}
				}
			}
			else
			{
				cout << "Элемент " << arr[indexVector[i]] << " и введенный элемент " << searchString << " не совпадают!" << endl;
				coincidence--;
			}

			if (numberOfMatchedItems == size(searchString))
			{
				cout << "Элемент " << arr[indexVector[i]] << " и введенный элемент " << searchString << " совпадают!" << endl;
			}
		}
	}

	cout << "В итоге реальных совпадений:" << coincidence << endl;
	if (coincidence == 0)
	{
		cout << "Ни найдено ни одного совпадения!" << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}