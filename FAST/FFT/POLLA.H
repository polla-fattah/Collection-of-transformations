#ifndef POLLA
#define POLLA
#include <iostream.h>
#include <stdlib.h>
#include <math.h>


class Imaginary
{
	double real;
	double imag;

public:
	Imaginary()
	{
		real = 0;
		imag = 0;
	}
	Imaginary(double r, double i)
	{
		real = correct(r);
		imag = correct(i);
	}
	//Operations
	inline Imaginary operator+ (Imaginary &num)
	{
		Imaginary temp(real + num.real, imag + num.imag);
		return temp;
	}
	inline Imaginary operator *(Imaginary num)
	{
		Imaginary temp;
		temp.real = real * num.real - imag * num.imag;
		temp.imag = real * num.imag + imag * num.real;
		return temp;
	}
	
	inline Imaginary operator -()
	{
		Imaginary temp = *this;
		temp.real = -real;
		temp.imag = -imag;
		return temp;
	}
	
	inline double correct(double d)
	{
		if(d>0.000000000001 || d<-0.000000000001)
			return d;
		else
			return 0.0;
	}
	//i/o
	friend istream &operator >> (istream &in, Imaginary &num);
	friend ostream &operator <<(ostream &out, Imaginary &num);

	Imaginary pow(double n)
	{
		Imaginary temp1(1,0),temp2= *this;
		for(int i = 1; i<=n ;i++)
			temp1=temp1 * temp2;
		return temp1;
	}
	void set(double r,double i)
	{
		real = r;
		imag = i;
	}
};
ostream &operator <<(ostream &out, Imaginary &num)
{
	cout.setf(ios::showpos);
	if(num.real)
		out<<num.correct(num.real);
	if(num.imag)
		out<<num.correct(num.imag)<<'i';
	if(!num.real && !num.imag)
		out<<0;
	return out;
}
istream &operator >> (istream &in, Imaginary &num)
{
	in>>num.real>>num.imag;
	return in;
}

#endif