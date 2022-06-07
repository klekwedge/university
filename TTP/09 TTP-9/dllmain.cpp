#include "pch.h"
#include <cmath>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

extern "C" __declspec(dllexport)
double myf_math(double a, double x)
{
	return log(x);
}

extern "C" __declspec(dllexport)
double Antonov_ln(double a, double eps, double x)
{
	double lnx = 0;
	int n = 1;
	double fnThis = (x - 1);
	double fnNext, k;
	lnx += fnThis;
	while (fabs(fnThis) > eps)
	{
		k = (x - 1) * n / (n + 1) * (-1);
		fnNext = fnThis * k;
		fnThis = fnNext;
		lnx += fnThis;
		n++;
	}
	return lnx;
}

extern "C" __declspec(dllexport)
double myf_3532703_00001(double a, double eps, double x)
{
	return Antonov_ln(a, eps, x);
}


extern "C" __declspec(dllexport) const char* FName()
{
	return "ln(x)";
}