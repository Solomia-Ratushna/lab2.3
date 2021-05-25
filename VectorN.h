//Vector.h
#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class VectorN
{
private:

	int N;
	double* a;

public:

	int GetN() const { return N; }
	void SetN(int value);

	VectorN();
	VectorN(double* a, int N);
	VectorN(int N);
	VectorN(const VectorN&);
	const double& operator [] (const int i) const { return a[i]; }
	double& operator [] (const int i) { return a[i]; }

	operator string() const;
	VectorN& operator =(const VectorN&);

	VectorN& operator ++();
	VectorN& operator --();
	VectorN operator ++(int);
	VectorN operator --(int);
	friend ostream& operator <<(ostream&, const VectorN&);
	friend istream& operator >>(istream&, VectorN&);

	VectorN operator +(const VectorN& r);
	VectorN operator -(const VectorN& r);

	friend double operator *(const VectorN l, const VectorN r);
};





