#include "PowOperation.h"


PowOperation::PowOperation(void)
{
}


PowOperation::~PowOperation(void)
{
}


double PowOperation::myPow(double x, int n)
{
	
	double pow1=1;
	int isNegative=0;
	if (n<0)
	{
		isNegative=1;
		n=abs(n);
	}

	int temp=n;
	if(n==1)
	{
		if (isNegative)
		{
			return (double)1.0/x;
		}
		else
		{
			return x;
		}			
	}
	else
	{
		while (temp>0)
		{
			if (temp%2==1)
			{
				pow1*=x;
			}
			x*=x;
			temp/=2;
		}

		if (isNegative)
		{
			return (double)1/pow1;
		}
		else
		{
			return pow1;
		}	
	}
}

void PowOperation::TestClass()
{
	cout<<"pow is="<<myPow(2,-2)<<endl;
}