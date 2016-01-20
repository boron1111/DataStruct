#include "Search2DMatrix.h"


Search2DMatrix::Search2DMatrix(void)
{
}


Search2DMatrix::~Search2DMatrix(void)
{
}

bool Search2DMatrix::searchMatrix(vector<vector<int>>& matrix, int target)
{
	int i,j;
	int Nrows,Ncols;
	Nrows=matrix.size();
	Ncols=(matrix[0]).size();
	
	int start=0,end=0;

	i=0;j=Ncols-1;
	while(i>=0&&j>=0&&i<Nrows&&j<Ncols)
	{
		if (matrix[i][j]==target)
		{
			return true;
		}
		else if (matrix[i][j]<target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return false;
}
void Search2DMatrix::TestClass()
{
	int array2D[25]={1,4,7,11,15,
			2,5,8,12,19,
			3,6,9,16,22,
			10, 13, 14, 17, 24,
			18, 21, 23, 26, 30};

	int Nrows=5,Ncols=5;
	vector <vector <int>>   matrix(Nrows); 
	for(int i=0;i <Nrows;i++) 
		matrix[i].resize(Ncols);//设置数组的大小3X3  
	for(int i=0;i <Nrows;i++) 
	{
		for(int j=0;j <Ncols;j++) 
		{
				matrix[i][j]=array2D[i*Nrows+j]; 
				cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	int target=20;
	bool res=searchMatrix(matrix,target);
	cout<<"Result is="<<res<<endl;
}