#define _USE_MATH_DEFINES
#include <locale>
#include <iostream>
#include <math.h>
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	double x; // значение аргумента
	double func; // точное значение функции
	double sum; // частичная сумма
	int n; // число слагамых в частичной сумме

	cout << "задание 1" << endl;
	cout << "введите значение аргумента ";
	cin >> x;
	cout << "введите кол-во слагаемых ";
	cin >> n;
	func = 1 / ((1 + x) * (1 + x));// Вычисление точного значения
	double lastx;
	sum = sumN(x, n, lastx);
	cout << "точное значение функции = " << func << endl;
	cout << "частичная сумма ряда =" << sum << endl;
	cout << "абсолютная погрешность = " << fabs(func - sum) << endl;
	cout << "последнее слагаемое = " << lastx << endl;
	if (fabs(func - sum) > lastx) cout << "абсолютная погрешность больше последнего слагаемого ";
	if (fabs(func - sum) < lastx) cout << " абсолютная погрешность меньше посл. слаг.";
	if (fabs(func - sum) == lastx) cout << " абсолютная погрешность равно последнему слаг.";
	cout << "\nзадание 2" << endl;
	double E;
	cout << "введите значение аргумента  ";
	cin >> x;
	cout << "задайте точность вычислений  ";
	cin >> E;
	func = 1 / ((1 + x) * (1 + x));
	sum = sumE(x, E, n);
	cout << "точное значение функции =" << func << endl;
	cout << "частичная сумма ряда c заданной точностью =" << sum << endl;
	sum = sumE(x, E / 10, n);
	cout << "частичная сумма ряда c точностью, большей в 10 раз, =" << sum << endl;
	system("pause");
	return 0;
}

double sumN(double x, int n, double& lastx)
{
	lastx = x;
	double sum = lastx;
	for (int i = 1; i < n; ++i)
	{
		double r; // отношение i слагаемлого к (i - 1)
		r = -x * x / (2 * i) / (2 * i + 1); // значение r
		lastx *= r;
		sum += lastx;
	}
	return sum;
}

double sumE(double x, double E, int& n)
{
	double lastx;

	lastx = x;
	double sum = lastx;
	for (n = 1; fabs(lastx) > E; ++n)
	{
		double r;
		r = -x * x / (2 * n) / (2 * n + 1); ;
		lastx *= r;
		sum += lastx;
	}
	return sum;
}
