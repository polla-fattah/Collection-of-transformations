#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <complex>
using namespace std;

inline double hi(double num)
{
	double temp;
	if(num>0.01 || num<-0.01)
		temp = num;
	else
		temp = 0.0;
	return temp;
}


main()
{
	int N,i,j;
	const double PI = 22.0/7.0;
	double real=0,imag=0;
	cout.setf(ios::showpos);
	cout<<"Enter the N value : ";
	cin>>N;

	complex<double> W(0,-2*PI/N);
	W=exp(W);
	complex<double> *input	= new complex<double> [N];
	complex<double> *result	= new complex<double> [N];
	complex<double> **array	= new complex<double>*[N];
	for (i= 0;i<N;i++)
		array[i]=new complex<double>[N];

	for(int k=0;k<N;k++)
		for (int n =0;n<N;n++)
			array[k][n] = pow(W,(k*n) % N);

	for ( i = 0; i<N ; i++)
	{
		cout<<"Enter next x : ";
		cin>>input[i];
	}
	for( i =0 ;i<N;i++)
		for(j = 0; j<N;j++)
			result[i]=result[i] + array[i][j]*input[j];
	for (i = 0 ; i<N ;i++)
		cout<<hi(result[i].real())<<hi(result[i].imag())<<endl;

	return 0;
}
