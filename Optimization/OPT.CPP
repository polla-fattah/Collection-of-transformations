#include <iostream.h>
#include "H1.h"
int COL_SIZE,ROW_SIZE;
int findMinColumn(double z[])
{
	int minLocation =0;
	double min = z[minLocation];
	for (int i=0; i < COL_SIZE ;i++)
		if (z[i] < z[minLocation])
			minLocation =i;
	if(z[minLocation] < 0)
		return minLocation;
	else
		return -1;
}

int findMinRow(double **matrix, int minCol)
{
	int minLoc = 1;
	double min = matrix[1][COL_SIZE - 1]/matrix[1][minCol];
	for (int i=2;i<ROW_SIZE;i++)
	{
		if(matrix[i][minCol] !=0)
			if(min >matrix[i][COL_SIZE - 1]/matrix[i][minCol])
			{
				min = matrix[i][COL_SIZE - 1]/matrix[i][minCol];
				minLoc = i;
			}
	}
	return minLoc;
}
void divide (double selected[],double value)
{
	for (int i=0;i<COL_SIZE;i++)
		selected[i]/=value;
}
void myShow(double **s)
{
	for (int i=0;i<ROW_SIZE;i++)
	{
		for (int j=0;j<COL_SIZE;j++)
			cout<<s[i][j]<<'\t';
		cout<<endl;
	}
}
void zero(double **matrix, int minRow, int minCol)
{
	double holder ; 
	for (int i =0 ;i < ROW_SIZE; i++)
	{
		holder = matrix[i][minCol];
		if (i != minRow && matrix[i][minCol] !=0 )
			for (int j = 0; j<COL_SIZE ;j++)
				matrix[i][j] = matrix[i][j] - matrix[minRow][j] * holder;
	}
}

void show(int index[],double **sol,int size)
{
	for (int i=0;i<size;i++)
	{
		cout<<index[i]<<"\n";
		cout<<"X"<<i<<" = "<<sol[index[i]][COL_SIZE-1]<<endl;
	}
}
main()
{
	int n,m,minCol,minRow,i;
	double **matrix;

	cout<<"Enter n value : ";
	cin>>n;
	cout<<"Enter m value : ";
	cin>>m;
	COL_SIZE = m+n+1;
	ROW_SIZE =  m+1;
	int *index = new int[m];

	matrix = new double*[COL_SIZE];
	for (i = 0 ;i <m+1;i++)
		matrix[i] = new double[COL_SIZE];

	get(matrix);	
//	for (i=0;i<ROW_SIZE;i++)
//		for (j=0;j<COL_SIZE;j++)
//			in>>matrix[i][j];


	while((minCol = findMinColumn(matrix[0]))!=-1)
	{
		minRow = findMinRow(matrix,minCol);
		divide(matrix[minRow],matrix[minRow][minCol]);
		zero(matrix,minRow,minCol);
		index[minCol]=minRow;
	}
	if(minCol <m)
		index[minCol] = minRow;
	show(index,matrix,n);
	return 0;
}

