#include "CountPrimes.h"


CountPrimes::CountPrimes(void)
{
}


CountPrimes::~CountPrimes(void)
{
}

int CountPrimes::isPrime(int n)
{
	if (n<2)
	{
		return 0;
	}
	int i=2;
	while(i*i<=n)
	{
		if (n%i==0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int CountPrimes::countPrimes(int n)
{
	if (n<2)
	{
		return 0;
	}

	int i,j;
	int *status=new int[n+1];

	for (i=0;i<n+1;i++)
	{
		status[i]=1;
	}

	int sum=0;
	int tempPrime=2;
	for (i=2;i*i<n;i++)
	{
		if (status[i]==1)
		{
			for (j=i*i;j<n;j=j+i)
			{
				status[j]=0;
			}	
		}
	}
	for (i=2;i<n;i++)
	{
		if (status[i])
		{
			sum++;
		}
	}


	if (status!=NULL)
	{
		delete[] status;
	}
	return sum;
}

void CountPrimes::TestClass()
{
	cout<<"Num of prime is"<<endl;
	cout<<countPrimes(1500000)<<endl;
}