#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "На графике можно увидеть следующие функции:" << endl <<
		"1) y=(x - 3)*(x*x - 6 * x + 6) ( Данный график обозначен красным цветом )" << endl <<
		"2) y= x*x*(x - 4) * (x - 4) ( Данный график обозначен синим цветом )" << endl;

	float i, min = 0.1, saver;
	vector <double> v1;
	int number = 0;
	int counter = 0;
	for (i = -50; i < 50; i += 0.01052)
	{
		float k = i * i*i*i - 7 * i*i*i + 7 * i*i + 24 * i - 18;
		if (abs(k) < min)
		{
			if (number == 0)
			{
				v1.push_back(k);
				number++;
				cout << number << " ) Примерная точка пересечения графиков: (" << i
					<< ";" << cbrt(i * i*(i - 4) * (i - 4)) << " )" << endl;
			}
			else
			{
				if (abs(v1[counter] - k) > 0.03)
				{
					v1.push_back(k);
					number++;
					counter++;
					cout << number << " ) Примерная точка пересечения графиков: (" << i
						<< ";" << cbrt(i * i*(i - 4) * (i - 4)) << " )" << endl;
				}
			}
		}
	}

	cout << "Всего точек пересечения:" << number << endl;
	system("pause");
	return 0;
}