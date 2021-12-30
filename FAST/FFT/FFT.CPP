#include "polla.h"

Imaginary **getW(Imaginary X[],int N)
{
	int i=0,j=0;
	double pi = 3.14159265358979;
	Imaginary W(cos(2* pi / N), -sin(2* pi / N));
	Imaginary **array = new Imaginary*[N];
	for (i= 0;i<N;i++)
		array[i]=new Imaginary[N];
	//calculate W matrix
	for (i= 0;i<N/2;i++)
	{
		X[i] = W.pow(i);
		X[i + N/2] = -X[i];
	}
	for(i=0;i<N;i++)
		for (j =i;j<N;j++)
			array[j][i] = array[i][j] = X[(i*j)%N];
	return array;
}

Imaginary *arranging(Imaginary X[],int N)
{
	Imaginary temp;
	for (int i =1; i<N/2 ;i++)
	{
		temp = X[i];
		X[i] = X[N-i];
		X[N-i] = temp;
	}
	return X;
}
main()
{
	int N,i,j;
	
	cout<<"Enter the N value : ";
	cin>>N;
	
	Imaginary *X = new Imaginary[N];
	Imaginary *Y = new Imaginary[N];
	Imaginary **array = getW(X,N);
	for ( i = 0; i<N ; i++)
	{
		cout<<"Enter :";
		cin >>j;
		X[i].set(j,0);
	//	X[i].set(i+1,0);
	}
	for( i =0 ;i<N;i++)
	{
		for(j = 0; j<N;j++)
		{
			Y[i]=Y[i] + array[i][j]*X[j];
		}
	}
//	Y = arranging(Y,N);

	for (i = 0; i < N; i++)
		cout<<Y[i]<<endl;
	cout<<endl;
	return 0;
}

