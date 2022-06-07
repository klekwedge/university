//В соответствии с вариантом написать и выполнить программу: 
//Задан двумерный массив А из N строк и М столбцов. Сфоpмиpовать одномеpный массив В из отpицательных элементов массива А
//Выполнить соpтиpовку массива В в поpядке неубывания.
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(console, &start_attribute);

	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	double N, M, o;
	cout << "Введите количество колонок (N) и строк (M) для двумерного массива A:" << endl << "N=";
	cin >> N;
	if (N <= 0)
	{
		cout << "Число колонок должно быть больше 0!" << endl;
		return N = 0;
	}
	if (modf(N, &o) != 0)
	{
		cout << "Число колонок не может быть дробным!" << endl;
		return N = 0;
	}

	cout << "M=";
	cin >> M;

	if (modf(M, &o) != 0)
	{
		cout << "Число строк не может быть дробным!" << endl;
		return M = 0;
	}

	if (N < 1 || M < 1 || (N < 1 && M < 1))
	{
		return 0;
	}
	cout << endl << "Массив A:" << endl;

	int** arrA = new int*[N];
	int run = 0;
	int positive = 0;
	for (int i = 0; i < N; i++)
	{
		arrA[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			arrA[i][j] = rand() % 1000 - 500;
			if (arrA[i][j] <= 0)
			{
				SetConsoleTextAttribute(console, FOREGROUND_RED);
				run++;
			}
			else
			{
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
				positive++;
			}
			cout << setw(4) << arrA[i][j] << ' ';
		}
		cout << endl;
	}
	SetConsoleTextAttribute(console, start_attribute.wAttributes);
	cout << "Массив A из положительных элементов:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);

	int *arrA0 = new int[positive];
	int z = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arrA[i][j] > 0)
			{
				arrA0[z] = arrA[i][j];
				cout <<setw(3)<< arrA0[z] <<" ";
				z++;
			}
		}
	}
	SetConsoleTextAttribute(console, start_attribute.wAttributes);

	int* arrB = new int[run];
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arrA[i][j] < 0)
			{
				arrB[n] = arrA[i][j];
				n++;
			}
		}
	}
	delete[]arrA;
	for (int i = 0; i < run; i++)
	{
		for (int j = i; j > 0 && arrB[j - 1] > arrB[j]; j--)
		{
			swap(arrB[j - 1], arrB[j]);
		}
	}



	SetConsoleTextAttribute(console, start_attribute.wAttributes);
	cout << endl << "Массив B из отpицательных элементов массива А в поpядке неубывания(возрастания):" << endl;
	for (int i = 0; i < run; i++)
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		cout << arrB[i] << " ";
	}
	cout << endl;
	SetConsoleTextAttribute(console, start_attribute.wAttributes);
	return 0;
}