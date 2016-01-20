#include "NumberOfIslands.h"


NumberOfIslands::NumberOfIslands(void)
{
}


NumberOfIslands::~NumberOfIslands(void)
{
}

int NumberOfIslands::numIslands(vector<vector<char>>& grid)
{
	int i,j;
	int m,n;
	if (grid.empty())
	{
		return 0;
	}
	m=grid.size();
	n=grid[0].size();
	



	int Label=1;
	if (grid[0][0]>'0')
	{
		grid[0][0]=Label+1+'0';
		Label++;
	}

	for (j=1;j<n;j++)
	{
		if (grid[0][j]=='0')
		{
			continue;
		}
		if (grid[0][j-1]>'1')
		{
			grid[0][j]=grid[0][j-1];
		}
		else
		{
			grid[0][j]=Label+1+'0';
			Label++;
		}
	}


	for (i=1;i<m;i++)
	{
		if (grid[i][0]>'0')
		{		
			if (grid[i-1][0]>'1')
			{
				grid[i][0]=grid[i-1][0];
			}
			else
			{
				grid[i][0]=Label+1+'0';
				Label++;
			}
		}

		

		for (j=1;j<n;j++)
		{
			if (grid[i][j]=='0')
			{
				continue;
			}
			if (grid[i-1][j]>'1'&&grid[i][j-1]>'1')
			{
				grid[i][j]=grid[i-1][j]<grid[i][j-1] ?grid[i-1][j]:grid[i][j-1];
			}
			else if (grid[i-1][j]>'1'&&grid[i][j-1]=='0')
			{
				grid[i][j]=grid[i-1][j];
			}
			else if (grid[i-1][j]<'1'&&grid[i][j-1]>'1')
			{
				grid[i][j]=grid[i][j-1];
			}
			else
			{
				grid[i][j]=Label+1+'0';
				Label++;
			}
		}
	}

	//for (i=0;i<m;i++)
	//{
	//	for (j=0;j<n;j++)
	//	{
	//		cout<<grid[i][j]-'0'<<" ";
	//	}
	//	cout<<endl;
	//}

	//cout<<"====================="<<endl;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			char minN=grid[i][j];
			if (i-1>=0&&i-1<m)
			{
				if (grid[i-1][j]>'0')
				{
					minN=minN<grid[i-1][j]?minN:grid[i-1][j];
				}
			}

			if (i+1>=0&&i+1<m)
			{
				if (grid[i+1][j]>'0')
				{
					minN=minN<grid[i+1][j]?minN:grid[i+1][j];
				}
			}

			if (j-1>=0&&j-1<n)
			{
				if (grid[i][j-1]>'0')
				{
					minN=minN<grid[i][j-1]?minN:grid[i][j-1];
				}
			}

			if (j-1>=0&&j+1<n)
			{
				if (grid[i][j-1]>'0')
				{
					minN=minN<grid[i][j-1]?minN:grid[i][j-1];
				}
			}

			grid[i][j]=minN;
		}
	}

	int maxv=0;
	int *labels=new int[Label+1];
	for (i=0;i<=Label;i++)
	{
		labels[i]=0;
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			//cout<<grid[i][j]-'0'<<" ";
			labels[grid[i][j]-'0']=1;
		}
		//cout<<endl;
	}

	int NumberofIsland=0;
	for (i=0;i<=Label;i++)
	{
		if (labels[i]>0)
		{
			NumberofIsland++;
		}
	}
	return NumberofIsland;
}

void NumberOfIslands::TestClass()
{
	//int array[][5]={1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1};
	int array[][5]={1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1};
	vector<vector<char>> grid(4);
	for(int i=0;i <4;i++) 
		grid[i].resize(5);//设置数组的大小3X3 

	for(int i=0;i <4;i++) 
	{	
		for(int j=0;j <5;j++) 
		{	
			grid[i][j]=array[i][j]-0+'0'; 
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<numIslands(grid)<<endl;
}