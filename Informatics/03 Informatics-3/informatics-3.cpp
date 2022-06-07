#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double function(double x, double a)
{
	double y;
	y = a * log((2 * x + 1) / (x - 1));
	return y;
}
int main()
{
	
	ofstream os("result.txt");
	setlocale(LC_ALL, "Rus");
	double y, x, a;
	double step, start_of_range, end_of_range;
	cout << "При вводе переменной x учитывайте , что x может принимать значения от (-inf,-0.5)U(1,+inf)" << endl
		<< "Введите значение x: ";
	cin >> x;
	if (x >= -0.5 && x <= 1)
	{
		cout << "Переменная x не может принимать данное значение" << endl;
		return x == 0;
	}
	cout << endl << "Введите шаг для переменной x: ";
	cin >> step;
	cout << endl << "Введите параматер a: ";
	cin >> a;
	if (a == 0)
	{
		cout << "y = 0" << endl;
		return a == 0;
	}
	cout << endl << "Введите диапазон значений для переменной x." << endl
		<< "Пожалуйста, учитывайте , что переменная x может принимать значения от (-inf,-0.5)U(1,+inf)" << endl;
	cout << endl << "Введите начало диапазона:";
	cin >> start_of_range;
	cout << endl << "Введите конец диапазона:";
	cin >> end_of_range;
	if (start_of_range > end_of_range || start_of_range == end_of_range)
	{
		cout << "Вы ввели неправильный диапазон!" << endl;
	}
	if (x <= start_of_range || x >= end_of_range)
	{
		cout << "Переменная x не попадает в заданный диапазон!";
		return x == 0;
	}

	cout << endl << "X" << "\t" << "Y" << endl;
	os << "X" << "\t" << "Y" << endl;
	
	for (x = x; start_of_range < x && x < end_of_range; x += step)
	{
		if (x >= -0.5&&x <= 1)
		{
			cout << x << "\t" << "-" << endl;
			os << x << "\t" << "-" << endl;
			continue;
		}
		y = function(x, a);
		cout << x << "\t" << y << endl;
		os << x << "\t" << y << endl;

	}
	
}
