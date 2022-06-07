#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string myNameDll = "Dll1";
	if (!LoadLibraryExA(myNameDll.c_str(), 0, LOAD_LIBRARY_AS_DATAFILE))
	{
		cout << "Ошибка подключения библиотеки динамической компоновки!" << endl;
		return -1;
	}

	HINSTANCE mydll = LoadLibrary(L"Dll1");
	if (mydll == NULL)
	{
		cout << "Внимание! Ошибка библиотеки динамической компоновки!" << endl;
		return -2;
	}

	typedef double(*DllFunсtion)(double, double);
	DllFunсtion myf_math = (DllFunсtion)(GetProcAddress)(mydll, "myf_math");

	typedef double(*DllMyFunction)(double, double, double);
	DllMyFunction myf_1A = (DllMyFunction)(GetProcAddress)(mydll, "myf_3532703_00001");

	typedef const char* (*FName)();
	FName Name = (FName)GetProcAddress(mydll, "FName");

	if (!(mydll && myf_1A && myf_math && Name))
	{
		cout << "Ошибка в библиотеке динамической компоновки!" << endl;
		return -3;
	}

	string nameOfMyPersonalFunction = "ln(x)";
	bool myRestrictionsOnX;
	if (nameOfMyPersonalFunction == Name())
	{
		cout << "Это моя функция:" << Name() << endl;
		myRestrictionsOnX = true;
	}
	else
	{
		cout << "Это не моя функция:" << Name() << endl;
		myRestrictionsOnX = false;
	}

	double start, end, step, eps, parametr;

	cout << "Введите точность эпсилон:" << endl;
	cin >> eps;
	if (eps <= 0)
	{
		cout << "Неправильный ввод эпсилон!";
		return 1;
	}
	cout << "Введите начало промежутка вычисления:" << endl;
	cin >> start;
	cout << "Введите конец промежутка вычисления:" << endl;
	cin >> end;
	if (start > end)
	{
		cout << "Неправильный ввод начала и конца вычисления!";
		return 2;
	}
	cout << "Введите шаг:" << endl;
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
	cout << "Введите параметр a:" << endl;
	cin >> parametr;
	if (parametr <= 0)
	{
		cout << "Неправильный ввод параметра!" << endl;
		return 5;
	}
	cout.setf(ios_base::fixed);
	cout << fixed;
	cout.precision(7);
	string name_of_function = "My ";
	name_of_function += Name();
	cout << "_____________________________________________________________________________________" << endl;
	cout << "|" << setw(20) << "X" << "|" << setw(20) << name_of_function << "|" << setw(20) << Name() << "|" << setw(20) << "Delta" << "|" << endl;
	cout << "_____________________________________________________________________________________" << endl;

	for (double x = start; x <= end + 0.0000000000000001; x += step)
	{
		if (myRestrictionsOnX)
		{
			if (x <= 0 || x > 2)
			{
				cout << "|" << setw(20) << x << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << endl;
				cout << "_____________________________________________________________________________________" << endl;
			}
			else
			{
				double MyFunction = myf_1A(parametr, eps, x);
				double Function = myf_math(parametr, x);

				cout << "|" << setw(20) << x << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction * MyFunction - Function * Function)) << "|" << endl;
				cout << "_____________________________________________________________________________________" << endl;
			}
		}
		else
		{
			double MyFunction = myf_1A(parametr, eps, x);
			double Function = myf_math(parametr, x);
			cout << "|" << setw(20) << x << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction * MyFunction - Function * Function)) << "|" << endl;
			cout << "_____________________________________________________________________________________" << endl;
		}
	}
	double xideal, Function, MyFunction;
	cout << endl << "Введите значение xideal для точного расчета." << endl;
	cin >> xideal;

	eps = 1;
	cout.precision(7);
	cout << "_____________________________________________________________________________________" << endl;
	cout << "|" << setw(20) << "X" << "|" << setw(20) << name_of_function << "|" << setw(20) << Name() << "|" << setw(20) << "Delta" << "|" << endl;
	cout << "_____________________________________________________________________________________" << endl;
	for (int i = 0; i < 7; i++)
	{
		eps *= 0.1;
		if (myRestrictionsOnX)
		{
			if (xideal <= 0 || xideal > 2)
			{
				cout << "|" << setw(20) << xideal << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << setw(20) << "Неверный x" << "|" << endl;
				cout << "_____________________________________________________________________________________" << endl;
			}
			else
			{
				Function = myf_math(parametr, xideal);
				MyFunction = myf_1A(parametr, eps, xideal);
				cout << "|" << setw(20) << eps << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction * MyFunction - Function * Function)) << "|" << endl;
				cout << "_____________________________________________________________________________________" << endl;
			}
		}
		else
		{
			double MyFunction = myf_1A(parametr, eps, xideal);
			double Function = myf_math(parametr, xideal);
			cout << "|" << setw(20) << xideal << "|" << setw(20) << MyFunction << "|" << setw(20) << Function << "|" << setw(20) << sqrt(abs(MyFunction * MyFunction - Function * Function)) << "|" << endl;
			cout << "_____________________________________________________________________________________" << endl;
		}
	}
	return 0;
}