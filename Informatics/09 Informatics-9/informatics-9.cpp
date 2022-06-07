#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int N, k;
	cout <<"Введите количество этажей." << endl;
	cin >> N;
	if (N <= 0)
	{
		cout << "Количество этажей должно быть >=1." << endl;
		return 1;
	}

	cout << "Введите этаж, начиная с которого шарики начинают разбиваться." << endl;
	cin >> k;
	if (k <= 0)
	{
		cout << "Этаж, начиная с коротого шарики начинают разбиваться должно быть >=1." << endl;
		return 2;
	}
	if (k > N)
	{
		cout << "Шарики не сломаются!" << endl;
		return 3;
	}
	double n;
	n = (-1 + sqrt(8 * N + 1)) / 2;
	cout << endl << "n=" << n << endl;
	cout << "Округляем в большую сторону)" << endl;
	n = ceil(n);
	cout << endl << "n=" << n << endl << endl;

	int j = 0;
	int b1state = 1;
	int o;
	int i = n;
	int status;
	for (o = 1; o <= n; o++)
	{
		j++;
		if (k > i)
		{
			cout << "Шаг " << o;
			if (b1state == 1)
			{
				cout << " Шар №1" << " " << " этаж " << i << " не разбился." << endl;
				i += n - j;
			
			}
			else if (b1state == 0)
			{
				cout << " Шар №2" << " " << " этаж " << i << " не разбился." << endl;
				i += 1;
			}
		}
		else if (k <= i)
		{
			cout << "Шаг " << o;
			if (b1state == 1)
			{
				cout << " Шар №1" << " " << " этаж " << i << " разбился." << endl;
				b1state = 0;
				i -= n - j;
			}
			else
			{
				cout << " Шар №2" << " " << " этаж " << i << " разбился." << endl;
				break;
			}
		}
		cout << endl;
	}
	cout << endl << "Всего шагов:" << o << endl;
	cout << "Шары разбиваются на " << k << " этаже." << endl;
	return 0;
}





