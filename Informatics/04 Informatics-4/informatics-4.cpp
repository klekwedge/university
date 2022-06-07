#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
int step1 = 0;
ofstream vivod("result.txt");
void Eratosthenes(bool massiv[], int Sieve)
{
	int i, j;
	for (j = 2; j <= Sieve; j++) massiv[j] = true;
	j = 2;
	while (j*j <= Sieve)
	{
		i = j * j;
		if (massiv[j])
			while (i <= Sieve)
			{
				massiv[i] = false;
				i = i + j;
			}
		j = j + 1;
	}

	for (j = 2; j <= Sieve; j++)
	{
		if (massiv[j] == true)
		{
			vivod << j << endl;
		}
	}
}

int nod(int A, int B)
{
	int k = 1;
	while ((A != 0) && (B != 0))
	{

		while ((A % 2 == 0) && (B % 2 == 0))
		{
			A /= 2;
			B /= 2;
			k *= 2;
		}
		while (A % 2 == 0)
		{
			A /= 2;
		}
		while (B % 2 == 0)
		{
			B /= 2;
		}
		if (A >= B)
		{
			A -= B;
			step1++;
		}
		else
		{ 
			B -= A;
			step1++;
		}
	}
	return B * k;
}

int nok(int n1, int n2)
{
	return (n1 * n2) / nod(n1, n2);
}


int main()
{
	int a, b, c, d, e;
	int MAX;
	setlocale(LC_ALL, "Rus");
	ifstream vvod("data.txt");
	vvod >> a >> b >> c >> d >> e;
	nod(a, b); nod(c, d); nod(nod(a, b), nod(c, d)); nod(e, nod(nod(a, b), nod(c, d)));
	vivod << "Наибольший общий делитель всех пяти чисел(" << a << " " << b << " " << c << " " << d << " " << e << ")" << "=" << nod(e, nod(nod(a, b), nod(c, d))) << endl;
	vivod <<"Количество шагов в бинарном алгоритме Евклида=" << step1/2<< endl;
	vivod << "Оценка="<< step1 / 2+1 << endl;
	vivod << "Количество шагов меньше,чем оценка.(" << step1 / 2 << "<" << step1 / 2+1 <<")"<< endl;
	int arr[5]{ a,b,c,d,e };
	MAX = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (MAX < arr[i])
		{
			MAX = arr[i];
		}
	}
	vivod << "Наибольшое число m=" << MAX << endl;

	double m = MAX / 2;
	vivod << "m/2= " << m << endl;
	int delta = abs(m - arr[0]);
	int xdelta = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (delta > abs(m - arr[i]))
		{
			delta = abs(m - arr[i]);
			xdelta = arr[i];
		}
	}
	vivod << "Ближайшее число из файла к m/2=" << xdelta << endl;
	vivod << "Квадратный корень из " << MAX << "=" << pow(MAX, 0.5) << endl;
	vivod << "Корень из " << MAX << " больше,чем количество шагов в алгоритме Решето Эратосфена на 1" << endl;
	nok(MAX, xdelta);
	vivod << "Наименьшее общее кратное чисел " << xdelta << " и " << MAX << "=" << nok(MAX, xdelta) << endl<<endl;
	int Sieve = e;
	bool *massiv = new bool[Sieve];
	vivod << "Простые числа от 1 до " << MAX << ". Решето Эратосфена:" << endl;
	Eratosthenes(massiv, Sieve);
	vivod << endl;
	cout << "Здравствуйте)Все Ваши данные уже давным-давно посчитались)Загляните в файл)" << endl;
	
}
