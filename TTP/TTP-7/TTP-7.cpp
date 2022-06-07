#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int coincidence = 0;
void binarySearch(int** arr, int left, int right, int requireElement, int i)
{
	int numOfMiddle = (left + right) / 2;
	int middle = arr[i][numOfMiddle];

	if (middle == requireElement)
	{
		coincidence++;
	}

	if (middle >= requireElement && left < numOfMiddle)
	{
		if (left < numOfMiddle - 1)
		{
			binarySearch(arr, left, numOfMiddle - 1, requireElement,i);
		}
		else
		{
			if (arr[i][numOfMiddle - 1] == requireElement)
			{
				coincidence++;
			}
		}
	}

	if (middle <= requireElement && right > numOfMiddle)
	{
		if (numOfMiddle + 1 < right)
		{
			binarySearch(arr, numOfMiddle + 1, right, requireElement, i);
		}
		else
		{
			if (arr[i][numOfMiddle + 1] == requireElement)
			{
				coincidence++;
			}
		}
	}
}



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, ("rus"));
	int M, N, size;
	cout << "Введите количество строк:";
	cin >> M;

	cout << "Введите количество столбцов:";
	cin >> N;

	if ((N < 1 && M < 1) || (N < 1 || M < 1))
	{
		cout << "Ошибка!Введен неверный размер массива!" << endl;
		return 1;
	}

	int** arr = new int* [M];
	for (int i = 0; i < M; i++)
	{
		arr[i] = new int[N];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 10;
			cout << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Введите количество элементов последовательности:" << endl;
	cin >> size;

	if (size > N)
	{
		cout << "Ошибка! Количество элементов последовательности не может быть больше размеров строки!" << endl;
		return 2;
	}
	if (size <= 0)
	{
		cout << "Ошибка! Количество элементов последовательности не может быть меньше или равно 0!" << endl;
		return 3;
	}

	if (size > 1)
	{
		cout << "Введите последовательность элементов:" << endl;
	}
	else if (size == 1)
	{
		cout << "Введите элемент:" << endl;
	}
	int* arrBuff = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arrBuff[i];
	}



	cout << "=======================" << endl << "Последовательный поиск:" << endl <<
		"=======================" << endl;

	int total = 0;

	bool find = false;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == arrBuff[0])
			{
				int repeat = 0;
				while (j + repeat < N && arr[i][j + repeat] == arrBuff[repeat])
				{
					repeat++;
					if (repeat == size)
					{
						if (size > 1)
						{
							cout << "Начиная со строки с индексом " << i + 1 << " и стоблца с индексом " << j + 1 << " элементы массива найдены." << endl
								<< "Все элементы последовательности совпадают." << endl;
						}
						else if (size == 1)
						{
							cout << "Найден элемент " << arrBuff[0] << " : в " << "строке с индексом " << i + 1 << " и в  столбце с индексом " << j + 1 << endl;
						}
						total++;
						find = true;
					}
				}

			}
		}
	}

	cout << endl << "Всего совпадений в последовательном поиске:" << total << endl << endl;;
	if (!find)
	{
		if (size > 1)
		{
			cout << "Не удалось найти данную последовательность." << endl;
		}
		else if (size == 1)
		{
			cout << "Не удалось найти данное число." << endl;
		}
	}


	cout << endl << endl << "Отсортированный массив по возрастанию:" << endl;
	int min, minI;
	for (int i = 0; i < M; i++)
	{
		for (int l = 0; l < N; l++)
		{
			min = arr[i][0], minI = 0;
			for (int j = 0; j < N - l; j++)
			{
				if (min < arr[i][j])
				{
					min = arr[i][j];
					minI = j;
				}
			}
			swap(arr[i][minI], arr[i][N - l - 1]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl << "===============" << endl << "Бинарный поиск:" << endl << "==============="
		<< endl << endl;

	cout << endl;
	if (size > 1)
	{
		cout << "Поиск первого элемента, который был введен:" << arrBuff[0] << endl;
	}
	else if (size == 1)
	{
		cout << "Поиск элемента, который был введен:" << arrBuff[0] << endl;
	}

	for (int i = 0; i < M; i++)
	{
		binarySearch(arr, 0, N - 1, arrBuff[0],i);
	}

	cout << endl << "Всего совпадений в бинарном поиске:" << coincidence << endl << endl;
	if (coincidence == 0)
	{
		cout << "В отсортированном массиве нет такого числа!" << endl;
	}
	return 0;
}