#include <iostream.h>
#include <math.h>
#include <stdlib.h>

bool firstCheck(double coef[],int n)
{
	int i=0;
	double sum = 0;
	for (i =0; i<n+1 ;i++)
		sum += coef[i];
	if (sum <=0)
		return false;
	sum =0;
 
	for (i=0 ;i<n+1;i++)
		sum+=coef[i] * pow(-1.0,i);
	sum *=pow(-1,n);
	if(sum <=0)
		return false;
	return true;
}
bool secondCheck(double **coef,int n)
{
	for (int row =0;row< n-1;row++)
	{
		for(int col =0;col < n- row ;col++)
		{
			coef[row + 1][n-row-col-1] = coef[row][n-row]*coef[row][n-row-col] - coef[row][0]*coef[row][col];
		//	cout<<coef[row + 1][n-row-col-1]<<"\t";
		}
	//	cout<<endl;
	}
	for (int i = 1; i<n;i++)
		if(coef[i][n-i]<0)
		{
		//	cout<<"Help me\n";
			return false;
		}
	return true;
}

main()
{
	int n=3,i;
	cout<<"n = ";
	cin>>n;
	double **coef = new double*[n];
	for (i =0;i<n;i++)
		coef[i] = new double[n + 1 - i];
/*	
	coef[0][0] = -0.083333333;
	coef[0][1] = -0.25;
	coef[0][2] = 0.333333333;
	coef[0][3] = 1;
*/
	cout <<"Enter the equation coeftiants : ";
	
	for(i =0 ; i<n+1;i++)
		cin>>coef[0][n-i];
	for(i =0 ; i<n+1;i++)
		coef[0][i] /=coef[0][n];
	if(firstCheck(coef[0],n) && secondCheck(coef,n))
		cout<<"It is stable equation.\n";
	else
		cout<<"It is NOT stable equation.\n";
	return 0;
}