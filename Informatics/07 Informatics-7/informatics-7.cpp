#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	ifstream vvod("Vvod.txt");
	ofstream vivod("Vivod.txt");
	if (!vvod)
	{
		vivod << "Не удалось считать данные из файла!" << endl;
		return 0;
	}
	int N;
	vvod >> N;
	vivod << "Массив из файла состоит из " << N << " элементов." << endl;
	vvod.seekg(2, ios_base::beg);
	vivod << "Элементы массива:" << endl;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		vvod >> arr[i];
		vivod << arr[i] << " ";
	}

	vivod << endl << endl << "Сортировка массива простым выбором:" << endl;
	int max, maxI, C1 = 0, M1 = 0;
	for (int i = 0; i < N; i++)
	{
		max = 0, maxI = 0;
		for (int j = 0; j < N - i; j++)
		{
			M1++;
			if (max < arr[j])
			{
				max = arr[j];
				maxI = j;
				C1++;
			}
		}
		swap(arr[maxI], arr[N - i - 1]);
		vivod << "Массив после " << i + 1 << " итерации:" << endl;
		for (int k = 0; k < N; k++)
		{
			vivod << arr[k] << " ";
		}
		vivod << endl;

	}
	double C1th = (N - 1)*(N / 2);
	double M1th = (3 + N / 4)*(N - 1);
	vivod << endl;
	vivod << "C1=" << C1 << endl;
	vivod << "M1=" << M1 << endl;
	vivod << "Теоретическое число сравнений (C)=" << C1th << endl;
	vivod << "Теоретическое число пересылок (M)=" << M1th << endl;
	delete[]arr;

	vivod << endl << "Сортировка массива вставками:" << endl;
	ifstream vvod2("Vvod.txt");
	vvod.seekg(2, ios_base::beg);

	int *arr2 = new int[N];
	for (int i = 0; i < N; i++)
	{
		vvod >> arr2[i];
	}
	int C2 = 0, M2 = 0;
	for (int i = 0; i < N; i++)
	{
		M2++;
		for (int j = i; j > 0 && arr2[j - 1] > arr2[j]; j--, C2++)
		{
			swap(arr2[j - 1], arr2[j]);
		}
		vivod << "Массив после " << i + 1 << " итерации:" << endl;
		for (int k = 0; k < N; k++)
		{
			vivod << arr2[k] << " ";
		}
		vivod << endl;
	}

	vivod << endl;
	double Cmin = (N - 2);
	double Cmax = (N + 1)*(N - 2) / 2;
	double Csrd = (Cmin + Cmax) / 2;
	double Mmin = 3 * (N - 2);
	double Mmax = (N + 5)*(N - 2) / 2;
	double Msrd = (Mmin + Mmax) / 2;
	vivod << "C2=" << C2 << endl;
	vivod << "M2=" << M2 << endl;
	vivod << "Теоретическое число сравнений (Cmax)=" << Cmax << endl;
	vivod << "Теоретическое число пересылок (Mmax)=" << Mmax << endl;
	delete[]arr2;

	vivod << endl << "Сортировка массива обменом («пузырьком»):" << endl;
	ifstream vvod3("Vvod.txt");
	vvod.seekg(2, ios_base::beg);

	int *arr3 = new int[N];
	for (int i = 0; i < N; i++)
	{
		vvod >> arr3[i];
	}
	int C3 = 0, M3 = 0;;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr3[j] > arr3[j + 1])
			{
				swap(arr3[j], arr3[j + 1]);
				C3++;
			}
			M3++;
		}
		vivod << "Массив после " << i + 1 << " итерации:" << endl;
		for (int k = 0; k < N; k++)
		{
			vivod << arr3[k] << " ";
		}
		vivod << endl;
	}
	vivod << endl;
	vivod << "C3=" << C3 << endl;
	vivod << "M3=" << M3 << endl;
	double Csrd2 = (N*N) / 4;
	double Msrd2 = 1.5*(N*N) / 4;
	vivod << "Теоретическое число сравнений (Csrd)=" << Csrd2 << endl;
	vivod << "Теоретическое число пересылок (Msrd)=" << Msrd2 << endl;
	delete[]arr3;
}


