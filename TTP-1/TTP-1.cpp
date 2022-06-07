﻿//В соответствии с персональным вариантом, вычислить значения функции y=F(x) для значений аргумента x, изменяющегося в интервале от Xначальное до Xконечное c шагом ∆x.
//Для вычисления значений использовать собственную функцию, т.е. ввести функцию пользователя F(x).
//Для использования математических функций (синус, косинус, логарифм) необходимо подключить математическую библиотеку (#include “math.h”). из полученных данных сформировать таблицу содержащую столбцы – №п.п; значение аргумента х; значение параметра а; значение аргумента у.

#include <iostream>
#include <math.h>
using namespace std;
double function(double x, double a)
{
	double y;
	y = (0.7) / (1 / x + (log(x) / a));
	return y;
}
int main()
{
	double y, x, a;
	int num, e;
	cout << "Break my programm)" << endl;
	cout << "Enter your number of a " << endl;
	cin >> a;
	if ((a < pow(10, 6) && a > pow(10, -6)) || (a > -1 * pow(10, 6) && a < -1 * pow(10, -6)) || (a == 0))
	{

		cout << "____________________________________________________________" << endl;
		cout << "|Num|x=              |a=              |y=                  |" << endl;
		cout << "|___|________________|________________|____________________|" << endl;

		for (num = 1, x = -14; num < 10, x <= 11; num++, x += 2.5)
		{
			if (x < 0)
			{
				printf("|%3i| %14.6f | %14.6f |        Error       | \n", num, x, a);
			}
			else if (a == 0)
			{
				printf("|%3i| %14.6f | %14.6f |        Error       | \n", num, x, a);

			}
			else
			{
				y = function(x, a);
				printf("|%3i| %14.6f | %14.6f |%20.6f| \n", num, x, a, y);
			}
		}
		cout << "|___|________________|________________|____________________|" << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}

}
