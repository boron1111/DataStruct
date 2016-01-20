#include "UglyNumber.h"


UglyNumber::UglyNumber(void)
{
}


UglyNumber::~UglyNumber(void)
{
}

bool UglyNumber::isUgly(int num)
{
	if (num<=0)
	{
		return false;
	}

	int Prime[3]={2,3,5};
	int i;
	int temp=num;

	for (i=0;i<3;i++)
	{
		while(temp%Prime[i]==0)
		{
			temp/=Prime[i];
		}
		if (temp==1)
		{
			return true;
		}
	}
	if (temp==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UglyNumber::TestClass()
{
	cout<<"Ugly number is="<<isUgly(1)<<endl;
}