#include "PowerofTwo.h"


PowerofTwo::PowerofTwo(void)
{
}


PowerofTwo::~PowerofTwo(void)
{
}


bool PowerofTwo::isPowerOfTwo(int n)
{
	if (n<=0)
	{
		return false;//0 defined as false because 2^n>=1;
	}

	int sum=0;
	for (int i=1;i<=32;i++)
	{
		if (((n>>i)&1)==1)
		{
			sum++;
		}
	}

	if (sum==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PowerofTwo::TestClass()
{
	cout<<"is Power of 2:"<<isPowerOfTwo(7)<<endl;
}
