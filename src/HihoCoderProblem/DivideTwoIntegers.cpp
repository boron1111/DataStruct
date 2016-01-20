#include "DivideTwoIntegers.h"


DivideTwoIntegers::DivideTwoIntegers(void)
{
}


DivideTwoIntegers::~DivideTwoIntegers(void)
{
}

int DivideTwoIntegers::divide(int dividend, int divisor)
{
	if ((dividend>INT_MAX) || (dividend<INT_MIN))
	{
		return INT_MAX;
	}
	
	int flag1=0,flag2=0;//flag to test limits
	if (dividend==INT_MIN)
	{
		flag1=1;
	}
	if (divisor==INT_MIN&&dividend==INT_MIN)
	{
		return 1;
	}
	else if (divisor==INT_MIN&&dividend!=INT_MIN)
	{
		return 0;
	}

	int temp1=dividend<0? 0-dividend:dividend;
	if (dividend==INT_MIN)
	{
		temp1=~dividend;
	}

	int temp2=divisor<0? 0-divisor:divisor;
	int sign1,sign2,temp3;
	sign1=dividend<0? -1:1;
	sign2=divisor<0? -1:1;

	//cout<<temp1<<","<<temp2<<endl;


	int MaxBit=1;
	temp3=temp2;
	while ((temp3<<1) <temp1&&MaxBit<(INT_MAX>>1)&&temp3<(INT_MAX>>1))
	{
		MaxBit+=MaxBit;
		temp3=temp3<<1;
		//cout<<MaxBit<<endl;
	}
	//cout<<MaxBit<<","<<temp3<<endl;
	int quotient=0;
	int temp4=temp1,tempBit=MaxBit;
	while (temp4 >0&&temp3>0)
	{
		if (temp4>=temp3)
		{
			quotient+=tempBit;
			temp4-=temp3;
			if (temp4<10)
			{
				temp4+=flag1;
				flag1=0;
			}
		}
		else
		{
			temp3=temp3>>1;
			tempBit=tempBit>>1;
		}
		//cout<<temp4<<","<<temp3<<endl;
	}

	//Special case,Max/min,min/max, answer is max, answer is min,negative sign
	int sign=sign1==sign2? 1:-1;
	if (quotient==INT_MIN&&sign>0)
	{
		return INT_MAX;
	}
	else if (quotient==INT_MIN && sign<0)
	{
		return INT_MIN;
	}
	if (sign==1)
	{
		return quotient;
	}
	else
	{
		return 0-quotient;
	}
	
}
void DivideTwoIntegers::TestClass()
{
	cout<<divide(-2147483648,2)<<endl;
}
