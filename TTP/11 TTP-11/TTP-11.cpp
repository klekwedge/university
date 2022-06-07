#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;
void bubbleSort(int** arrBuff, int M, int N, int* C1, int* M1)
{
	int** arr1 = new int* [M];
	for (int i = 0; i < M; i++)
	{
		arr1[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr1[i][j] = arrBuff[i][j];
		}
	}

	int count;
	for (int i = 0; i < M; i++)
	{

		for (int n = 0; n < N - 1; n++)
		{
			count = (*M1);
			for (int j = 0; j < N - 1 - n; j++)
			{
				(*C1)++;
				if (arr1[i][j] < arr1[i][j + 1])
				{
					swap(arr1[i][j], arr1[i][j + 1]);
					(*M1)++;
				}

			}

			if (count == (*M1))
			{
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		delete[] arr1[i];
	}
	delete arr1;
	arr1 = nullptr;
}

void selectionSort(int** arrBuff, int M, int N, int* C2, int* M2)
{
	int** arr2 = new int* [M];
	for (int i = 0; i < M; i++)
	{
		arr2[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr2[i][j] = arrBuff[i][j];
		}
	}

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N - 1; j++) {

			int max = j;

			for (int n = j + 1; n < N; n++)
			{
				(*C2)++;

				if (arr2[i][n] > arr2[i][max])
				{
					max = n;
				}
			}

			if ((max != j) && (arr2[i][j] != arr2[i][max]))
			{
				swap(arr2[i][j], arr2[i][max]);
				(*M2)++;
			}
		}

	}

	for (int i = 0; i < M; i++)
	{
		delete[] arr2[i];
	}
	delete arr2;
	arr2 = nullptr;
}

void insertSort(int** arrBuff, int M, int N, int* C3, int* M3)
{
	int** arr3 = new int* [M];
	for (int i = 0; i < M; i++)
	{
		arr3[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr3[i][j] = arrBuff[i][j];
		}
	}



	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool q = true;
			for (int k = j; k > 0; k--)
			{
				if (N > 1)
				{
					(*C3)++;
				}
				if (arr3[i][k] > arr3[i][k - 1])
				{
					if (q)
					{
						(*M3)++;
						q = false;
					}
					swap(arr3[i][k], arr3[i][k - 1]);

				}
				else
				{
					break;
				}
			}
		}
	}
	if (N == 2)
	{
		(*C3) = 1 * M;
	}

	for (int i = 0; i < M; i++)
	{
		delete[] arr3[i];
	}
	delete arr3;
	arr3 = nullptr;

}


void ShellSort(int** arrBuff, int M, int N, int* C4, int* M4)
{
	int** arr4 = new int* [M];
	for (int i = 0; i < M; i++)
	{
		arr4[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr4[i][j] = arrBuff[i][j];
		}
	}


	int  d, x;
	int k = 1, count = 0;
	while (k <= N)
	{

		if (k == 1)
		{
			k *= 2;
			k++;
		}
		else
		{
			k *= 2;
			k--;
		}
		count++;
	}
	if (k > N)
	{
		k /= 2;
		if (k > 1)
		{
			k++;
		}
		count--;
	}


	int countBuff = count;
	for (int n = 0; n < M; n++)
	{
		count = countBuff;
		for (int k = 0; k <= countBuff; k++)
		{

			d = pow(2, count) + 1;

			if (d == 2)
			{
				d--;
			}
			for (int i = d; i < N; i++)
			{
				x = arr4[n][i];
				(*C4)++;
				for (int j = i - d; j >= 0 && x > arr4[n][j]; j -= d)
				{
					arr4[n][j + d] = arr4[n][j];
					arr4[n][j] = x;
					(*M4)++;
				}

			}
			count--;
		}
	}


	for (int i = 0; i < M; i++)
	{
		delete[] arr4[i];
	}
	delete arr4;
	arr4 = nullptr;
}

int C5;
int M5;

