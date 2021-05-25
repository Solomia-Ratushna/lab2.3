//Source.cpp
#include "VectorN.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "N =? "; cin >> N;
	VectorN n(N);
	cin >> n;
	cout << n << endl << endl;

	int N2;
	cout << "N =? "; cin >> N2;
	VectorN m(N2);
	cin >> m;
	cout << m << endl << endl;

	VectorN c = n + m;
	cout << "n + m = " << c << endl;
	VectorN d = n - m;
	cout << "n - m = " << d << endl;
	double e = n * m;
	cout << "a * b = " << e << endl;

	cout << m << endl;
	cout << ++m << endl;
	cout << m << endl;
	cout << m-- << endl;

	return 0;
}
