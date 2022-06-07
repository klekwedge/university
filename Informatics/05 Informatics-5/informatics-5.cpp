#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	double x, b, n, h, n1, h1, b1, x1, x2, x3;
	n = 0; h = 0; n1 = 0; h1 = 0;
	cout << "Введите x: ";
	cin >> x;
	x1 = x; x2 = x; x3 = x;
	cout << "Введите точность (k): ";
	cin >> k;
	while (x >= 10)
	{
		x /= 10;
		n = n + 1;
	}
	cout << "Последовательность b в двоичной системе: ";
	for (int i = 0; i < k; i++)
	{
		x = x * x;
		if (x < 10)
		{
			b = 0;
			h = (b / pow(2, i + 1)) + h;
			cout << " " << b;
		}
		else
		{
			b = 1;
			x = x / 10;
			h = (b / pow(2, i + 1)) + h;
			cout << " " << b;
		}
	}
	cout << endl;
	double log10x = h + n;
	while (x1 >= 2)
	{
		x1 /= 2;
		n1++;
	}
	cout << "Последовательность b в двоичной системе: ";
	for (int i = 0; i < k; i++)
	{
		x1 = x1 * x1;
		if (x1 < 2) {
			b1 = 0;
			h1 = (b1 / pow(2, i + 1)) + h1;
			cout << " " << b1;
		}
		else {
			b1 = 1;
			x1 = x1 / 2;
			h1 = (b1 / pow(2, i + 1)) + h1;
			cout << " " << b1;
		}
	}
	cout << endl;
	double log2x = n1 + h1;
	cout << "log10x= " << log10x << endl;
	cout << "log2x= " << log2x << endl;
	double lgx = (log(x2)) / (log(10));
	cout << "Машинное вычисление логарифма по основанию 10=";
	cout << lgx << endl;
	double lg2x = (log(x3)) / (log(2));
	cout << "Машинное вычисление логарифма по основанию 2=";
	cout << lg2x << endl;
	double c = abs(lgx - log10x);
	double d = abs(lg2x - log2x);
	cout << "Разность между автоматическим и ручным вычислением логарифма по основанию 10=";
	cout.precision(16);
	cout << c << endl;
	cout << "Разность между автоматическим и ручным вычислением логарифма по основанию 2=";
	cout.precision(16);
	cout << d << endl;
}
