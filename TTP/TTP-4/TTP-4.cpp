#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double Foo(double x, double eps)
{
	int n = 1;
	double lnx = 0;
	double fnThis = (x - 1);
	double fnNext, k;
	lnx += fnThis;
	while (abs(fnThis) > eps)
	{
		k = (x - 1)*n / (n + 1)*(-1);
		fnNext = fnThis * k;
		fnThis = fnNext;
		lnx += fnThis;
		n++;
	}
	return lnx;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double start, end, step, eps;
	cout << "Введите точность эпсилон." << endl;
	cin >> eps;
	if (eps <= 0)
	{
		cout << "Неправильный ввод эпсилон!";
		return 1;
	}
	cout << "Введите начало промежутка вычисления." << endl;
	cin >> start;
	cout << "Введите конец промежутка вычисления." << endl;
	cin >> end;
	if (start > end)
	{
		cout << "Неправильный ввод начала и конца вычисления!";
		return 2;
	}
	cout << "Введите шаг." << endl;
	cin >> step;
	if (step <= 0)
	{
		cout << "Неправильный ввод шага!";
		return 3;
	}
	if (step > (end - start))
	{
		cout << "Неправильный ввод шага!";
		return 4;
	}
	cout.setf(ios_base::fixed);
	cout << fixed;
	cout.precision(7);
	cout << "_____________________________________________________________________________________" << endl;
	cout << "|" << setw(20) << "X" << "|" << setw(20) << "MyFunctiontion(x)" << "|" << setw(20) << "Function(x)" << "|" << setw(20) << "Delta" << "|" << endl;
	cout << "_____________________________________________________________________________________" << endl;

	for (double x = start; x <= end + 0.0000000000000001; x += step)
	{
		if (x <= 0 || x > 2)
		{
			cout << "|" << setw(20) << x << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << endl;
			cout << "_____________________________________________________________________________________" << endl;
		}
		else
		{
			double MyFunction = Foo(x, eps);
			double Function = log(x);
			cout << "|" << setw(20) << x << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction*MyFunction - Function * Function)) << "|" << endl;
			cout << "_____________________________________________________________________________________" << endl;
		}
	}
	double xideal, Function, MyFunction;
	cout << endl << "Введите значение xideal для точного расчета." << endl;
	cin >> xideal;
	if (xideal <= 0 || xideal > 2)
	{
		cout << "Неверный ввод xideal!" << endl;
		return 5;
	}
	eps = 1;
	cout.precision(7);
	cout << "_____________________________________________________________________________________" << endl;
	cout << "|" << setw(20) << "Eps" << "|" << setw(20) << "MyFunctiontion(x)" << "|" << setw(20) << "Function(x)" << "|" << setw(20) << "Delta" << "|" << endl;
	cout << "_____________________________________________________________________________________" << endl;
	for (int i = 0; i < 7; i++)
	{
		eps *= 0.1;
		MyFunction = Foo(xideal, eps);
		Function = log(xideal);
		cout << "|" << setw(20) << eps << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction*MyFunction - Function * Function)) << "|" << endl;
		cout << "_____________________________________________________________________________________" << endl;
	}
	return 0;
}