#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream inf("Vvod.txt");
	double x1, x2, x3, x0, y1, y2, y3, y0;
	inf >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0;
	if (!inf)
	{
		cout << "Данный файл нельзя считать!" << endl;
		return 0;
	}
	cout << "x1=" << x1 << "\t" << "y1=" << y1 << endl << "x2=" << x2 <<"\t"<< "y2=" << y2 << endl << "x3="<< x3 << "\t" <<"y2=" << y3 << endl << "x0=" << x0 << "\t"<< "y0=" << y0 << endl;
	cout << "Где x0 и y0 координаты точки." << endl<<endl;
	double a = (x1 - x0)*(y2 - y1) - (x2 - x1)*(y1 - y0);
	double b = (x2 - x0)*(y3 - y2) - (x3 - x2)*(y2 - y0);
	double c = (x3 - x0)*(y1 - y3) - (x1 - x3)*(y3 - y0);
	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	{
		cout << "Точка находится внутри треугольника.";
	}
	else if (a == 0 || b == 0 || c == 0)
	{
		cout << "Точка находится на стороне треугольника." << endl;
	}
	else
	{
		cout << "Точка находится снаружи треугольника." << endl;
	}

	double s1, s2, s3;
	s1 = 0.5*abs((x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0));
	s2 = 0.5*abs((x1 - x0)*(y3 - y0) - (x3 - x0)*(y1 - y0));
	s3 = 0.5*abs((x2 - x0)*(y3 - y0) - (x3 - x0)*(y2 - y0));
	cout <<endl<< endl;
	double AB, AC, BC, A, B, C, H, xh, yh;
	if (s1 > s2 && s1 > s3)
	{
		cout << "Площадь наибольшего треугольника=" << s1 << endl;
		AB = pow(pow((x1 - x0), 2) + pow((y1 - y0), 2), 0.5);
		AC = pow(pow((x2 - x0), 2) + pow((y2 - y0), 2), 0.5);
		BC = pow(pow((x1 - x2), 2) + pow((y1 - y2), 2), 0.5);

		A = y1 - y2;
		B = x2 - x1;
		C = x1 * y2 - x2 * y1;

		H = fabs(A*x0 + B * y0 + C) / (sqrt(A*A + B * B));
		xh = x2 + (x1 - x2)*((x0 - x2)*(x1 - x2) + (y0 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		yh = y2 + (y1 - y2)*((x0 - x2)*(x1 - x2) + (y0 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	}
	else if (s2 > s1&&s2 > s3)
	{
		cout << "Площадь наибольшего треугольника=" << s2 << endl;
		AB = pow(pow((x1 - x0), 2) + pow((y1 - y0), 2), 0.5);
		AC = pow(pow((x3 - x0), 2) + pow((y3 - y0), 2), 0.5);
		BC = pow(pow((x1 - x3), 2) + pow((y1 - y3), 2), 0.5);

		A = y3 - y1;
		B = x1 - x3;
		C = x3 * y1 - x1 * y3;

		H = fabs(A*x0 + B * y0 + C) / (sqrt(A*A + B * B));
		xh = x3 + (x1 - x3)*((x0 - x3)*(x1 - x3) + (y0 - y3)*(y1 - y3)) / ((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
		yh = y3 + (y1 - y1)*((x0 - x3)*(x1 - x3) + (y0 - y3)*(y1 - y3)) / ((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
	}
	else if (s3 > s1&&s3 > s2)
	{
		cout << "Площадь наибольшего треугольника=" << s3 << endl;
		AB = pow(pow((x2 - x0), 2) + pow((y2 - y0), 2), 0.5);
		AC = pow(pow((x3 - x0), 2) + pow((y3 - y0), 2), 0.5);
		BC = pow(pow((x2 - x3), 2) + pow((y2 - y3), 2), 0.5);

		A = y3 - y2;
		B = x2 - x3;
		C = y2 * x3 + x2 * y3;

		H = fabs(A*x0 + B * y0 + C) / (sqrt(A*A + B * B));
		xh = x3 + (x2 - x3)*((x0 - x3)*(x2 - x3) + (y0 - y3)*(y2 - y3)) / ((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
		yh = y3 + (y2 - y3)*((x0 - x3)*(x2 - x3) + (y0 - y3)*(y2 - y3)) / ((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
	}
	double max = AB;
	if (AC > max)   max = AC;
	if (BC > max)	max = BC;

	double min = AB;
	if (AC < min)   min = AC;
	if (BC < min)	min = BC;
	double srd = AB + AC + BC - max - min;

	double d = min * min + srd * srd;
	double e = max * max;
	if (d > e)
	{
		cout << "Заданный треугольник остроугольный." << endl;
	}
	else if (d < e)
	{
		cout << "Заданный треугольник тупоугольный." << endl;
	}
	else
	{
		cout << "Заданный треугольник прямоугольный." << endl;
	}
	cout << endl << "Высота треугольника=" << H << endl;
	cout << "Координаты высоты (x,y): (" << xh << "," << yh << ")" << endl;
	return 0;
}