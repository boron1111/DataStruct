#include "HappyNumber.h"


HappyNumber::HappyNumber(void)
{
}


HappyNumber::~HappyNumber(void)
{
}

bool HappyNumber::isHappy(int n)
{
	int temp=n,temp1;
	int sum=0;

	int *Array=new int[10000];
	int k=0;
	Array[k]=n;
	while(temp>0)
	{
		temp1=temp%10;
		sum+=temp1*temp1;
		temp/=10;
		if (temp==0)
		{
			if (sum==1)
			{
				return true;
			}
			else
			{
				temp=sum;
				sum=0;
			}

			if (temp==n)
			{
				return false;
			}

			k++;
			Array[k]=temp;
			for (int j=0;j<k;j++)
			{
				if (Array[j]==Array[k])
				{
					return false;
				}
			}
		}
	}
	return false;
}

void HappyNumber::TestClass()
{
	cout<<"is happy="<<isHappy(20)<<endl;
}