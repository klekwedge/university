#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int m, n, x, y, P, o = 1, Randnum;
	cout << "Введите размер m (строки)." << endl;
	cin >> m;
	cout << "Введите размер n (колонки)." << endl;
	cin >> n;
	if ((m == 1 && n == 1) || (m == 1 || n == 1))
	{
		cout << "Размер массива не может быть таким!" << endl;
		return 1;
	}
	cout << "Введите x." << endl;
	cin >> x;
	cout << "Введите y." << endl;
	cin >> y;
	if ((x == 0 || y == 0) || (x == 0 && y == 0) || (x > n || y > m) || (x > n&&y > m))
	{
		cout << "Вы ввели неправильное значение x и y!" << endl;
		return 2;
	}
	x--;
	y--;
	cout << "Введите вероятность размножения бактерий (P)." << endl;
	cin >> P;
	if (P == 0)
	{
		cout << "Матрица не заполнится бактериями,так как вероятность равна нулю!Помимо этого, будет бесконечное количество итераций!" << endl;
		return 3;
	}
	else if (P < 1 && P > 100)
	{
		return 4;
	}
	int **arr = new int *[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == y && j == x)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = 0;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int value = 0;


	srand(time(NULL));
	for (int k = 0; k < 2000; k++)
	{
		Randnum = rand() % 100 + 1;
		cout << endl << "||||||||||\\" << Randnum << endl;
		if (Randnum == 100)
		{
			break;
		}
	}
}