void quickSort(int** arr, int levy, int pravy, int i)
{
	int l = levy, p = pravy;
	int pivot, middle = (l + p) / 2;
	pivot = arr[i][middle];

	if (pravy - levy == 1)
	{
		C5++;
		if (arr[i][pravy] > arr[i][levy])
		{
			swap(arr[i][pravy], arr[i][levy]);
			M5++;
		}

	}
	else
	{
		while (l <= p)
		{
			while (arr[i][l] > pivot)
			{
				if (pivot != l)
				{
					C5++;

				}
				l++;
			}

			while (arr[i][p] < pivot)
			{
				if (pivot != p)
				{
					C5++;
				}
				p--;
			}
			C5++;

			if (l <= p)
			{
				if (l != p)
				{
					if (arr[i][l] < arr[i][p])
					{
						swap(arr[i][l], arr[i][p]);

						M5++;

					}
				}
				l++;
				p--;
			}

			else if (l <= p)
			{
				if (arr[i][l] == arr[i][p])
				{
					l++;
				}
				p--;
			}

		}

		if (levy < p) quickSort(arr, levy, p, i);
		if (l < pravy) quickSort(arr, l, pravy, i);
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int M;
	vector<int> cVector;
	vector<int> mVector;
	int C1, M1;




	for (int l = 0; l < 7; l++)
	{

		int I = l + 1;
		M = 30 * I * 1 * 1;
		cout << M << endl;
		int** arr = new int* [M];
		for (int i = 0; i < M; i++)
		{
			arr[i] = new int[M];
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				arr[i][j] = rand() % 21 - 10;
			}
		}

		C1 = 0, M1 = 0;
		bubbleSort(arr, M, M, &C1, &M1);
		cVector.push_back(C1);
		mVector.push_back(M1);
		C1 = 0, M1 = 0;
		selectionSort(arr, M, M, &C1, &M1);
		cVector.push_back(C1);
		mVector.push_back(M1);
		C1 = 0, M1 = 0;
		insertSort(arr, M, M, &C1, &M1);
		cVector.push_back(C1);
		mVector.push_back(M1);
		C1 = 0, M1 = 0;
		ShellSort(arr, M, M, &C1, &M1);
		cVector.push_back(C1);
		mVector.push_back(M1);
		C5 = 0, M5 = 0;
		for (int n = 0; n < M; n++)
		{
			quickSort(arr, 0, M - 1, n);
		}
		cVector.push_back(C5);
		mVector.push_back(M5);

		for (int i = 0; i < M; i++)
		{
			delete[] arr[i];
		}
		delete arr;
		arr = nullptr;
	}
	int k = 0;
	for (int j = 0; j < 7; j++)
	{
		cout.setf(ios::left);
		cout << "-------------------------------------------------------------------" << endl <<
			"|" << setw(2) << "I" << "|" << setw(20) << "Название сортировки:" << "|" << setw(20) << "Количество сравнений" << "|" <<
			setw(20) << "Количество пересылок" << "|" << endl << "-------------------------------------------------------------------" << endl;
		cout << "|" << setw(2) << j + 1 << "|" << setw(20) << "Сортировка пузырьком" << "|" << setw(20) << cVector[k] << "|" << setw(20) << mVector[k] << "|" << endl <<
			"-------------------------------------------------------------------" << endl;
		k++;
		cout << "|" << setw(2) << j + 1 << "|" << setw(20) << "Сортировка выбором" << "|" << setw(20) << cVector[k] << "|" << setw(20) << mVector[k] << "|" << endl <<
			"-------------------------------------------------------------------" << endl;
		k++;
		cout << "|" << setw(2) << j + 1 << "|" << setw(20) << "Сортировка вставками" << "|" << setw(20) << cVector[k] << "|" << setw(20) << mVector[k] << "|" << endl <<
			"-------------------------------------------------------------------" << endl;
		k++;
		cout << "|" << setw(2) << j + 1 << "|" << setw(20) << "Сортировка Шелла" << "|" << setw(20) << cVector[k] << "|" << setw(20) << mVector[k] << "|" << endl <<
			"-------------------------------------------------------------------" << endl;
		k++;
		cout << "|" << setw(2) << j + 1 << "|" << setw(20) << "Быстрая сортировка" << "|" << setw(20) << cVector[k] << "|" << setw(20) << mVector[k] << "|" << endl <<
			"-------------------------------------------------------------------" << endl << endl;
		k++;
	}
	return 0;
}