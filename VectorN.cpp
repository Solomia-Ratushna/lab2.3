//VectorN.cpp
#include "VectorN.h"

void VectorN::SetN(int value)
{
	if (value > 0)
	{
		N = value;
	}
	else
	{
		N = 0;
	}
}
VectorN::VectorN()
	:N(1)
{
	a = new double[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = 0;
	}
}

VectorN::VectorN(double* a, int N)
{
	this->N = (N >= 1) ? N : 1;
	this->a = new double[N];
	for (int i = 0; i < N; i++)
	{
		this->a[i] = a[i];
	}
	delete[] a;
}

VectorN::VectorN(int N)
{
	this->N = (N >= 1) ? N : 1;
	this->a = new double[N];
	for (int i = 0; i < N; i++)
	{
		this->a[i] = 0;
	}
}


VectorN::VectorN(const VectorN& b)
	:N(b.N)
{
	a = new double[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = b.a[i];
	}
	delete[] b.a;

}
VectorN::operator string() const
{
	stringstream SS;
	for (int i = 0; i < N; i++)
	{
		SS << a[i] << " ";
	}

	return SS.str();
}

VectorN& VectorN::operator =(const VectorN& b)
{
	N = b.N;
	delete[] a;
	a = new double[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = b.a[i];
	}

	return *this;
}

VectorN& VectorN::operator ++()
{
	VectorN b = *this;
	a = new double[N + 1];
	for (int i = 0; i < N; i++)
	{
		a[i + 1] = b.a[i];
	}
	a[0] = 0;
	N++;
	delete[] b.a;
	b.a = a;

	return *this;
}
VectorN& VectorN::operator --()
{
	VectorN b = *this;
	N--;
	a = new double[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = b.a[i + 1];
	}
	delete[] a;
	b.a = a;

	return *this;
}
VectorN VectorN::operator ++(int)
{
	VectorN b = *this;
	a = new double[N + 1];
	for (int i = 0; i < N; i++)
	{
		a[i] = b.a[i];
	}
	a[N] = 0;
	N++;
	delete[] b.a;
	b.a = a;
	return *this;
}
VectorN VectorN::operator --(int)
{
	VectorN b = *this;
	N--;
	a = new double[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = b.a[i];
	}
	delete[] b.a;
	b.a = a;
	return *this;
}
ostream& operator <<(ostream& out, const VectorN& a)
{
	out << "( " << string(a) << ")" << endl;
	return out;
}
istream& operator >>(istream& in, VectorN& b)
{
	for (int i = 0; i < b.N; i++)
	{
		cout << "[" << i + 1 << "]" << ": ";
		in >> b.a[i];
	}
	return in;
}

VectorN VectorN::operator +(const VectorN& r)
{
	VectorN res(r.N);
	for (int i = 0; i < r.GetN(); i++)
	{
		res.a[i] = this->a[i] + r.a[i];
	}

	return res;
}
VectorN VectorN::operator -(const VectorN& r)
{
	VectorN res(r.N);
	for (int i = 0; i < r.GetN(); i++)
	{
		res.a[i] = this->a[i] - r.a[i];
	}
	return res;
}
double operator *(const VectorN l, const VectorN r)
{
	double scal = 0;

	for (int i = 0; i < r.N; i++)
	{
		scal += (l.a[i] * r.a[i]);
	}

	return scal;
}


