#include <iostream>
#include <ctime>
using namespace std;
int s1 = 0;
unsigned long long Factorial(int a)
{
	if (a == 0)
	{
		s1++;
		return 1;
	}
	else
	{
		s1++;
		return a * Factorial(a - 1);
	}
}
int s2 = 0;
int Fibo(int b)
{
	if (b == 0)
	{
		s2++;
		return 0;
	}
	if (b == 1)
	{
		s2++;
		return 1;
	}
	s2++;
	return Fibo(b - 1) + Fibo(b - 2);
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int a;
	cout << "Введите число, чтобы программа могла посчитать его факториал)" << endl;
	cin >> a;
	cout << endl;
	clock_t t1 = clock();
	cout << "Факториал вашего числа (функция):" << Factorial(a) << endl;
	clock_t t2 = clock();
	cout << "Время выполнения:" << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
	cout << "Число итераций в рекурсии=" << s1 << endl;

	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	unsigned long long b = 1;
	clock_t t3 = clock();
	for (int i = 1; i <= a; i++)
	{
		b *= i;
	}
	cout << "Факториал вашего числа (цикл):" << b << endl;
	clock_t t4 = clock();
	cout << "Время выполнения: " << (double)(t4 - t3) / CLOCKS_PER_SEC << endl;

	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Введенное вами ранее число, также будет использоваться как n-ый член в числовой последовательности чисел Фибоначчи." << endl << endl;
	cout << "Числа Фибоначчи (функция):";
	clock_t t5 = clock();
	for (int i = 0; i < a; i++)
	{
		cout << Fibo(i) << " ";
	}
	clock_t t6 = clock();
	cout << endl << "Время выполнения:" << (double)(t6 - t5) / CLOCKS_PER_SEC << endl;
	cout << "Число итераций в рекурсии=" << s2 << endl;

	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Числа Фибоначчи (цикл):";
	int a1 = 0, b1 = 1, c;
	clock_t t7 = clock();
	for (int i = 0; i < a; i++)
	{
		if (i == 0)
		{
			cout << a1 << " ";
			a1++;
		}
		else if (i > 0 && i <= 2)
		{
			cout << a1 << " ";
		}
		else
		{
			c = a1 + b1;
			b1 = a1;
			a1 = c;
			cout << c << " ";
		}
	}
	clock_t t8 = clock();
	cout << endl << "Время выполнения:" << (double)(t8 - t7) / CLOCKS_PER_SEC << endl;

	cout << endl;
	a1 = 0, b1 = 1, c = 0;
	for (int i = 0; i < a; i++)
	{
		if (i == 0)
		{
			a1++;
		}
		else if (i > 0 && i <= 2)
		{
			c += i;
		}
		else
		{
			c = a1 + b1;
			b1 = a1;
			a1 = c;
		}
		if (i == c)
		{
			cout << "Fn=n:"<<"\t"<< c << endl;
		}
		if (i*i == c)
		{
			cout << "Fn=n*n:" <<"\t" << c << endl;;
		}

	}
	cout << endl;


	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	double F = (sqrt(5) + 1) / 2;
	cout << "Золотое сечение=" << F << endl;
	cout << "Приближенное значение для каждого числа Фибоначчи." << endl;
	for (int i = 0; i < a; i++)
	{
		cout << (double)(F*Fibo(i)) / (sqrt(5)) << " ";
	}
	cout << endl << endl;
	cout << "Вычисление для каждого числа Фибоначчи Fn/Fn-1." << endl;
	for (int i = 0; i < a; i++)
	{
		if (i >= 2)
		{
			cout << (double)(Fibo(i)) / (Fibo(i - 1)) << " ";
		}
	}
	cout << endl << endl;
	cout << "Для n>=15 значение приближается к золотому сечению." << endl;


	return 0;
}