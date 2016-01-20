#include "PerfectSquares.h"


PerfectSquares::PerfectSquares(void)
{
}


PerfectSquares::~PerfectSquares(void)
{
}

int PerfectSquares::numSquares(int n)
{
	int status;
	int i,j;

	if (n<=0)
	{
		return 0;
	}

	status=isSquare(n);
	if (status==1)
	{
		return 1;
	}

	int root=sqrt((double)n);

	/*int MinNum=n;
	int CurrentNum;
	for (i=1;i<=root;i++)
	{
		CurrentNum=1+numSquares(n-i*i);
		if (MinNum>CurrentNum)
		{
			MinNum=CurrentNum;
		}
	}*/
	int *dp=new int[n+1];
	dp[1]=1;
	int MinNum=n;
	for (i=2;i<=n;i++)
	{
		j=1;
		MinNum=n;
		while(j*j<=i)
		{
			if (j*j==i)
			{
				MinNum=1;
				break;
			}
			else
			{
				MinNum=(dp[i-j*j]+1)<MinNum? dp[i-j*j]+1:MinNum;
				j++;
			}
		}
		dp[i]=MinNum;
	}
	return dp[n];

}

int PerfectSquares::isSquare(int n)
{
	int temp=sqrt((double)n);
	if (temp*temp==n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void PerfectSquares::TestClass()
{
	int squareNum;
	squareNum=numSquares(13);
	cout<<"Num of Squares="<<squareNum<<endl;
}