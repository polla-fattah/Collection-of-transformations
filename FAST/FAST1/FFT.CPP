#include <iostream.h>
struct comp
{
	double real;
	double imag;
};

//Operations
comp add(comp &num1,comp &num2)
{
	comp temp;
	temp.real=num2.real + num1.real;
	temp.imag=num2.imag + num1.imag;
	return temp;
}
comp multiply(comp num1,comp num2)
{
	comp temp;
	temp.real = num1.real * num2.real - num1.imag * num2.imag;
	temp.imag = num1.real * num2.imag + num1.imag * num2.real;
	return temp;
}
/*double correct(double d)
{
	if(d>0.000000000001 || d<-0.000000000001)
		return d;
	else
		return 0.0;
}
*/
comp pow(comp num,double n)
{
	comp temp;
	temp.real =1;
	temp.imag =0;
	for(int i = 1; i<=n ;i++)
		temp=multiply(temp , num);
	return temp;
}
/*
comp **getW(comp X[],int N)
{
	int i=0,j=0;
	double pi = 3.14159265358979;
	comp W(cos(2* pi / N), -sin(2* pi / N));
	comp **array = new comp*[N];
	for (i= 0;i<N;i++)
		array[i]=new comp[N];
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
comp *arranging(comp X[],int N)
{
	comp temp;
	for (int i =1; i<N/2 ;i++)
	{
		temp = X[i];
		X[i] = X[N-i];
		X[N-i] = temp;
	}
	return X;
}
*/
void show(comp p)
{
	cout<<p.real<<' '<<p.imag<<endl;
}
main()
{
	comp p,q;
	p.real=0;
	p.imag = 1;
	q.real=10;
	q.imag = 11;
	show(pow(q,10));
	show(q);
/*	int N,i,j;
	
	cout<<"Enter the N value : ";
	cin>>N;
	
	comp *X = new comp[N];
	comp *Y = new comp[N];
	comp **array = getW(X,N);
	for ( i = 0; i<N ; i++)
	{
	//	cout<<"Enter :";
	//	cin >>j;
	//	X[i].set(j,0);
		X[i].set(i+1,0);
	}
	for( i =0 ;i<N;i++)
	{
		for(j = 0; j<N;j++)
		{
			Y[i]=Y[i] + array[i][j]*X[j];
		}
	}
	Y = arranging(Y,N);

	for (i = 0; i < N; i++)
		cout<<Y[i]<<endl;
	cout<<endl;
	*/
	return 0;
}

