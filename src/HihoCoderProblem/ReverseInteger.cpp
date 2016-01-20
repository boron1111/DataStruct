#include "ReverseInteger.h"


ReverseInteger::ReverseInteger(void)
{
}


ReverseInteger::~ReverseInteger(void)
{
}

int ReverseInteger::reverse(int x)
{
	int sum=0,Len=0;
	int temp=x,temp2,digit=1;
	long long sum1=0;
	while(temp!=0)
	{
		Len++;
		temp/=10;
		if (temp!=0)
		{
			digit*=10;
		}
		
	}


	temp=x;
	while (temp!=0)
	{
		temp2=temp%10;

		//Be aware of the large value which causes overflow of int, and negative int
		if (((long long)sum1+(long long)temp2*digit+1)/2147483648!=0)
		{
			return 0;
		}

		sum1+=(long long)temp2*digit;
		digit/=10;
		temp/=10;
	}
	return (int)sum1;
}

void ReverseInteger::TestClass()
{
	cout<<reverse(-2147483648)<<endl;
}
